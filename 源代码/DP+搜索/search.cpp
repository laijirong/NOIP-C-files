//因式分解
#include <cstdio>
#include<cmath>
using namespace std;
int n,data[1000000];
bool is_prime(int a)
{
	if(a==2) return 1;
	for(int i=3;i<=sqrt(a);i++)
		if(a%i==0) return 0;
	return 1;
}
void out(int a)
{
	if (a==1) return;
	printf("%d=",n);
	for (int i=1;i<a;i++)
		printf("%d*",data[i]);
	printf("%d\n",data[a]);
	return;
}
void search (int a,int b,int c)
{
	for (int i=c;i<=b;i++)
		if (b%i==0)
			{
				data[a]=i;
				if (b==i)
					out(a);
				else
					search(a+1,b/i,i);
			}
}
int main ()
{
	scanf("%d",&n);
	if(is_prime(n))
	{
		printf("%d=1*",n);
		printf("%d\n",n);
		return 0;
	}
	else
	{
		printf("%d=1*",n);
		printf("%d\n",n);
		search(1,n,2);
		return 0;
	}
	
}
