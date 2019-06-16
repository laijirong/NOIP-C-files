#include <iostream>
#include <cstdio>
using namespace std;
int a[8020];
int main ()
{
	int n;
	float s;
	cin>>n;
	for (int i=1;i<=n;i++)
		{
			cin>>s;
			a[int (s*10)]=1;
		}
	for (int i=0;i<=8000;i+=5)
		if (a[i]!=0) 
			printf("%.1f ",float (i/10.0));
	return 0;	
}
