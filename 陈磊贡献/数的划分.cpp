#include<cstdio>
#include<iostream>
using namespace std;
int n,k,dp[10][210];
int main()
{
	freopen("10199.in","r",stdin);
	freopen("10199.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<=n;i++)
	dp[1][i]=1;
	
	for(int i=2;i<=k;i++)
	for(int j=0;j<=n-k;j++)
	if(j>=i)	dp[i][j]=dp[i-1][j]+dp[i][j-i];
	else	    dp[i][j]=dp[i-1][j];
	
	printf("%d\n",dp[k][n-k]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
