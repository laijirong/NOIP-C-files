#include<iostream>
using namespace std;
int main () 
{
	int a=1,b=0,c=0,n=100;
	while (a<10)
		{
			a++;
		while (b<10)
			{
				b++;
			while (c<10)
				{
					c++;
					if(a*100+b*10+c==a*a*a+b*b*b+c*c*c)
					cout<<a*100+b*10+c;
				}
			}
		}

	while (n<=999)
		{
		
		a=n/100;
		b=(n-100*a)/10;
		c=n%10;
		
		
			if (a*a*a+b*b*b+c*c*c==n)
			printf("%d\n",n);
			n++;
		}
	n=a*100+b*10+c;
	while (n<1000)
		{
		
			if (n==a*a*a+b*b*b+c*c*c)
			cout<<n<<endl;
			n++;
			cout<<n<<" ";
		}
	
	return 0;
	
}
