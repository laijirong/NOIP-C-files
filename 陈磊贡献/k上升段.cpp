#include<cstdio>
using namespace std;
int n,k;
long long dp[25][25];
int main()
{
	freopen("10100.in","r",stdin);
	freopen("10100.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) dp[i][1]=1;
	for(int i=1;i<=n;i++)
	for(int j=2;j<=k&&j<=n;j++)
	dp[i][j]=dp[i-1][j]*j+dp[i-1][j-1]*(i-j+1);
	
	printf("%lld\n",dp[n][k]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
