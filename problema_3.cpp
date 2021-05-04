#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
void crear(long long * &lista, long long tam){
	ofstream archivo;
	archivo.open("lista_original.txt",ios::out);
	srand(time(NULL));
	lista=new long long [tam];
	for(int i=0;i<tam;i++){
		lista[i]=1+rand()%10;
		archivo<<lista[i]<<" ";
	}
	archivo.close();
}
void mostrar(long long *lista, long long tam){
	ofstream file;
	file.open("lista_ordenada.txt",ios::out);
	for(long long i=0;i<tam;i++){
		file<<lista[i]<<" ";
	}
	file.close();
}

void quicksort(long long *lista, long long izq, long long der){
	long long i,j,x,aux;
	i=izq;
	j=der;
	x=lista[(izq+der)/2];
	do{
		while((lista[i]<x)&&(j<=der)){
			i++;
		}
		while((x<lista[j])&&(j>izq)){
			j--;
		}
		if(i<=j){
			aux=lista[i]; lista[i]=lista[j]; lista[j]=aux;
			i++; j--;
		}
	}
	while(i<=j);
	if(izq<j) quicksort(lista, izq, j);
	if(i<der) quicksort(lista,i,der);
}
int main(){
	long long  *lista, tam=1000000;
	crear(lista,tam);
	cout<<"GUARDANDO LISTA EN TXT"<<endl;
	quicksort(lista,0,tam-1);
	mostrar(lista,tam);
	cout<<"GUARDANDO LISTA ORDENADA EN TXT"<<endl;
	delete[]lista;
	system("pause");
	return 0;
}
