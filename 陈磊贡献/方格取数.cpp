#include<cstdio>
using namespace std;
int n,x,y,ans,map[410][410],dp[410][410][20];
int max(int a,int b,int c,int d)
{
	if(a<b) a=b;
	if(a<c) a=c;
	if(a<d) a=d;
	return a;
}
int main()
{
	freopen("10079.in","r",stdin);
	freopen("10079.out","w",stdout);
	scanf("%d",&n);
	while(scanf("%d%d",&x,&y)==2)
	scanf("%d",&map[x][y]);
	for(int k=2;k<=2*n;k++)
	for(int i=1;i<k;i++)
	for(int j=1;j<k;j++)
	{
		dp[i][j][k%10]=max	(
								dp[i-1][j][(k-1)%10]+map[i][k-i]+map[j][k-j],
								dp[i][j-1][(k-1)%10]+map[i][k-i]+map[j][k-j],
								dp[i][j]  [(k-1)%10]+map[i][k-i]+map[j][k-j],
								dp[i-1][j-1][(k-1)%10]+map[i][k-i]+map[j][k-j]
							);
		if(i==j) dp[i][j][k%10]-=map[i][k-i];
	}
	printf("%d\n",dp[n][n][(2*n)%10]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
