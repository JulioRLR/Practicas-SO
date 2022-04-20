#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include<errno.h>
int main(int argc, char *argv[])
{
	pid_t pid1, pid2, pid3, pid4, pid5, pid6, pid7, pid8, pid9, pid10;
	int status1, status2, status3, status4, status5, status6, status7, status8, status9, status10;
	int fd[2];
	char buffer[30];
	pipe(fd);
	if ((pid1=fork()) == 0 ){    
		if((pid5=fork()) == 0){
			if((pid3=fork()) == 0){
				printf("Escribiendo en Pipe O\n");
				buffer[0] = 'O';
				write(fd[1], buffer, 2);
			}
			else {
				waitpid(pid3,&status3,0);
				read(fd[0], buffer, 2);
				printf("Leido %s\n", buffer);
				printf("Escribiendo en Pipe T\n");
				buffer[1] = 'T';
				write(fd[1], buffer, 3);
			}
		}
		else {
			waitpid(pid5,&status5,0);
			if((pid6=fork()) == 0){ 
				read(fd[0], buffer, 3);
				printf("Leido %s\n", buffer);
				printf("Escribiendo en Pipe O\n");
				buffer[2] = 'O';
				write(fd[1], buffer, 4);
			}
			else{
				waitpid(pid6,&status6,0);
				read(fd[0], buffer, 4);
				printf("Leido %s\n", buffer);
				printf("Escribiendo en Pipe Ñ\n");
				buffer[3] = 'N';
				write(fd[1], buffer, 5);
			}
		}
	}
	else{ 
		waitpid(pid1,&status1,0);
		if((pid2=fork()) == 0 ){ 
			if((pid7=fork()) == 0){				
				read(fd[0], buffer, 5);
				printf("Leido %s\n", buffer);				
				printf("Escribiendo en Pipe O\n");
				buffer[4] = 'O';
				write(fd[1], buffer, 6);
			}
			else {
				waitpid(pid7,&status7,0);
				read(fd[0], buffer, 6);
				printf("Leido %s\n", buffer);				
				printf("Escribiendo en Pipe 2\n");
				buffer[5] = '2';
				write(fd[1], buffer, 7);
			}
		}
		else{ 
			waitpid(pid2,&status2,0);
			if((pid4=fork()) == 0){
				if((pid8=fork()) == 0){
					
					read(fd[0], buffer, 7);
					printf("Leido %s\n", buffer);
					
					printf("Escribiendo en Pipe 0\n");
					buffer[6] = '0';
					write(fd[1], buffer, 8);
				}
				else {
					waitpid(pid8,&status8,0);
					if((pid9=fork()) == 0){ 
						
						read(fd[0], buffer, 8);
						printf("Leido %s\n", buffer);
						printf("Escribiendo en Pipe 1\n");
						buffer[7] = '1';
						write(fd[1], buffer, 9);
					}
					else{
						waitpid(pid9,&status9,0);
						read(fd[0], buffer, 9);
						printf("Leido %s\n", buffer);
						printf("Escribiendo en Pipe 9\n");
						buffer[8] = '9';
						write(fd[1], buffer, 10);
					}
				}
			}
			else {
				waitpid(pid1, &status1, 0);
				waitpid(pid2, &status2, 0);
				waitpid(pid4, &status4, 0);
				read(fd[0], buffer, 10);
				printf("Leido %s\n", buffer);
			}
			
		}
	}
	return 0;
}
