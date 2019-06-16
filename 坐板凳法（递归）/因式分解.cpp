#include<cstdio>
#include<cmath>
using namespace std;
int n;
int data[1000100];
void out(int a)
{
	if(data[a]!=n)
	{
	printf("%d=",n);
	for(int i=1;i<=a-1;i++)
	  printf("%d*",data[i]);
	printf("%d\n",data[a]);
    }
}
void search(int a,int b,int c)
{
	for(int i=c;i<=b;i++)
	if(b%i==0)
	{
		data[a]=i;
		if(b==i) out(a);
		else search(a+1,b/i,i);
	}
}
int main()
{
	//freopen("fh.in","r",stdin);
	//freopen("fh.out","w",stdout);
	scanf("%d",&n);
	printf("%d=1*%d\n",n,n);
	search(1,n,2);
	//fclose(stdout);
	return 0;
}
