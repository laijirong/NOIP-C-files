#include<cstdio>
using namespace std;
int n,m,a,b,c,d[100010],ans,ans1,ans2;
int lowbit(int a)
{
	return a&(-a);
}
int main()
{
	freopen("10726.in","r",stdin);
	freopen("10726.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&c,&a,&b);
		if(c==0)
		while(a<=n)
		{
			d[a]+=b;
			a+=lowbit(a);
		}
		else
		{
			ans1=ans2=ans=0;a--;
			while(a)
			{
				ans1+=d[a];
				a-=lowbit(a);
			}
			while(b)
			{
				ans2+=d[b];
				b-=lowbit(b);
			}
			ans=ans2-ans1;
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
