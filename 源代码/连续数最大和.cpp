#include<cstdio>
#include<algorithm>
using namespace std;
int n,sum[100010],minsum[100010],ans=-999999;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];
		minsum[i]=min(sum[i],minsum[i-1]);
		ans=max(ans,sum[i]-minsum[i-1]);
	}
	printf("%d\n",ans);
	return 0;
}
