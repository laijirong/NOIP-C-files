#include<cstdio>
#include<iostream>
using namespace std;
int n,s,k,ans1,ans2,x,y,map[2010][2010],zy[2010],pos[2010];
struct ss
{
	int ma,mi;
} red[2010][2010];
int main()
{
	freopen("10179.in","r",stdin);
	freopen("10179.out","w",stdout);
	scanf("%d%d%d",&n,&s,&k);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	scanf("%d",&map[i][j]);
	for(int i=1;i<=n;i++)
	{
		int p1=1,p2=1,t;
		zy[p2]=-0x7fffffff;
		for(int j=n;j>=1;j--)
		{
			t=map[i][j];
			while(t>=zy[p2]&&p2>=p1)
			p2--;
			zy[++p2]=t;
			pos[p2]=j;
			if(pos[p1]-j>=s)
			p1++;
			red[i][j].ma=zy[p1];
		}
		for(int j=1;j<=n;j++)
		zy[j]=pos[j]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int p1=1,p2=1,t;
		zy[p2]=-0x7fffffff;
		for(int j=n;j>=1;j--)
		{
			t=-map[i][j];
			while(t>=zy[p2]&&p2>=p1)
			p2--;
			zy[++p2]=t;
			pos[p2]=j;
			if(pos[p1]-j>=s)
			p1++;
			red[i][j].mi=zy[p1];
		}
		for(int j=1;j<=p1;j++)
		zy[j]=pos[j]=0;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&x,&y);
		ans1=ans2=-0x7fffffff;
		for(int j=x;j<x+s;j++)
		{
			ans1=max(ans1,red[j][y].ma);
			ans2=max(ans2,red[j][y].mi);
		}
		printf("%d\n",ans1+ans2);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
