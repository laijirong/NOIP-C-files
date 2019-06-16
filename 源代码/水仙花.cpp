#include <iostream>
#include<math.h>
using namespace std;
int main ()
{
	long long a,b,c,d,n;
	d=a*100+b*10+c;
	
	while ((n>99)&&(n<1000))
		{
			if (d==pow(a,3)+pow(b,3)+pow(c,3))
			cout<<d<<endl;
			n++;
		}
		cout<<a*100+b*10+c<<" ";
	return 0;
} 
