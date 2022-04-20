#include<iostream>
#include<cstdlib>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define maxchar 50
using namespace std;


struct nodo{
	
	int matricula;
	char nombre[maxchar];
	int mat;
	int ing;
	int esp;
	struct nodo *sgte;
	char temp[maxchar];
	float promedio;
	
};


typedef struct nodo *Alista;
void menu(void){
	
	cout<<"\n\t\t    REGISTRO DE ESTUDIANTE    \n";
	cout<<" 1. REGISTRAR ESTUDIANTE                        "<<endl;
	cout<<" 2. ELIMINAR ESTUDIANTE                         "<<endl;
	cout<<" 3. MOSTRAR LISTADO                             "<<endl;
	cout<<" 4. SALIR                                       "<<endl;
	
	cout<<"\n Ingrese opcion : ";
}
	
	void registrar_estudiante(Alista &lista){
		
		Alista t,q = new(struct nodo);
		cout<<"\n\tDATOS DEL ESTUDIANTE";
		cin.ignore();cout<<"\n\n\tMATRICULA:"; cin>>q->matricula;
		cin.ignore();cout<<"NOMBRES:"; cin.getline(q->nombre,maxchar);
		cout<<"\nCalificacion de materias "<<endl;
		cin.ignore();cout<<"ESPAÑOL:"; cin>>q->esp;
		cin.ignore();cout<<"INGLES:"; cin>>q->ing;
		cin.ignore();cout<<"MATEMATICAS:";cin>>q->mat;
		system("cls");
		
		q->sgte = NULL;
		
		if(lista==NULL){
			lista = q;
			
		} else {
			
			t = lista;
			
			while(t->sgte!=NULL){
				
				t = t->sgte;
			}
			t->sgte = q;
			
		}
	}
		
		
		void eliminar_estudiante(Alista &lista){
			
			int matr;
			Alista q,t;
			q=lista;
			
			cout<<"\n\n\n\tELIMINAR UN ESTUDIANTE";
			cout<<"\n\n\tINGRESE MATRICULA:"; cin>>matr;
			
			while(q!=NULL){
				
				if(q->matricula==matr){
					
					if(q==lista)
						lista=lista->sgte;
					
					else
						t->sgte=q->sgte;
					
					delete(q);
					
					cout<<"\n\n\tESTUDIANTE ELIMINADO...!!!!!\n";
					
					return;
					
				}else {
					
					t=q;
					q=q->sgte;
					
				}
				
			}
			if(q==NULL)
				  cout<<"\n\tMATRICULA INCORRECTA...!!\n";
			
		}
			
			void mostrar_estudiantes(Alista q){
				
				int i=1;
				int m=0,in=0,e=0;
				int suma;
				float promedio=0;
				while(q!=NULL){
					
					cout<<"\n\tDATOS DEL ESTUDIANTE ["<<i<<"] ";
					cout<<"\n\n\tMATRICULA   : "<<q->matricula<<endl;
					cout<<"NOMBRE  : "<<q->nombre<<endl;
					cout<<"ESPAÑOL : "<<q->esp<<endl;
					cout<<"INGLES : "<<q->ing<<endl; 
					cout<<"MATEMATICAS: "<<q->mat<<endl;
					
					m=q->mat;
					in=q->ing;
					e=q->esp;
					suma=m+in+e;
					promedio =(suma/3);
					cout<<"Promedio:"<<promedio<<endl;
					q=q->sgte;
					i++;
				}
			}
				
				int main(void){
					
					Alista lista=NULL;
					
					int opcion;
					
					do{
						menu();
						cin>>opcion;
						
						switch(opcion){
							
						case 1: registrar_estudiante(lista);
						break;
						
						case 2: if(lista==NULL){
							
							cout<<"\n\tNo Hay Estudiantes Registrados.....!!!!\n";
							
						}else{
							eliminar_estudiante(lista);
							
						}
						break;
						
						
						case 3: if(lista==NULL){
							
							cout<<"\n\tNo Hay estudiantes Registrados.....!!!!\n";
							
						}else {
							mostrar_estudiantes(lista);
						}
						break;
					    
						case 6:
						
							return 0;
						default: cout<<"\nINGRESE UNA OPCION VALIDA...\n"; break;
						
						}
						
						system("pause"); 
						system("cls");
						
					}while(opcion!=6);
					
					system("pause");
					
					return 0;
				}
