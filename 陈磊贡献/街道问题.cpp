#include<cstdio>
#include<iostream>
using namespace std;
int n,m,x,y,map[210][210],dp[210][210];
int main()
{
	freopen("10078.in","r",stdin);
	freopen("10078.out","w",stdout);
	scanf("%d%d",&n,&m);
	while(scanf("%d%d",&x,&y)==2)
	scanf("%d",&map[x][y]);
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	dp[i][j]=max(dp[i-1][j]+map[i][j],dp[i][j-1]+map[i][j]);
	
	printf("%d\n",dp[n][m]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
