// constructing bitsets
#include <iostream>
#include <string>
#include <bitset>
using namespace std;
class xx{
      public:
      bitset<7> M[7];
      void impre();
      //definiendo and de conjuntos
      friend xx operator &(xx c1, xx c2);
      
      friend xx operator |(xx c1, xx c2); //operador or de conjunto
      
	  int contar(); // cuenta los 1
      
	  friend xx operator <<(xx c1,int n); //shift a la izquierda
      
	  friend bool operator ==(xx c1,xx c2);// compara si son iguales
      
};
//--------------------------------------------------------------------------------------------------------
 xx operator |(xx c1, xx c2){
 	xx c3;
 		for(int i=0;i<7;i++){
            c3.M[i] = c1.M[i]|c2.M[i];
		}
     return c3;
 }
 
 int xx :: contar(){
 	int p=0;
 	for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if(this->M[i][j]==1){
            	p++;
			}	
		}
 	}
 	return p;
}
xx operator <<(xx c1,int n){
	xx c3;
 	
	for(int i=0;i<7;i++){
        c3.M[i] = (c1.M[i]<<=n);
    }
    
	return c3;
}
 
bool operator ==(xx c1,xx c2){
	int p=0;
 	for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if(c1.M[i][j]==c2.M[i][j]){
            	p++;
			}	
		}
 	}
 	if(p==7*7){
 		return true;
	}
	else{
		return false;
	} 
}
 
//--------------------------------------------------------------------------------------------------------

xx operator &(xx c1, xx c2){ 
     xx c3;
     for(int i=0;i<7;i++)
            c3.M[i] = c1.M[i]&c2.M[i];
     return c3;
}
void xx::impre(){
     int i,j;
     for(i=0;i<7;i++){
                      cout<<endl;
                      for(j=0;j<7;j++)                 
                          cout<<this->M[i][j]<<"  ";
}
}
                     
int main ()
{  xx a,b,c;
   a.M[0][3]=1;
   a.M[3][4]=1;
   b=a;
   //cout<<(b==a);
   b.M[1].set();
   c=a&b;
   c=a|b;
   
   a.impre();
   cout<<endl<<"----------------------"<<endl;
   operator <<(a,3).impre();
   /*
   cout<<endl<<"----------------------"<<endl;
   b.impre();
   cout<<endl<<"----------------------"<<endl;
   c.impre();
   */
   //cout<<b.contar();
   //cout<<(c==a);
   //c.impre();
   
   
  cout<<endl<<endl;
  system("PAUSE");
  return 0;
}
