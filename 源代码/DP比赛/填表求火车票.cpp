#include<cstdio>
#include<algorithm>
using namespace std;
int price[15],cost[100],n,co;
int main ()
{
	for(int i=1;i<=10;i++)
		scanf("%d",&price[i]);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		cost[i]=0x7fffffff;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=10;j++)
			{
				if (i>=j) cost[i]=min(cost[i],cost[i-j]+price[j]);
			}
	printf("%d",cost[n]);
	return 0;
}
