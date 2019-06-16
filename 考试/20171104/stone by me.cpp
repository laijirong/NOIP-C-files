//二分,枚举//跳石头
#include <cstdio>
#include <algorithm>
using namespace std;
int l,n,m,ans,d[50010],ll,rr,mid,s,sum;
int bin (int a)
{
	s=0;sum=0;//s 当前石头里起点的距离，sum 移动石头的数目 
	for (int i=1;i<=n+1;i++)
		{
			if (d[i]-s<a)
				sum++;
			else s=d[i];
		}
	if (sum>m) return 0;
	return 1;
}
int main ()
{
//	freopen ("stone.in","r",stdin);
//	freopen ("stone.out","w",stdout);
	scanf("%d%d%d",&l,&n,&m);
	for (int i=1; i<=n; i++)
		scanf("%d",&d[i]);
	ll=0;rr=d[n+1]=l;
	while (ll<=rr)
	{
		mid=(ll+rr)/2;
		if (bin(mid))
			{
				ll=mid+1;
				ans=mid;
			}
		else rr=mid-1; 
	}
	printf("%d",ans);
	return 0;
}