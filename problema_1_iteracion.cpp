#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void crear(long long * &lista, long long tam){
	srand(time(NULL));
	lista=new long long [tam];
	for(int i=0;i<tam;i++){
		lista[i]=1+rand()%10;
	}
}
long long sumaite(long long *lista,long long tam){
	long long sum=0;
	for(long long j=0;j<tam;j++){
		sum+=lista[j];
	}
	return sum;
}
int main(){
	long long  *lista, tam=1000000;
	crear(lista,tam);
	cout<<"Suma con iteracion: "<<sumaite(lista,tam)<<"\n";
	delete[]lista;
	system("pause");
	return 0;
}
