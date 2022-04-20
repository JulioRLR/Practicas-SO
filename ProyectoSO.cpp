#include <iostream>
using namespace std;
class Planificador3{
private:
	int ram=10;
	int Aux[11]={1,1,1,1,1,1,1,1,1,1,1};
	int ti[11]={1,2,3,4,5,6,7,8,9,10,11};
	int tll[11]={0,3,5,6,2,4,4,7,4,3,0};
	int tex[11]={1,3,4,1,2,3,1,1,5,2,1};
	int Ram[11]={2,3,4,11,2,8,6,3,6,9,10};
	int pri[11]={2,1,3,2,2,2,1,1,2,1,4};
	int Final[11];
public:

	int z=0;
	int r=0,y=10,t=0,o=0,p=0,a=0,s=0,d=0,f=0,w=0,q=10,j=0;
	
	void monotar(){
		int z=0;
		int r=0,y=10,t=0,o=0,p=0,a=0,s=0,d=0,f=0,w=0,q=10,j=0;
		do{
			r=0,y=10,t=0,o=0,p=0,a=0,s=0,d=0,f=0,w=0,q=10,j=0;
			//================llegada
			
			for(int i=0; i<11; i++){//Tiempo llegada menor
				if(Aux[i]==1){
					if(q>tll[i]){
						if(tex[i]!=0){
							q=tll[i];
						}
					}
				}
			}
			w=q;//Tiempo llegada menor
			for(int i=0; i<11; i++){//cuenta los menores iguales
				if(Aux[i]==1){
					if(w==tll[i]){
						r++;
					}
				}
			}
			int *menores = new int[r];//crea el arreglo con el lugar de los menores 
			//	cout<<"1-En el tiempo: "<<z<<" los Pid qu entran son: "<<endl;
			for(int i=0; i<11; i++){//llena el arreglo con el lugar de los menores 
				if(w==tll[i]){
					if(Aux[i]==1){
						menores[t]=ti[i];
						t++;
						//				cout<<"("<<"T"<<ti[i]<<")";
					}
				}
			}
			//	cout<<endl;
			
			
			//========================================= T ejecucion
			for(int i=0; i<r; i++){//comparar ejecucion de menores tiempos de llegada 
				int u =menores[i];
				u=u-1;
				if(y>tex[u]){
					y=tex[u];
				}
			}
			
			for(int i=0; i<r; i++){//Numero de repetidos de tiempo de ejecucion dentro de los menores de tiempo de llegada 
				int u =menores[i];
				u=u-1;
				if(y==tex[u]){
					o++;
				}
			}
			int *ejecucion = new int[o];// Arreglo de todos los tiempos de ejecucion repetidos
			//	cout<<"2-El menor Tiempo de ejecucion es: "<<y<<" y los Pid son: "<<endl;
			for(int i=0; i<11; i++){//llena el arreglo con el lugar de los menores tiempos de ejecucion 
				if(y==tex[i]){
					if(Aux[i]==1){
						if(w==tll[i]){
							ejecucion[p]=ti[i];
							p++;
							//					cout<<"("<<"T"<<ti[i]<<")";
						}
					}
				}
			}
			//	cout<<endl;
			
			//========================= prioridad 
			for(int i=0; i<o; i++){//comparar la mayor  prioridad de menores tiempos de ejecucion 
				int u =ejecucion[i];
				u=u-1;
				if(a<pri[u]){
					a=pri[u];
				}
			}
			
			for(int i=0; i<o; i++){//Numero de repetidos de priuoridad  dentro de los menores de tiempo de ejecucion
				int u =menores[i];
				u=u-1;
				if(a==pri[u]){
					s++;
				}
			}
			int *prioridad = new int[s];// Arreglo de todos las prioridades repetidas
			//	cout<<"3-La Mayor Prioridad es: "<<a<<endl;
			//	cout<<"==El Pid que se ejecuta=="<<endl;
			for(int i=0; i<11; i++){//llena el arreglo con el lugar de la mayor prioridad
				if(a==pri[i]){
					if(y==tex[i]){
						if(Aux[i]==1){
							prioridad[d]=ti[i];
							d++;
							//				cout<<"("<<"T"<<prioridad[0]<<")";
						}
					}
				}
			}
			//	cout<<endl;
			
			f=prioridad[0];
			f=f-1;
			if(Ram[f]>ram){
				Aux[f]=0;
				cout<<"(/)";
				z++;
				
			}
			
			else {
					for(int xi=0;xi<tex[f];xi++){
					cout<<"("<<prioridad[0]<<")";//casi falta 3
					}
					
					Aux[f]=0;
				
			}
			
			z++;
			delete [] menores;
			delete [] ejecucion;
			delete [] prioridad;
			d=0;
			a=0;
			y=0;
			o=0;
			q=10;
			r=0;
			t=0;
			j=0;
		}while(z!=23);
		
		
	}
};


