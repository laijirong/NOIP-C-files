#include  <cstdio>
#include<iostream>
#include<cstdlib>
#include<math.h>
using namespace std;
int main ()
{
	double a,b,c,x1,x2;
	cin>>a>>b>>c;
	x1=(-1*b+sqrt(b*b-4*a*c))/(2*a);
	x2=(-1*b-sqrt(b*b-4*a*c))/(2*a);
	a!=0;
	if (x1>=x2)
	 {
	 	if (x1>x2)
	 		cout<<"x1="<<x1<<"x2= "<<x2;
	 	else 
	 		cout<<"x1=x2= "<<x1;
	 }
	 else 	cout<<"x1= "<<x1<<"x2= "<<x2;
	system("pause");
	return 0;
}

