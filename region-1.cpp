#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	pid_t pid1, pid2, pid3, pid4, pid5, pid6, pid7, pid8, pid9, pid10;
	int status1, status2, status3, status4, status5, status6, status7, status8, status9, status10;
	int fd[2],ff[2],tvuelo,tpago,tregion,j;
	float total,boleto,iva;
	char vuelo[12],pago[13],region[5];
	pipe(fd);
	if ((pid1=fork()) == 0 ){ /*padre*/
		printf("Soy el Padre %d, hijo de %d\n", getpid(), getppid());
		printf("Que tipo de vuelo desea ?  1= Nacional 2= Internacional");
		scanf("%d",&tvuelo);
		if(tvuelo== 1){
			printf("Escribiendo en el PIPE\n");
			vuelo[0]='n';
			vuelo[1]='a';
			vuelo[2]='c';
			vuelo[3]='i';
			vuelo[4]='o';
			vuelo[5]='n';
			vuelo[6]='a';
			vuelo[7]='l';
			vuelo[8]='\0';
			vuelo[9]='\0';
			vuelo[10]='\0';
			vuelo[11]='\0';
			write(fd[1], vuelo, 12);
		}
		if(tvuelo==2){
			printf("Escribiendo en el PIPE\n");
			vuelo[0]='i';
			vuelo[1]='t';
			vuelo[2]='e';
			vuelo[3]='r';
			vuelo[4]='n';
			vuelo[5]='a';
			vuelo[6]='c';
			vuelo[7]='i';
			vuelo[8]='o';
			vuelo[9]='n';
			vuelo[10]='a';
			vuelo[11]='l';
			write(fd[1], vuelo, 12);
		}
		
	} else{
		waitpid(pid1,&status1,0);
		
		if ((pid2=fork()) == 0 ){/*pago*/
			printf("Num. de boletos ?");
			scanf("%d",&boleto);
			printf("Soy %d, hijo de %d\n", getpid(), getppid());
			printf("Que tipo de pago desea ?  1= efectivo 2= tarjeta 3= transferncia");
			scanf("%d",&tpago);
			if(tpago== 1){
				printf("Escribiendo en el PIPE\n");
				pago[0]='e';
				pago[1]='f';
				pago[2]='e';
				pago[3]='c';
				pago[4]='t';
				pago[5]='i';
				pago[6]='v';
				pago[7]='o';
				pago[8]='\0';
				pago[9]='\0';
				pago[10]='\0';
				pago[11]='\0';
				pago[12]='\0';
				write(fd[1], pago,13);
				total*=boleto;
				total*=1.15;
			}
			if(tpago==2){
				printf("Escribiendo en el PIPE\n");
				pago[0]='t';
				pago[1]='a';
				pago[2]='r';
				pago[3]='j';
				pago[4]='e';
				pago[5]='t';
				pago[6]='a';
				pago[7]='\0';
				pago[8]='\0';
				pago[9]='\0';
				pago[10]='\0';
				pago[11]='\0';
				pago[12]='\0';
				write(fd[1], pago,13);
				total*=boleto;
				total*=1.30;
			}
			if(tpago==3){
				printf("Escribiendo en el PIPE\n");
				pago[0]='t';
				pago[1]='a';
				pago[2]='n';
				pago[3]='s';
				pago[4]='f';
				pago[5]='e';
				pago[6]='r';
				pago[7]='e';
				pago[8]='n';
				pago[9]='c';
				pago[10]='i';
				pago[11]='a';
				write(fd[1], pago, 12);
				total*=boleto;
				total*=1.20;
			}
			
		}else{
			waitpid(pid2,&status2,0);
			if ((pid3=fork()) == 0 ){/*region*/
				printf("Soy %d, hijo de %d\n", getpid(), getppid());
				
				printf("Que tipo de rgion desea ?  1=Norte  2=Sur 3= Este 4=Oeste");
				scanf("%d",&tregion);
				if(tregion==1){
					printf("Escribiendo en el PIPE\n");
					region[0]='n';
					region[1]='o';
					region[2]='r';
					region[3]='t';
					region[4]='e';
					write(fd[1], region, 5);
					
					printf("Escribiendo total en el PIPE\n");
					total*=2500;
					
				//	write(ff[1], &total,sizeof(total));
					
				}
				if(tregion==2){
					printf("Escribiendo en el PIPE\n");
					region[0]='s';
					region[1]='u';
					region[2]='r';
					region[3]='\0';
					region[4]='\0';
					write(fd[1], region, 5);
					printf("Escribiendo total en el PIPE\n");
					total*=1850;
				
				//	write(ff[1], &total,sizeof(total));
				}
				if(tregion==3){
					printf("Escribiendo en el PIPE\n");
					region[0]='e';
					region[1]='s';
					region[2]='t';
					region[3]='e';
					region[4]='\0';
					write(fd[1],region, 5);
					printf("Escribiendo total en el PIPE\n");
					total*=4200;
					
					//write(ff[1], &total,sizeof(total));
				}
				if(tregion==4){
					printf("Escribiendo en el PIPE\n");
					region[0]='o';
					region[1]='e';
					region[2]='s';
					region[3]='t';
					region[4]='e';
					write(fd[1],region, 5);
					printf("Escribiendo total en el PIPE\n");
					total*=1780;
					
					//write(ff[1], &total,sizeof(total));
				}
				
			}else{
				waitpid(pid1,&status1,0);
				waitpid(pid2,&status2,0);
				waitpid(pid3,&status3,0);
				printf("Leyendo desde Pipe Vuelo:\n");
				read(fd[0], vuelo, 12);
				printf("He leido %s\n", vuelo);
				
				printf("Leyendo desde Pipe  Pago:\n");
				read(fd[0], pago, 13);
				printf("He leido %s\n", pago);
				
				printf("Leyendo desde Pipe Region:\n");
				read(fd[0], region, 5);
				printf("He leido %s\n",region);
				
				printf("Leyendo desde Pipe Total:\n");
				//read(ff[0],&total,sizeof(total));
				
				printf("He leido %.2f \n",total);
			}
		}
	}
	return 0;
}
