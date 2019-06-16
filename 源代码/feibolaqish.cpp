#include<iostream>
using namespace std;
int main()
{
	int a=1,b=1,c=0,n;
	cin>>n;
	for(int i=3;i<=n;i++)
		{
			c=a+b;a=b;b=c;
			
		}
		cout<<c;
	return 0;
}
