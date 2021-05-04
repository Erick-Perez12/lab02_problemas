#include <iostream>

using namespace std;

void crear(char * &lista, long long tam){
    cout<<"Ingrese palabra: "; cin.getline(lista,tam);
}

int tamIte(char *lista){
    int cont=0;
    for(;*(lista+cont)!='\0';cont++);
    cout<<cont;
    return 0;
}
int main(){
	long long  tam=1000000;
    char *lista = new char[tam];
	crear(lista,tam);
    cout<<"Tamaño de la cadena por iteracion: ";
    tamIte(lista);
	delete[]lista;
    return 0;
}
