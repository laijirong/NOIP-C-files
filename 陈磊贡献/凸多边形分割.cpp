#include<cstdio>
#define mo 1234567
using namespace std;
int n;
long long dp[210];
int main()
{
	freopen("10076.in","r",stdin);
	freopen("10076.out","w",stdout);
	scanf("%d",&n);
	dp[2]=dp[3]=1;
	for(int i=4;i<=n;i++)
	{
		for(int j=2;j<i;j++)
		{
			dp[i]+=((dp[j]%mo)*(dp[i-j+1]%mo)%mo);
			dp[i]%=mo;
		}
		dp[i]%=mo;
	}
	dp[1]=dp[2]=0;
	printf("%d\n",dp[n]%mo);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
