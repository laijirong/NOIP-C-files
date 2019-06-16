#include<cstdio>
using namespace std;
int n,m,r,pos,a,b,c,d,ans,zy,red[5010][5010];
int lowbit(int a)
{
	return a&(-a);
}
int main()
{
	freopen("10729.in","r",stdin);
	freopen("10729.out","w",stdout);
	scanf("%d%d%d",&n,&m,&r);
	for(int i=1;i<=r;i++)
	{
		scanf("%d",&pos);
		if(pos==0)
		{
			scanf("%d%d%d",&a,&b,&c);
			for(int x=a;x<=n;x+=lowbit(x))
			for(int y=b;y<=m;y+=lowbit(y))
			red[x][y]+=c;
		}
		else
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			ans=0;
			for(int x=c;x>0;x-=lowbit(x))
			for(int y=d;y>0;y-=lowbit(y))
			ans+=red[x][y];
			
			for(int x=c;x>0;x-=lowbit(x))
			for(int y=b-1;y>0;y-=lowbit(y))
			ans-=red[x][y];
			
			for(int x=a-1;x>0;x-=lowbit(x))
			for(int y=d;y>0;y-=lowbit(y))
			ans-=red[x][y];
			
			for(int x=a-1;x>0;x-=lowbit(x))
			for(int y=b-1;y>0;y-=lowbit(y))
			ans+=red[x][y];
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
