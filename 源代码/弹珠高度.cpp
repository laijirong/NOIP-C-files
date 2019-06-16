#include<iostream>
using namespace std;
int main()
{
	long long n,a;
	cin>>n;
	while (n>=1)
	{
		a=n%10;
		n=n/10;
		cout<<a<<" ";
	}
	return 0;
}

