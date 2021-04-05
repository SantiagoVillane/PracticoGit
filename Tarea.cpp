#include <cstdlib>
#include <iostream>
#include <sstream>
#include <iomanip>    

using namespace std;

template<class Data>
class Node {
private:
    Data data;
    Node *next;
public:
	Node(){
		next=NULL;
	}
    Node(Data data){
        this->data = data;
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
    bool esvacio(){
    	return next==NULL;
	}
    
    Node *get_siguiente(){
        return next;
    }
    void set_siguiente(Node *next){
        this->next = next;
    }
};

template<class T>
class LinkedList {
protected:
    Node<T>* head;
    int p=0;
public:
    Node <T>* get_cabeza() const{
        return this->head;
    }
    
	LinkedList<T>* rest ()const{
    	 LinkedList<T>* r=new LinkedList(head->get_siguiente());
	return r;
	}

    LinkedList<T> operator +=(const LinkedList<T> &list){
	if(list.es_vacia()){
		return *this;
	}	
	
	
		this->agregar(list.head->get_data());
		return this->operator+=(*list.rest());
    }

    LinkedList(){
    	head=new Node<T>();
    }
    
	LinkedList(Node <T>* n){
    	head= n;
    }

    void agregar(T data){
        Node<T>* n= new Node<T>(data);
		n->set_siguiente(head);
		head=n; 
    }


    bool es_vacia() const{
	return head->esvacio();
    }


    void print(){
    if(this->es_vacia()){
    	cout<<"Lista Vacia!"<<endl;
		}
    else 
		{		
		cout<<"La lista es:"<<endl;
		this->prinT();			
		}
	}
	void prinT(){
		if(this->es_vacia()){
			
		}else{
		cout<<head->get_data()<<setw(4);
		this->rest()->prinT();
	}}

    int size(){
        if(this->es_vacia()){
        	return 0;
		}
		return 1 + (this->rest()->size());
    }
};

int main()
{
   /* LinkedList<string>* l = new LinkedList<string>();
    LinkedList<int>* r = new LinkedList<int>();
    LinkedList<string>* l2 = new LinkedList<string>();
    l->agregar(" 11x");
    l->agregar(" 22y");
    l->agregar(" 33z");
    l2->agregar("2 pesito");
    l2->agregar("3 pesito");
	r->agregar(100);
    r->agregar(22);
    r->agregar(33);
	l->print();   
   ((l)->operator+=(*l2)).print();
   cout<<l->size()<<endl;
   */
   LinkedList<int> l, m;
l.agregar(1);
l.agregar(2);
m.agregar(3);
m.agregar(4);
l.operator +=(m);
l.print();
cout << endl;
	
	system("PAUSE");
    return EXIT_SUCCESS;

}
