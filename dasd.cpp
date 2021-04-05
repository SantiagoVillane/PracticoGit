#include <cstdlib>
#include <iostream>

using namespace std;

void impre(int v[],int n);
int suma(int v[],int n);
int mayor(int v[],int n);
int mult(int a, int b);
void hanoi(char a,char c,char b,int n);
int main(int argc, char *argv[])
{   
    int v[6]={17,15,-8,30,5,-2};
    
	cout<<"impre vector"<<endl; impre(v,5);    
   cout<<"la suma de los comp es: "<<endl<<suma(v,5)<<endl;
    cout<<"El mayor es: "<<endl<<mayor(v,5)<<endl;    
    int a=7, b=4;
	cout<<"La multiplicacion de 2 enteros :"<<endl<<a<<"*"<<b<<"="<<mult(a,b)<<endl;	
    hanoi('a','c','b',4);	
		
		system("PAUSE");
    return EXIT_SUCCESS;
}
void hanoi(char a, char c, char b, int n)
{
    if (n > 0) {
        hanoi(a, b, c, n - 1);
        cout << "Mover " << n << " desde " << a << " hasta " << c << endl;
        hanoi(b, c, a, n - 1);
    }

}


void impre(int v[],int n)
{   if(n==0)cout<<v[n]<<endl;
    else{ 
          //cout<<"estoy yendo";
          //cout<<v[n]<<endl;
          impre(v,n-1);
          //cout<<"estoy retornando"<<endl;
          cout<<v[n]<<endl;
          
          
    } 
}

int suma(int v[],int n)
{
	if (n == 0) return v[n];
	else {
		return v[n] + suma(v, n-1);
	}
}
int mayor(int v[],int n){
	if(n==0){
		return v[n];
	}else{
		int a=mayor(v,n-1);
		if(a<v[n])
		{
		return v[n];
		}
			return a;
	  	}
}
int mult(int a, int b){
	//if(b==0) return 0;
	if(b==0) return 0;
	else{
		return a+mult(a,b-1);
	}
}


