#include<iostream>
using namespace std;
int main () 
{
	int m,k,n=0;
	cin>>m>>k;
	if (m%19==0)
		{
			while (m>1)
				{
					if (m%10==3)
						
						n++;
						m=m/10;
						
				}	
				if (n==k)
					cout<<"yes";
				else cout<<"no";
				
		}
	else cout<<"no";
	return 0;
	
}
