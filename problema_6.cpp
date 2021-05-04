#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;
void crear(string * &lista, long long tam){
	ifstream archivo;
	archivo.open("D:\\2. ERICK\\3er semestre\\cc\\Lab_02_GRUPO_A_Perez_Chipa_Erick_UNSA_EPCC_CC_II\\palabra.txt",ios::in);
	if(archivo.fail()){
		cout<<"texto no encontrado";
		exit(1);
	}
	for(int i=0;i<tam;i++){
		archivo>>*(lista+i);
		//cout<<*(lista+i);
	}
	archivo.close();

}

void Quicksort(string *lista, long long inicio,long long final){
    int centro, i = inicio, j = final;
	string pivot;
	centro = (inicio+final)/2;
	pivot = lista[centro];
	do{
		while (lista[i]<pivot) i++;
		while (lista[j]>pivot) j--;
		if(i<=j){
			string aux;
			aux = lista[i];
			lista[i] = lista[j];
			lista[j] = aux;
			i++;
			j--; 
		}
	}
	while(i<=j);
	if(inicio<j) Quicksort(lista, inicio, j);
	if(i<final) Quicksort(lista,i,final);
}
void mostrar(string *lista, long long tam){
	ofstream file;
	file.open("texto_ordenado.txt",ios::out);
	for(long long i=0;i<tam;i++){
		file<<*(lista+i)<<" , ";
	}
	file.close();
}
int main(){
	long long  tam=1000000;
    string *lista = new string[tam];
	crear(lista,tam);
	cout<<"TEXTO LEIDO ";
	Quicksort(lista,0,tam-1);
	cout<<"\nLista ordenada: "<<endl;
	mostrar(lista,tam);
	cout<<"TEXTO ORDENADO Y GUARDADO \n";
	delete[]lista;
    return 0;
}
