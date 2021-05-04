#include <iostream>
using namespace std;
void concade(char *cadA,char *cadB){
	int tam=0;
	for(; *(cadB+tam)!='\0';tam++);
	int ind=0;
	while(*(cadA+ind)!='\0'){
		*(cadB+tam+ind)=*(cadA+ind);
		ind++;
	}
	*(cadB+tam+ind)='\0';
}
int main(){
	char *cadeA=new char[100];
	char *cadeB=new char[100];
	cout<<"cadena a: ";cin.getline(cadeA,100);
	cout<<"cadena b: ";cin.getline(cadeB,100);
	concade(cadeA,cadeB);
	cout<<"A: "<<cadeA<<endl;
	cout<<"B: "<<cadeB<<endl;
	concade(cadeA,cadeB);
	return 0;
}
