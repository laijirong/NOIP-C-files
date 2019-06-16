#include <iostream>
using namespace std;
int a[100020];
int main ()
{
	int n,swap;
 	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n-1;i++)
			for (int j=1;j<=n;j++)
			{
				if (a[j]>a[j+1]);
				else{
						swap=a[j];
						a[j]=a[j+1];
						a[j+1]=swap;
					}
			}
	for (int i=n;i>=1;i--)
	 	cout<<a[i]<<" ";
	return 0;
}
