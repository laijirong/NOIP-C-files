#include<cstdio>
#include<iostream>
using namespace std;
int n,ti,dp[20010];
char p[2010];
struct work
{
	int val,time;
} red[2010];
int main()
{
	freopen("10273.in","r",stdin);
	freopen("10273.out","w",stdout);
	
	scanf("%d%d",&n,&ti);
	for(int i=1;i<=n;i++)
	cin>>red[i].val>>red[i].time>>p[i];
//	scanf("%d%d%c",&red[i].val,&red[i].time,&p[i]);
	
	for(int i=1;i<=n;i++)
	if(p[i]=='A')
	for(int j=ti;j>=red[i].time;j--)
	dp[j]=max(dp[j],dp[j-red[i].time]+red[i].val);
	
	for(int i=1;i<=n;i++)
	if(p[i]=='B')
	for(int j=red[i].time;j<=ti;j++)
	dp[j]=max(dp[j],dp[j-red[i].time]+red[i].val);
	
	printf("%d\n",dp[ti]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
