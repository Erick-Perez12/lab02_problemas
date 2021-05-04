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
/*long long sumare(long long *lista, long long tam){//para tamaño de array hasta el 10000
	if(tam==0) return 0;
	return lista[tam-1]+sumare(lista, tam-1);
}*/
long long sumare(long long *lista, long long inicio,long long final){
	if(inicio>final)return 0;
	if(inicio==final) return lista[final];
	long long primpart=sumare(lista,inicio+1,((inicio+1)+final)/2);
	long long segpart=sumare(lista,(((inicio+1)+final)/2)+1,final);
	return lista[inicio]+primpart+segpart;	
}
int main(){
	long long  *lista, tam=1000000;
	crear(lista,tam);
	cout<<"Suma con recursividad: "<<sumare(lista,0,tam-1)<<"\n";
	delete[]lista;
	system("pause");
	return 0;
}
