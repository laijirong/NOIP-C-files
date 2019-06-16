#include <cstdio>
#include <algorithm>
using namespace std;
int data[2020],dp[2020],ans,n;
int main ()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&data[i]);
		dp[i]=1;
	}
	for(int i=1;i<=n;i++)
		for (int j=1;j<i;j++)
			if (data[i]>=data[j])
					dp[i]=max(dp[i],dp[j]+1);
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[i]);
	printf("%d",ans);
	return 0;
}
