// Listas_02.cpp 
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
    void add(T d); //sumar nodos a la lista
    bool esvacia(void);
    T cabeza(void); //retorna el dato del primer nodo
    Lista* resto(void); //retorna el puntero al "resto" de la lista
                        //resto= lo que queda de la lista sin la cabeza
    string toPrint(string p);
    T suma(T i);
    int size();
    void borrar(void); //borra la cabeza
    void borrar_last();//borra el ultimo
    void concat(Lista<T>* l1);// le transfiere los datos de l1 a this
    Lista<T>* copy(void);// hace una copia de la lista
    void tomar(int n);//deja "vivos" los n primeros nodos y borra el resto
   
   	Lista <T>* insertar(T d,int n=0);
   	void addOrdenado(T d,int n=1);
   	Lista<T> final(int n);
};
template <class T>
void Lista<T>::add(T d) //100
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
    if (this->esvacia()) {
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

int main()
{
    Lista<string>* l = new Lista<string>();
    Lista<int>* r = new Lista<int>();
    Lista<string>* l2 = new Lista<string>();
    
    Lista<int>* i = new Lista<int>();
   
    //r->add(100);
    //r->add(22);
    //r->add(12);r->add(2);
	/*cout<<r->toPrint(" ");
    r->final(2);
    cout<<r->toPrint(" ");
    r->tomar(1);
    */
	//r->insertar(3,5);
	//cout<<r->toPrint(" ");
   /* 
    l->add(" 11x");
    l->add(" 22y");
    l->add(" 33z");
    
    cout << "l= "<<l->toPrint("fin") << endl;
    cout << "r= " << r->toPrint("fin") << endl;
    cout << "l2= " << l2->toPrint("fin") << endl;
    cout << "suma:" << r->suma(0) << endl<<endl;
    cout << "size l= " << l->size() << endl;
    cout << "size r= " << r->size() << endl;
    cout << "size l2= " << l2->size() << endl<<endl;

    l2->add(" AA");
    l2->add(" BB");
    l2->concat(l);
    cout << l2->toPrint(" soy l2 concatenada con l");
    cout << l->toPrint(" soy l");
    Lista<string>* copia = l->copy();
    cout << copia->toPrint(" soy copia de l");
    l->borrar_last();
    cout << l->toPrint(" soy l");
    l->borrar_last();
    cout << l->toPrint(" soy l");
    l = copia->copy();
    cout << l->toPrint(" soy l");
    l->borrar();
    cout << l->toPrint(" soy l");

    cout << l2->toPrint(" soy l2");
    l2->tomar(4);
    cout << l2->toPrint(" soy l2");
    */
	i->add(3);
	i->add(1);
	i->add(2);
	i->insertar(4,3);
	cout<<i->toPrint(".");
	
    cout << endl << endl;
    system("PAUSE");
    return EXIT_SUCCESS;

}


/*
void addOrdenado(T d)// suma nodos ordenados de menor a mayor
bool esta(T d); //retorna true cuando d est? en la lista
void borrarDato(T d)// borra el nodo que contiene a d
*/

template <class T> Lista<T>* Lista<T>::insertar(T d,int n){
	
	Lista<T>* j = new Lista();
    j->concat(this);
	this->final(n);
	this->add(d);
	j->tomar(n);
	this->concat(j);
	return this;
	}
	
template <class T> void Lista<T>::addOrdenado(T d,int n){
	if(this->esvacia()){
		this->add(d);
	}else{
	if(d<(this->czo->get_dato())){
		this->insertar(d,n);
}
	else{
		this->resto()->addOrdenado(d);
		n++;
	}
	}
}
template <class T> Lista<T> Lista<T>::final(int n){
	for(int i=0;i<n;i++){
		this->borrar();
	}
}

template <class T> int Lista<T>::size()
{
    if (this->esvacia()) return 0;
    return 1 + this->resto()->size();
}



template <class T> void Lista<T>::borrar(void)
{ //borra el nodo cabeza
    if (!this->esvacia()) {
        Nodo<T>* tmp = czo;
        czo = czo->get_next();
        delete tmp;
    }
}

template <class T> void Lista<T>::borrar_last()
{ // borra el ultimo nodo
    if (!this->esvacia()) {
        if ((czo->get_next())->get_next() == NULL) {
            delete czo->get_next();
            czo->set_next(NULL);
        }
        else this->resto()->borrar_last();
    }
}

template <class T> void Lista<T>::concat(Lista<T>* l1)
{// le transfiere los datos de l1 a this
    if (!(l1->esvacia())) {
        this->concat(l1->resto());
        this->add(l1->cabeza());
    }
}

template <class T> Lista<T>* Lista<T>::copy(void)
{
    Lista<T>* aux = new Lista();
    aux->concat(this);
    return aux;
}

template <class T> void Lista<T>::tomar(int n)
{ //deja "vivos" los n primeros nodos y borra el resto
    if (this->size() > n) {
        this->borrar_last();
        this->tomar(n);
    }
}



