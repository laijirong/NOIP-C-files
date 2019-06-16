#include<cstdio>
#include<iostream>
using namespace std;
int deep,n,lifetime=10,dp[110];
struct rubbish
{
	int time,ener,heigh;
} rubb[110],e[110];
void sort(int a,int b)
{
	if(a==b) return ;
	int mid=(a+b)/2;
	sort(a,mid);sort(mid+1,b);
	
	int p1=a,p2=mid+1,p=a;
	while(p1<=mid&&p2<=b)
	if(rubb[p1].time>rubb[p2].time) e[p++]=rubb[p2++];
	else							e[p++]=rubb[p1++];
	
	for(int i=p1;i<=mid;i++)
	e[p++]=rubb[i];
	
	for(int i=p2;i<=b;i++)
	e[p++]=rubb[i];
	
	
	for(int i=a;i<=b;i++)
	rubb[i]=e[i];
}
int main()
{
	freopen("10642.in","r",stdin);
	freopen("10642.out","w",stdout);
	scanf("%d%d",&deep,&n);
	for(int i=1;i<=n;i++)
	scanf("%d%d%d",&rubb[i].time,&rubb[i].ener,&rubb[i].heigh);
	sort(1,n);
	dp[0]=10;
	for(int i=1;i<=n;i++)
	for(int j=deep;j>=0;j--)
	if(dp[j]>=rubb[i].time)
	{
		if(j+rubb[i].heigh>=deep)
		{
			printf("%d\n",rubb[i].time);
			return 0;
		}
		dp[j+rubb[i].heigh]=max(dp[j+rubb[i].heigh],dp[j]);
		dp[j]+=rubb[i].ener;
	}
	printf("%d\n",dp[0]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
