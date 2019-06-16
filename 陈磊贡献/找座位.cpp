#include<map>
#include<iostream>
using namespace std;
map<int,int> red;
int main()
{
	int n,t;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		red[t]=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		cout<<red[t]<<" ";
	}
	return 0;
}
