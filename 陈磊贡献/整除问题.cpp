#include<cstdio>
#define mo 1234567
using namespace std;
int n,m,j_,ans,red[1010],dp[1010][1010];
int main()
{
	freopen("10077.in","r",stdin);
	freopen("10077.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&red[i]);
		red[i]%=m;
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][red[i]]++;
		for(int j=0;j<m;j++)
		{
			j_=(j+m-red[i])%m;
			dp[i][j]=(dp[i-1][j_]+dp[i-1][j]+dp[i][j])%mo;
		}
	}
	printf("%d\n",dp[n][0]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
