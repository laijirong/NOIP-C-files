#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int answer,ans[31],seat[31],f[10000];
int dp(int a,int b)
{
	for(int i=1;i<=seat[a]*m;i++)
	f[i]=31;
	
	for(int i=1;i<=a;i++)
	  for(int j=seat[i];j<=seat[a]*m;j++)
		f[j]=min(f[j],f[j-seat[i]]+1);
	
	for(int i=b+1;i<=seat[a]*m;i++)
	if(f[i]>m) return i-1;
	
	return seat[a]*m;
}
void judge(int a)
{
	if(a>answer)
	{
		answer=a;
		for(int i=2;i<=n;i++)
		ans[i]=seat[i];
	}
}
void search(int a,int b)
{
		if(a==n+1)
		{
			judge(b);
			return;
		}
	for(int i=seat[a-1]+1;i<=b+1;i++)
	{
		seat[a]=i;
		search(a+1,dp(a,b));
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	seat[1]=ans[1]=1;
	search(2,m);
	
	printf("%d\n",answer);
	for(int i=1;i<=n;i++)
	printf("%d ",ans[i]);
	return 0;
}
