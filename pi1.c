#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include<errno.h>
int main(int argc, char *argv[])
{
	pid_t pid1, pid2, pid3, pid4, pid5, pid6, pid7, pid8, pid9;
	int status1, status2, status3, status4, status5, status6, status7, status8, status9;
	int fd[2];
	char buffer[30];
	pipe(fd);
	
	if ((pid1=fork()) == 0 ){      
		
		if((pid5=fork()) == 0){
			printf("Escribiendo en Pipe H\n");
			buffer[0] = 'H';
			write(fd[1], buffer, 2);
		}
		else {
			waitpid(pid5,&status5,0);
			if((pid6=fork()) == 0){ 
				read(fd[0], buffer, 2);
				printf("Leido %s\n", buffer);
				printf("Escribiendo en Pipe O\n");
				buffer[1] = 'O';
				write(fd[1], buffer, 3);
			}
			else{
				waitpid(pid6,&status6,0);
				read(fd[0], buffer, 3);
				printf("Leido %s\n", buffer);
				printf("Escribiendo en Pipe L\n");
				buffer[2] = 'L';
				write(fd[1], buffer, 4);
			}
		}
	}
	else{ 
		waitpid(pid1,&status1,0);
		if((pid2=fork()) == 0 ){ 
			if((pid7=fork()) == 0){ 
				read(fd[0], buffer, 4);
				printf("Leido %s\n", buffer);
				printf("Escribiendo en Pipe A\n");
				buffer[3] = 'A';
				write(fd[1], buffer, 5);
			}
			else {
				waitpid(pid7,&status7,0);
				read(fd[0], buffer, 5);
				printf("Leido %s\n", buffer);
				printf("Escribiendo en Pipe M\n");
				buffer[4] = 'M';
				write(fd[1], buffer, 6);
			}
		}
		else{ 
			waitpid(pid2,&status2,0);
			if((pid3=fork()) == 0){
				read(fd[0], buffer, 6);
				printf("Leido %s\n", buffer);
				printf("Escribiendo en Pipe U\n");
				buffer[5] = 'U';
				write(fd[1], buffer, 7);
			}
			else{ 
				waitpid(pid3, &status3, 0);
				if((pid4=fork()) == 0){
					if((pid8=fork()) == 0){
						read(fd[0], buffer, 7);
						printf("Leido %s\n", buffer);
						printf("Escribiendo en Pipe N\n");
						buffer[6] = 'N';
						write(fd[1], buffer, 8);
					}
					
					else {
						waitpid(pid8,&status8,0);
						if((pid9=fork()) == 0){ 
							read(fd[0], buffer, 8);
							printf("Leido %s\n", buffer);
							printf("Escribiendo en Pipe D\n");
							buffer[7] = 'D';
							write(fd[1], buffer, 9);
						}
						
						else{
							waitpid(pid9,&status9,0);
							read(fd[0], buffer, 9);
							printf("Leido %s\n", buffer);
							printf("Escribiendo en Pipe O\n");
							buffer[8] = 'O';
							write(fd[1], buffer, 10);
						}
					}
				}
				else {
					waitpid(pid1, &status1, 0);
					waitpid(pid2, &status2, 0);
					waitpid(pid3, &status3, 0);
					waitpid(pid4, &status4, 0);
					read(fd[0], buffer, 10);
					printf("Leido %s\n", buffer);
				}
			}
		}
	}
	
	return 0;
}
