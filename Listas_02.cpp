// Listas_02.cpp  con addOrdenado
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
       void addO(T d, Nodo<T>* ant);
       void borrarDatoO(T d,Nodo<T>* ant);
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
    void impre(void);
    T suma(T i);
    int size();
    void borrar(void); //borra la cabeza
    void borrar_last();//borra el ultimo
    void concat(Lista<T>* l1);// le transfiere los datos de l1 a this
    Lista<T>* copy(void);// hace una copia de la lista
    void tomar(int n);//deja "vivos" los n primeros nodos y borra el resto
    void addOrdenado(T d) { addO(d, NULL); }; //sumar nodos a la lista Ordenados de menor a MAYOR

	bool esta(T d);
	void borrarDato(T d){borrarDatoO(d,NULL);};
	
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
    
    
    l->add(" 11x");
    l->add(" 22y");
    l->add(" 33z");
    r->add(100);
    r->add(22);
  /*
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
    cout << l->toPrint(" soy l");
    cout << "copia=" << copia << "   l=" << l << endl;

    l->borrar_last();
    cout << l->toPrint(" soy l");
    l->borrar_last();
    cout << l->toPrint(" soy l");

    l = copia->copy();
    cout << l->toPrint(" soy l");
    l->borrar();
    cout << l->toPrint(" soy l");

    cout << l2->toPrint(" soy l2");
    l2->tomar(1);
    cout << l2->toPrint(" soy l2");
    
*/
    Lista<string>* l3 = new Lista<string>();

    l3->addOrdenado("Maria");
    l3->addOrdenado("Ana");
    l3->addOrdenado("Elena");
   // cout << l3->toPrint(" soy l3");
    //l3->borrarDato("Ana");
    //cout << l3->toPrint(" soy l3");

	cout<<l3->esta("Maria")<<l3->esta("Ana")<<l3->esta("Elena");
    
    /*
    cout << l3->toPrint(" soy l3");
    l3->addOrdenado("Elena");
    cout << l3->toPrint(" soy l3");
    l3->addOrdenado("Oscar");
    cout << l3->toPrint(" soy l3");
    l3->addOrdenado("Nina");
    cout << l3->toPrint(" soy l3");
    l3->addOrdenado("Teresa");
    cout << l3->toPrint(" soy l3");
   */

    cout << endl << endl;
    system("PAUSE");
    return EXIT_SUCCESS;

}

/*
void addOrdenado(T d)// suma nodos ordenados de menor a mayor
bool esta(T d); //retorna true cuando d está en la lista
void borrarDato(T d)// borra el nodo que contiene a d

int size();// cantidad de nodos de la lista
void borrar(void); //borra la cabeza
void borrar_last();//borra el ultimo
void concat(Lista* l1);// le transfiere los datos de l1 a this
Lista* copy(void);// hace una copia de la lista
void tomar(int n);//deja "vivos" los n primeros nodos y borra el resto
*/

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

template <class T> void Lista<T>::impre(void)
{
    Nodo<T> *aux;
    aux = czo;
    while (aux->get_next() != NULL) {
        cout << aux->get_dato() << endl;
        aux = aux->get_next();
    }
}
/*
void Lista<T>::concat(Lista* l1)
{

    if (this->size() <= 1)
        czo->set_next(l1->czo);
    else
        this->resto()->concat(l1);

}
*/

template <class T>
void Lista<T>::addO(T d, Nodo<T>* ant)
{
    if (this->esvacia()) {//el primero
        this->add(d);
    }
    else {
        if (d < czo->get_dato()) {
            if (ant == NULL) {//al principio
                this->add(d);
            }
            else {//entre medio
                Nodo<T>* nuevo = new Nodo<T>(d);
                nuevo->set_next(ant->get_next());
                ant->set_next(nuevo);
            }
        }
        else {
            if ((czo->get_next())->get_next() == NULL) {//al final
                Nodo<T>* nuevo = new Nodo<T>(d);
                nuevo->set_next(czo->get_next());
                czo->set_next(nuevo);

            }
            else this->resto()->addO(d, czo);

        }
    }
}
template <class T>
bool Lista<T>::esta(T d){
	if(this->esvacia()){
		return false;
	}
	if(this->czo->get_dato()==d){
			return true;
		}
		
			return (this->resto())->esta(d);
	
	
	
}
template <class T>
void Lista<T>::borrarDatoO(T d,Nodo<T> *ant){
	if(this->esvacia()){
		cout<<"No ta";
	
}
	else{
		if(this->cabeza()==d){
			if(ant==NULL){
			this->borrar();
		}
		else{
           ant->set_next(czo->getnext())
		   delete czo;			
		
}}
	else{
		if((czo->get_next())==NULL){
			ant->set_next(NULL);
		}
		else{
			this->resto()->borrarDatoO(d,czo);
		}
	}}}



