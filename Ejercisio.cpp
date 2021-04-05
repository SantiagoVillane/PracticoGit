#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string.h>


using namespace std;

void copiar_parte_a_en_parte_b(const int*a, int* b, const unsigned int &len_a, const unsigned int &len_b,
                               const unsigned int &start_a, const unsigned int &start_b){
if(start_a>=len_a){
cout<<"ERROR A"<<endl;
}
else if(start_b>=len_b){
cout<<"ERROR B"<<endl;
}
else if((len_a - start_a) > (len_b - start_b)){
cout<<"ERROR C"<<endl;
}
else{
int j=0;

for(int i=start_a;i<int(len_a);i++){ 
	b[start_b+j]=a[i];
	j++;
}}


}

int main(){
int a[5] = {2, 4, 8, 10, 5};
int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//copiar_parte_a_en_parte_b(a, b, 5, 10, 1, 1);
//Deber�a modificar b de manera que:
copiar_parte_a_en_parte_b(a, b, 5, 10, 5, 1);
//copiar_parte_a_en_parte_b(a, b, 5, 10, 1, 10);

for(int i=0;i<10;i++){
	cout<<" "<<b[i]<<" ";
}

return 0;
}



    
    // Razones por la que puede fallar el metodo:
    // 1. start_a > len_a (No puede acceder una longitud mayor a mi arreglo)
    // 2. start_b > len_b (No puede acceder una longitud mayor a mi arreglo)
    // 3. len_a - start_a > len_b - start_b (B tiene que tener el espacio suficiente para soportar la cantidad de
    // elementos que se van a copiar de a)

