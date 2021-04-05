#include <cstdlib>
#include <iostream>

using namespace std;

void impre(int v[],int n);


int main(int argc, char *argv[])
{   int v[6]={17,15,-8,30,5,-2};
    char nom[]={"Juan Perez"};
    
    cout<<"impre vector"<<endl; impre(v,5);    
   
    cout<<endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
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


