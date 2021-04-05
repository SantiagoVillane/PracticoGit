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
       void borrarD(T d, Nodo<T>* ant);
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
    bool esta(T d);// detecta si d esta en la lista
    void borrarDato(T d) { borrarD(d, NULL); }//borra el nodo que contiene d
    void borrar(void); //borra la cabeza
    void borrar_last();//borra el ultimo
    void concat(Lista<T>* l1);// le transfiere los datos de l1 a this
    Lista<T>* copy(void);// hace una copia de la lista
    void tomar(int n);//deja "vivos" los n primeros nodos y borra el resto
    void addOrdenado(T d) { addO(d, NULL); }; //sumar nodos a la lista Ordenados de menor a MAYOR

	Lista <T> *insertar(T d,int n=0);
	Lista<T> final(int n);
};
template <class T> Lista<T> Lista<T>::final(int n){
	for(int i=0;i<n;i++){
		this->borrar();
	}
}

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

template <class T> Lista<T>* Lista<T>::insertar(T d,int n){
	
	Lista<T>* j = new Lista();
    j->concat(this);
	this->final(n);
	this->add(d);
	j->tomar(n);
	this->concat(j);
	return this;
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
    Nodo<T>* aux;
    aux = czo;
    while (aux->get_next() != NULL) {
        cout << aux->get_dato() << endl;
        aux = aux->get_next();
    }
}

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

template <class T> bool Lista<T>::esta(T d)
{// busca d en la lista
    if (this->esvacia()) return false;
    if (this->cabeza() == d) return true;
    
    return this->resto()->esta(d);    
}

template <class T>
void Lista<T>::borrarD(T d, Nodo<T>* ant)
{
    if (!this->esvacia()) {
        if (d == this->cabeza()) {
            if (ant == NULL) {//al principio
                this->borrar();
            }
            else {//entre medio
                ant->set_next(czo->get_next());
                delete czo;
            }
        }
        else  this->resto()->borrarD(d, czo);

    }
}

template <class T> class Pila:public Lista<T>{
      public:
             Pila(){Lista<T>();};
             void apilar(T d){this->add(d);};
             T tope(void){return this->cabeza();};
             void desapilar(void){this->borrar();};
             bool pilavacia(){return this->esvacia();};
};                  
template <class T> class pila{
	private:
	
			T d[100];
			int p;
	
	public: 
	
			Pila(){p=-1;};
			void apilar(T x){d[p++]=x;};
			T tope(void){return d[p];};
			void desapilar(){p--;};
			bool pilavacia(){return p==-1;};
		};
		
template <class T> class Cola:public Lista<T>{
	public:
			
			Cola(){Lista<T>();}
			
			void encolar(T d){this->insertar(d,this->size());};
			
			T tope(){return this->cabeza();};
			
			void descolar(){this->borrar_last();};			
			
			bool colavacia(){return this->esvacia();};
								
							};
							
template <class T> class cola{
	private:
			T d[100];
			
	public:
		int p;
			int u;
			cola(){p=100; u=100;};
			
			void encolar(T x){
			if(u!=0){
			u--;
			d[u]=x;}
			else if((u==0) && (p=100)){
				cout<<"Llena"<<endl;
				}
				else if(u-1==p){
					cout<<"Llena"<<endl;
				}
				else{
					u=100;
					u--;
					d[u]=x;
				}};	
			
			T tope(){return d[u];};
			
			
			void descolar(){
				if(p!=0 && p!=u){
				p--;
				d[p]=NULL;
				}
				else if(p==u){
					cout<<"No hay mas nada bro"<<endl;
				}
				else{
					p=100;
					p--;
					d[p]=NULL;
				}};
			
			bool colavacia(){
			if(p==u){
				return 1;
			}else{
				return 0;
			}};
			
			
			};
	
	
	
	
	
	
	
	
/*void balance(string a){
	 int Ca=0;int Pa=0;int La=0;int Cc=0;int Pc=0;int Lc=0;  
   for(int i=0;(i<a.length());i++){
          if(a.at(i)=='['){Ca++;}
		  else if(a.at(i)=='('){Pa++;}
		  else if(a.at(i)=='{'){La++;}
  			else if(a.at(i)==']'){Cc++;}
  			else if(a.at(i)==')'){Pc++;}
  			else if(a.at(i)=='}'){Lc++;}
  }
	   if(Pa==Pc&&Ca==Cc&&La==Lc){
	   	cout<<"Balanciado";
	   }
	   	else{
	   		cout<<"Desbalanceado";
		   }
}  
*/
int balance(string cadena){

    Pila<char>* p = new Pila<char>();
    int error = 0;

    for (int i = 0; (i < cadena.length()) && (!error); i++) {

        if (cadena.at(i) == '{') p->apilar('{');

        if (cadena.at(i) == '[') p->apilar('[');

        if (cadena.at(i) == '(') p->apilar('(');



        if (cadena.at(i) == '}') {

            if (p->pilavacia()) error = 1;

            else

                if (p->tope() != '{') error = 1;

                else p->desapilar();

        }

        if (cadena.at(i) == ']') {

            if (p->pilavacia()) error = 1;

            else

                if (p->tope() != '[') error = 1;

                else p->desapilar();

        }

        if (cadena.at(i) == ')') {

            if (p->pilavacia()) error = 1;

            else

                if (p->tope() != '(') error = 1;

                else p->desapilar();

        }

    }//fin for i  

    if ((!error) && p->pilavacia())cout << endl << "TOdo OK";

    else cout << endl << "ERROR";
}

int main()
{
	cola<int>* c= new cola<int>();
	c->encolar(1); c->encolar(2); c->encolar(3);c->encolar(4);

	cout<<c->tope()<<c->u;
	c->descolar();
	c->descolar();
	c->descolar();
	c->descolar();
	c->descolar();
	c->descolar();

	cout<<"    "<<c->tope()<<c->u<<endl;
	
	
	
	
	
	
	
	
	
   /* Pila<string> *p= new Pila<string>();
  p->apilar("10");  p->apilar("11");
  p->apilar("12");  p->apilar("13");
  if (!p->pilavacia()) cout<<p->tope()<<endl;
  if (!p->pilavacia())p->desapilar();
  if (!p->pilavacia())cout<<p->tope()<<endl;
  if (!p->pilavacia())p->desapilar();
  if (!p->pilavacia())cout<<p->tope()<<endl;
  
// ingresar una cadena que contendra ([{ y )]}
// el programa debera determinar si el "balance" de los ([{ es correcto
// errores posibles
// hay mas ((( que )) o [[[ que ] o { que }}}
// que no se corresponda un cerrado con el ultimo abierto {  ]


  string cadena;
  cout<<endl<<"Ingrese cadena= "; cin>>cadena;
  //int error=0;
  //for(int i=0;(i<cadena.length());i++){
   //       cout<<cadena.at(i)<<endl;
	balance(cadena);  
  */
  }

    /*cout << endl << endl;
    system("PAUSE");
    return EXIT_SUCCESS;

}*/

