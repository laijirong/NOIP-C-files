#include<cstdio>
using namespace std;
int n,m,pos,a,b,c;
long long ans1,ans2,d1[100010],d2[100010];
int lowbit(int a)
{
	return a&(-a);
}
void add1(int red,int num)
{
	while(red<=n)
	{
		d1[red]+=num;
		red+=lowbit(red);
	}
}
void add2(int red,int num)
{
	while(red<=n)
	{
		d2[red]+=num;
		red+=lowbit(red);
	}
}
long long answer(long long *red,int zy)
{
	long long ans=0ll;
	while(zy)
	{
		ans+=red[zy];
		zy-=lowbit(zy);
	}
	return ans;
}
int main()
{
	freopen("11227.in","r",stdin);
	freopen("11227.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int mm=1;mm<=m;mm++)
	{
		scanf("%d",&pos);
		if(pos==0)
		{
			scanf("%d%d%d",&a,&b,&c);
			add1(a,c);
			add1(b+1,-c);
			add2(a,c*a);
			add2(b+1,-c*(b+1));
		}
		else
		{
			scanf("%d%d",&a,&b);
			ans1=a*answer(d1,a-1)-answer(d2,a-1);
			ans2=(b+1)*answer(d1,b)-answer(d2,b);
			printf("%lld\n",ans2-ans1);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
