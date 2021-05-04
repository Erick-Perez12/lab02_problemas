#include <iostream>
using namespace std;

void crear(char * &lista, long long tam){
    cout<<"Ingresar palabra: "; cin.getline(lista,tam);
}
int tamaRe(char *lista){
    if(*lista =='\0') return 0;
    else {
        return 1 + tamaRe(lista+1);
    }
}
int main(){
	long long  tam=1000000;
    char *lista = new char[tam];
	crear(lista,tam);
    cout<<"TAMAÑO POR RECURSIVIDAD: "<<tamaRe(lista);
	delete[]lista;
    return 0;
}
