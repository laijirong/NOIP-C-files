#include <iostream>
using namespace std;
int main ()
{
	int n,au_t=0,ag_t=0,cu_t=0;
	cin>>n;
	for (int i=1;i<=n;i++)
		{
			int au,ag,cu;
			cin>>au>>ag>>cu;
			au_t+=au;
			ag_t+=ag;
			cu_t+=cu;
		}
		
		cout<<au_t<<" "<<ag_t<<" "<<cu_t<<" "<<au_t+ag_t+cu_t;
	return 0;
} 
