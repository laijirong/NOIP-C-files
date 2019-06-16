#include <iostream>
//#include <cstdlib>
//#include<cstdio>
using namespace std;
int a[120];
int main ()
{
	int n;cin>>n;
	//freopen("out.txt","w",stdout);
	for (int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=100;j++)
	  		if(j%i==0) 
	   		{
	   			if(a[j]==1) a[j]=0;
	   			else a[j]=1; 	
	   		}
	}
	for(int i=1;i<=100;i++)
	 //printf("%d\n",a[i]);
	 if (a[i]==0) cout<<"¹Ø"<<endl;
	 else cout<<"¿ª"<<endl;
	return 0;
}
