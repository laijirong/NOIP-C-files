#include<cstdio>
#include<iostream>
using namespace std;
int n,red[310],zy[310],dp[310][310];
int main()
{
	freopen("10069.in","r",stdin);
	freopen("10069.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&red[i]);
		zy[i]=zy[i-1]+red[i];
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(i!=j) dp[i][j]=0x7fffffff/2;
	
	for(int i=n;i>=1;i--)
	for(int j=i+1;j<=n;j++)
	for(int k=i;k<j;k++)
	dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+zy[j]-zy[i-1]);
	
	printf("%d\n",dp[1][n]);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
