#include<cstdio>
#include<algorithm>
using namespace std;
struct point
{
	int val1,val2;
	bool operator <(const point b) const
	{
		if(val1==b.val1) return val2<b.val2;
		return val1<b.val1;
	}
}G[10];
int main()
{
	for(int i=1;i<=7;i++)
		scanf("%d%d",&G[i].val1,&G[i].val2);
	sort(G+1,G+1+7);
	for(int i=1;i<=7;i++)
		printf("%d %d\n",G[i].val1,G[i].val2);
}
