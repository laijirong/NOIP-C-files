#include<cstdio>
using namespace std;
int n,m,ans,map[2010][2010],dp[2010][2010];
int min(int a,int b,int c)
{
	if(a>b) a=b;
	if(a>c) a=c;
	return a;
}
int main()
{
	freopen("11338.in","r",stdin);
	freopen("11338.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		scanf("%d",&map[i][j]);
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(map[i][j])
	dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(dp[i][j]>ans) ans=dp[i][j];
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
