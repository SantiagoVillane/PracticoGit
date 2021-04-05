#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

template<class Data>
class Node {
private:
    Data data;
    Node *next;
public:
    Node(Data data){
        this->data = data;
        this->next = NULL;
    }
    Node(){
        
        this->next = NULL;
    }
    void set_data(Data data){
        this->data = data;
    }
    Data get_data(){
        return data;
    }
    bool tiene_siguiente(){
        return next != NULL;
    }
    Node *get_siguiente(){
        return next;
    }
    void set_siguiente(Node *next){
        this->next = next;
    }
    bool esvacio(){
    	return this->get_siguiente() == NULL;
	}
};

template<class T>
class PilaEnlazada {
private:
    Node<T>* head;
public:
    PilaEnlazada() {
    	head = new Node<T>();
        // Completar
    }

    void push(T elemento) {
        Node<T> *n=new Node<T>(elemento);
        n->set_siguiente(head);
        head=n;
		// Completar
    }

    T get_top() {
    	if(this->empty()){
    		throw out_of_range("La lista esta vacia");
		}
    	
       return this->head->get_data(); // Completar
    }

    void pop() {
        // Completar
        if(this->empty()){
        	throw out_of_range("No se puede hacer pop de una pila vacía");
		}
        
		head=head->get_siguiente();    
	}

    bool empty() {
      // Completar
      return head->esvacio();
    }
};

main(){
	PilaEnlazada<char> pila;
	
	cout<<pila.empty();
/*pila.push('a');
pila.pop();
try{
  pila.pop();
  cout << "Excepcion no fue generada!";
} catch( std::out_of_range e1 ) {
  cout << e1.what();
}
*/
}
