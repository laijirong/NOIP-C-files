#include <iostream>
using namespace std;
int main ()
{
	int n,au,cu,ag,x=0,y=0,z=0,all=0;
	cin>>n;
	for (int i=1;i<=n;i++)
		{
			cin>>au>>ag>>cu;
			x+=au;
			y+=ag;
			z+=cu;
		}
		all=x+y+z;
		cout<<x<<" "<<y<<" "<<z<<" "<<all;
	return 0;
} 
