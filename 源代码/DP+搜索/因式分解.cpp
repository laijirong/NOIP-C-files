#include<cstdio>
#include<cmath>
using namespace std;
int seat[1000000];
int n;
bool ss(int a)
{
	if(a==2) return 1;
	for(int i=3;i<=sqrt(a);i++)
		if(a%i==0) return 0;
	return 1;
}
void out(int a)
{
	if(a==1) return ;
	
	printf("%d=",n);
	for(int i=1;i<a;i++)
	printf("%d*",seat[i]);
	printf("%d\n",seat[a]);
	
	return;
}
void search(int a,int b,int c)
{
	for(int i=c;i<=b;i++)
	{
		if(b%i==0)
		{
			seat[a]=i;
			if(b==i)
			out(a);
			else
			search(a+1,b/i,i);
		}
	}
}
int main()
{
	scanf("%d",&n);
	if(ss(n))
	{
		printf("%d=1*",n);
		printf("%d\n",n);
		return 0;
	}
	printf("%d=1*%d\n",n,n);
	search(1,n,2);
	return 0;
}
