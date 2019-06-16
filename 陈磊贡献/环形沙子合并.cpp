#include<cstdio>
#include<iostream>
using namespace std;
int n,ans,red[610],dp[610][610],zy[610];
int main()
{
	freopen("10072.in","r",stdin);
	freopen("10072.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&red[i]);
		zy[i]=zy[i-1]+red[i];
	}
	for(int i=1;i<n;i++)
	{
		zy[i+n]=zy[i+n-1]+red[i];
		red[i+n]=red[i];
	}
	
	for(int i=1;i<2*n;i++)
	for(int j=1;j<2*n;j++)
	if(i!=j) dp[i][j]=0x7fffffff/4;
	
	for(int i=2*n-1;i>=1;i--)
	for(int j=i+1;j<2*n;j++)
	for(int k=i;k<j;k++)
	dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+zy[j]-zy[i-1]);
	
	ans=0x7fffffff;
	for(int i=1;i<=n;i++)
	ans=min(ans,dp[i][i+n-1]);
	
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
