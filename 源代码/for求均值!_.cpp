#include <iostream>
using namespace std;
int main ()
{
	int n,delta,x,min=10001,max=-1;
	cin>>n;
	for (int i=1;i<n;i++)
		{
			cin>>x;
			if (max<x)
				max=x;
			if (min>x)
				min=x;
		}
		delta=max-min;
		printf("%d",delta);
	return 0;
} 
