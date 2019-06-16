#include<cstdio>
using namespace std;
int n,m,a,b,c,pos,red,d[100010];
int lowbit(int a)
{
	return a&(-a);
}
void add(int a,int num)
{
	while(a)
	{
		d[a]+=num;
		a-=lowbit(a);
	}
}
int answer(int a)
{
	int ans=0;
	while(a<=n)
	{
		ans+=d[a];
		a+=lowbit(a);
	}
	return ans;
}
int main()
{
	freopen("10727.in","r",stdin);
	freopen("10727.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&pos);
		if(pos==0)
		{
			scanf("%d%d%d",&a,&b,&c);
			add(a-1,-c);
			add(b,c);
		}
		else
		{
			scanf("%d",&a);
			printf("%d\n",answer(a));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
