#include <iostream>
#include <cstdio>
using namespace std;
int a[2010];
int main ()
{
	int n,stg;
	cin>>n;
	for (int i=1;i<=n;i++) 
		cin>>a[i];cout<<endl;
	for (int i=1;i<=n-1;i++)
		{
			for (int j=i+1;j<=n;j++)
					if (a[i]>a[j])
						{
							stg=a[j];
							a[j]=a[i];
							a[i]=stg;
						}
		}
	for (int i=1;i<=n;i++)
		cout<<a[i]<<endl;
	return 0;
}
