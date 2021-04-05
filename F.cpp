#include <stdexcept> 
#include <iostream>		

using namespace std;


template<class T>
class ArregloPila {
private:
    const int capacidad;
    int puntero_top;
    T *buffer;
public:
    ArregloPila(const int capacidad): capacidad(capacidad), puntero_top(0) {
        // Lista de inicialización permite inicializar valores a variables constantes durante la clase
        // Inicializacion del buffer
        
    }

    void push(T e) {
    	try{
		if((puntero_top==capacidad-1)){
       	    throw "Le erraste pinche gordo";  
			}}catch(const char* Dato){};
			
			
			buffer[puntero_top++]=e;
			
}

    T get_top() {
    	return buffer[puntero_top];
        
    }

    void pop() {
        try{
		if((puntero_top==0)){
       	    throw "Le erraste pinche gordo";  
			}}catch(const char* Dato){};
		
		
        puntero_top--;
    }

    bool empty() {
    	return puntero_top==0;
    }
};

main(){
	ArregloPila<char> pila(10);
pila.push('a');
pila.push('b');
cout << pila.get_top() << endl;
pila.pop();
cout << pila.get_top() << endl;
	
	
}
