#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;
void crear(long long * &lista, long long tam){
	ofstream file;
	srand(time(NULL));
	lista=new long long [tam];
	file.open("lista_original_problem_2.txt",ios::out);
	for(long long i=0;i<tam;i++){
		lista[i]=1+rand()%10;
		file<<lista[i]<<" ";
	}
	file.close();
}
/*void invertirRe(long long *&mylista, long long tam){//funcional hasta el 43723
	if(tam>0){
		cout<<mylista[tam]+1<<" ";
		invertirRe(mylista,tam-1);
	}
}*/  
long long invertirRe(long long * lista,long long inicio,long long final){
	long long aux;
	if(inicio>=final)return 0; //error solo funciona con cadenas pequeñas
	//cout<<"inicio: "<<inicio<<"final: "<<final<<"\n";
	//cout<<"inicioval: "<<lista[inicio]<<" finalval: "<<lista[final]<<"\n";
	aux=lista[inicio];
	lista[inicio]=lista[final];
	lista[final]=aux;
	//cout<<"iniciofin: "<<lista[inicio]<<" finalfin: "<<lista[final]<<"\n";
	return invertirRe(lista,inicio+1,final-1);
} 
void invertirRec(long long *lista, long long tam){
	ofstream archivo;
	archivo.open("Lista_invertidad_recursividad.txt",ios::out);
    if(tam>=1){
    	cout<<*(lista+(tam-1))<<" ";
        invertirRec(lista,tam -1);
    }
    archivo<<*(lista+(0))<<" ";
    archivo.close();
}
void mostrar(long long *lista, long long tam){
	ofstream archivo;
	archivo.open("Lista_invertidad_recursividad.txt",ios::out);
	for(int i=0;i<tam;i++){
		archivo<<*(lista+i)<<" ";
	}
	archivo.close();
}
int main(){
	long long  *lista, tam=1000000;
	crear(lista,tam);
    //invertirRe(lista,0,tam-1);
    //invertirRec(lista, tam);
	//mostrar(lista,tam);
	cout<<endl;
	delete[]lista;
	system("pause");
	return 0;
}
