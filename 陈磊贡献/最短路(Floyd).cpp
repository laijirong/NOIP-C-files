#include<iostream>
#include<cstdio>
using namespace std;
int n,sta,end;
int dp[2010][2010];
int main()
{
	int x=0,y=0,z=0;
	freopen("11269.in","r",stdin);
	freopen("11269.out","w",stdout);
	scanf("%d%d%d",&n,&sta,&end);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(i!=j)	dp[i][j]=1000000000;
	
	while(scanf("%d%d%d",&x,&y,&z)==3)
	dp[x][y]=dp[y][x]=z;
	
	if(x==0&&y==0&&z==0)
	{
		printf("0\n");
		return 0;
	}
	
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	
	printf("%d\n",dp[sta][end]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
