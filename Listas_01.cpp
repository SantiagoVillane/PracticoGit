// Listas_01.cpp 
//
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

template <class T> class Nodo {
private:
    T dato;
    Nodo* next;
public:
    Nodo() { next = NULL; };
    Nodo(T a) { dato = a; next = NULL; };
    void set_dato(T a) { dato = a; };
    void set_next(Nodo* n) { next = n; };
    T get_dato() { return dato; };
    Nodo* get_next() { return next; };
    bool es_vacio() { return next == NULL; }
};

template <class T> class Lista {
private: Nodo<T>* czo;
public:
    Lista() { czo = new Nodo<T>(); };
    Lista(Nodo<T>* n) { czo = n; };
    //~Lista(void);
    void add(T d);
    bool esvacia(void);
    T cabeza(void);
    Lista* resto(void);
    string toPrint(string p);
    T suma(T i);
    
	int size();
    void borrar();
    void borrar_last();
    void concat(Lista* l1);
    Lista* copy(void);
    void tomar(int n);
};
template <class T>
void Lista<T>::add(T d)
{
    Nodo<T>* nuevo = new Nodo<T>(d);
    nuevo->set_next(czo);
    czo = nuevo;
}
template <class T>
bool Lista<T>::esvacia(void)
{
    return czo->es_vacio();
}
template <class T>
T Lista<T>::cabeza(void)
{
    if (esvacia()) {
        cout << " Error, Cabeza de lista vacia";
        return NULL;
    }
    return czo->get_dato();
}

template <class T>
Lista<T>* Lista<T>::resto(void)
{
    Lista* l = new Lista(czo->get_next());
    return (l);
}

template <class T>
string Lista<T>::toPrint(string p)
{
    if (this->esvacia()) {
        return p;
    }
    else {
        //std::ostringstream stm;
        ostringstream stm;
        stm << this->cabeza() << "-" << this->resto()->toPrint(p) << endl;
        //cout<<endl<<" stm.str()= "<<stm.str()<<endl;
        return stm.str();
    }
}

template <class T>
T Lista<T>::suma(T i)
{    //cout<<" i al entrar= "<<i<<endl;
    if (this->esvacia()) {
        return i;
    }
    else {

        //cout<<"this->cabeza()= "<<this->cabeza()<<endl;   
        return this->resto()->suma(i + this->cabeza());
    }
}

// --------------------------------------------------------------------------------TAREA-----------------------------------------------------------------------------------------------

template <class T>
int Lista<T>::size(){
	
	if(this->esvacia()){
		return 0;
	}
		return 1+this->resto()->size();
	} 

template <class T>
void Lista<T>::borrar(){
	if(this->esvacia()){
		cout<<"Ta vacio broh"<<endl;
	}
	else{
	czo=czo->get_next(); 
}
}

template <class T> void Lista<T>::borrar_last(){
	if(this->esvacia()){
		cout<<"Vacio broh"<<endl;
	}
	else if ((czo->get_next())->get_next()==NULL) {
        czo->set_next(NULL);
    }
    else {
       this->resto()->borrar_last();
    }
	
}

template <class T> void Lista<T>::concat(Lista* l1){
	if(l1->esvacia()){
	}
	else{
	this->add(l1->cabeza());
	this->concat(l1->resto());
	}
}

template <class T> Lista<T>* Lista<T>::copy(){
	Lista* t = new Lista(this->czo);
	return t;
}

template <class T> void Lista<T>::tomar(int n){
	int d=this->size()-n;
	for(int i=0;i<d;i++){
		this->borrar_last();
	}
}

// --------------------------------------------------------------------------------TAREA-----------------------------------------------------------------------------------------------


int main()
{
    Lista<string>* l = new Lista<string>();
    Lista<int>* r = new Lista<int>();
    Lista<string>* l2 = new Lista<string>();
    l->add(" 11x");
    l->add(" 22y");
    l->add(" 33z");
    l2->add("2 pesito");
    l2->add("3 pesito");
    r->add(100);
    r->add(22);
    r->add(33);
    cout << "l= "<<l->toPrint("fin") << endl;
   // cout << "r= " << r->toPrint("fin") << endl;
    //cout << "suma:" << r->suma(0) << endl;
	//cout << l->size()<<endl;
    //l->borrar();
    //l->borrar_last();
	//cout << "l2= "<<l2->toPrint("fin") << endl;
	l->concat(l2);
	//Lista<int>* i = r->copy();
	//cout << "i= "<<i->toPrint("fin") << endl;
	l->tomar(3);
    cout << "l= "<<l->toPrint("fin") << endl;

	
	system("PAUSE");
    return EXIT_SUCCESS;

}

/*
int size();// cantidad de nodos de la lista
void borrar(void); //borra la cabeza
void borrar_last();//borra el ultimo
void concat(Lista* l1);// le transfiere los datos de l1 a this
Lista* copy(void);// hace una copia de la lista
void tomar(int n);//deja "vivos" los n primeros nodos y borra el resto
*/
