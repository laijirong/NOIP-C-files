#include<cstdio>
using namespace std;
int n,d[1010];
void change(int &a,int &b)
{
	int t=a;a=b;b=t;
}
void inse(int a)
{
	while(a!=1&&(d[a]>d[a/2]))
	{
		change(d[a],d[a/2]);
		a/=2;
	}
}
void dele(int a)
{
	if(a>=n) return ;
	int son=a*2+1;
	if(a*2<n&&d[a*2]>d[a*2+1])
	son=a*2;
	if(a*2==n) son=a*2;
	if(d[a]<d[son])
	{
		change(d[a],d[son]);
		dele(son);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&d[i]);
	for(int i=1;i<=n;i++)
	inse(i);
	{
		d[1]=0;
		change(d[1],d[n]);
		n--;
		dele(1);
	}
	for(int i=1;i<=n;i++)
	printf("%d %d\n",i,d[i]);
	return 0;
}
