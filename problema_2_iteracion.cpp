#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;
void crear(long long * &lista, long long tam){
	srand(time(NULL));
	lista=new long long [tam];
	for(long long i=0;i<tam;i++){
		lista[i]=1+rand()%10;
	}
	cout<<"\n";
}
void mostrar(long long *lista, long long tam){
	ofstream archivo;
	archivo.open("Lista_iteracion.txt",ios::out);
	for(long long i=0;i<tam;i++){
		archivo<<lista[i]<<" ";
	}
	archivo.close();
}
void invertir(long long *lista, long long tam){//iterativa
    ofstream file;
	file.open("Lista_invertido_iteracion.txt",ios::out);
	long long *listab;
	listab=new long long [tam];
	for(long long  j=0;j<tam;j++){
		listab[j]=lista[tam-(j+1)];
		file<<listab[j]<<" ";
	}
	file.close();
}
int main(){
	long long  *lista, tam=1000000;
	crear(lista,tam);
	mostrar(lista,tam);
	cout<<"LISTA GUARDADA EN TXT \n";
	invertir(lista,tam);
	cout<<"LISTA INVERTIDAD EN TXT \n";
	cout<<endl;
	delete[]lista;
	system("pause");
	return 0;
}
