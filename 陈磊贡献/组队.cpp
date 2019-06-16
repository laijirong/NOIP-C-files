#include<cstdio>
using namespace std;
int n,m,pos,sum,d1[400010],d2[400010],d3[400010];
int main()
{
	freopen("10095.in","r",stdin);
	freopen("10095.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		d1[m]=i;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		d2[m]=i;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		d3[m]=i;
	}
	for(int i=1;i<=n;i++)
	{
		pos=0;
		for(int j=1;j<=n;j++)
		if(d1[j]<d1[i]&&d2[j]<d2[i]&&d3[j]<d3[i])
		{
			pos=1;
			break ;
		}
		if(!pos) sum++;
	}
	printf("%d\n",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
