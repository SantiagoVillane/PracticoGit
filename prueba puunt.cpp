#include <cstdlib>
#include <iostream>

using namespace std;
main(){
	int x=1;
	int *p;
	p=&x;
	
	cout<<x<<"    "<<p<<"    "<<*p<<"     "<<&p<<"     "<<&x<<endl<<endl;
	
	int a[5];
	a[0]=1;
	int *o;
	o=&a[0];
	o[1]=2;
	cout<<a[0]<<a[1]<<"    "<<o[0]<<"    "<<*(o+1);
	
	
	
	
	
}
