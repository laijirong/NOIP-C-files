#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long n,a,b=0;
	cin>>n;
	while ((n>=1)||(n<=-1))//((-1000000000<=n)&&(n<=1000000000))
	{
		a=n%10;
		b=b*10+a;
		n=n/10;
		
		//system("pause");
	}
	cout<<b;	
	return 0;
}
