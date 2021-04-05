#include <iostream>	
#include <sstream>	

using namespace std;

int fact(int a){
	if(a>1){
		return a*fact(a-1);
	}else{
	
		return 1;
	}
}
int cociente1(int endo, int sor){
	if(endo<sor){
		return 0;
	}else{
		return 1+cociente1(endo-sor,sor);
		}
}
int cociente2(int endo, int sor, int *coc){
	if(endo<sor){
		return endo;
	}else{
		*coc=*coc+1;
		return cociente2(endo-sor,sor,coc);
		}
}

int fibonacci(int f){
	if(f<3){
		return 1;
	}else{
		return fibonacci(f-1)+fibonacci(f-2);
	}
}

//TAREA
int fiboit(int f){
	int a=0;
	int b=1;
	int c;
	for(int i=1;i<f;i++){
		c=a+b;
		a=b;
		b=c;
	}
	return c;
}
long int fiboit2(long int f,long int i=3,long int u=1,long int p=1){
	if(f==i){
		return u+p;
	}
	else if(f<3){
		return 1;
	}
	else{
	return fiboit2(f,i+1,u+p,u);
	}
}


int main(){
	//int endo,sor;
	//int a;
	//cin>>endo>>sor;
	//int c=0;
	//int resto=cociente2(endo,sor,&c);
	//cout<<"cociente: "<<c<<" resto: "<<resto;
//	cout<<cociente(endo,sor);
	//cin>>a;
	//cout<<fact(a);
	long int f;
	cin>>f;
//	cout<<fibonacci(f)<<endl;
	cout<<fiboit(f)<<endl;
	//cout<<fiboit2(f);
}

