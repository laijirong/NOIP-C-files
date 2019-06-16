#include<iostream>
#include<cstdio>
using namespace std;
int n,s;
double answer,dp[3010][1010];
struct ss
{
	int v;
	double val;
} red[3010];
int main()
{
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)
	scanf("%d%lf",&red[i].v,&red[i].val);
	
	for(int i=1;i<=n;i++)
	for(int j=red[i].v;j<=s;j++)
	dp[i][j]=max(dp[i-1][j],dp[i-1][j-red[i].v]+red[i].val);
	
	printf("%.2lf ",dp[n][s]);
	return 0;
}
