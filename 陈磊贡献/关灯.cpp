#include<iostream>
#include<cstdio>
using namespace std;
int n,v,sum;
int d[1010],w[1010],dp[1010][1010][2],tw[1010];
int main()
{
	scanf("%d%d",&n,&v);
	for(int i=1;i<=n;i++)
	scanf("%d%d",&d[i],&w[i]);
	for(int i=1;i<=n;i++)
	tw[i]=tw[i-1]+w[i];
	
	dp[v][v][0]=0;
	dp[v][v][1]=0;
	for(int i=v+1;i<=n;i++)
	{
		dp[v][i][1]=dp[v][i-1][1]+(tw[n]-tw[i-1]+tw[v]-w[v])*(d[i]-d[i-1]);
		dp[v][i][0]=dp[v][i][1]+(tw[n]-tw[i]+tw[v]-w[v])*(d[i]-d[v]);
	}
		
	for(int i=v-1;i>=1;i--)
	{
		dp[i][v][0]=dp[i+1][v][0]+(tw[n]-tw[v]+tw[i+1]-w[i+1])*(d[i+1]-d[i]);
		dp[i][v][1]=dp[i][v][0]+(tw[n]-tw[v]+tw[i]-w[i])*(d[v]-d[i]);
	}
	  
	for(int i=v-1;i>=1;i--)
	for(int j=v+1;j<=n;j++)
	{
		dp[i][j][0]=min(dp[i+1][j][0]+(tw[n]-tw[j]+tw[i])*(d[i+1]-d[i]),dp[i+1][j][1]+(tw[n]-tw[j]+tw[i])*(d[j]-d[i]));
		dp[i][j][1]=min(dp[i][j-1][1]+(tw[n]-tw[j-1]+tw[i-1])*(d[j]-d[j-1]),dp[i][j-1][0]+(tw[n]-tw[j-1]+tw[i-1])*(d[j]-d[i]));
	}
	 
	printf("%d",min(dp[1][n][0],dp[1][n][1]));
	return 0;
}
