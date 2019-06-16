#include<cstdio>
#include<iostream>
using namespace std;
int n,m,p,q,isf,step;
int map[210][210],found[210][210];
int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
struct ss
{
	int x,y;
	int last;
}way[40010],ans[40010];
void mysearch(int a)
{
	if(way[a].last==0) return;
	mysearch(way[a].last);
	ans[++step].x=way[a].x;
	ans[step].y=way[a].y;
}
void bfs()
{
	way[++q].x=1;
	way[q].y=1;
	while(p<=q)
	{
		for(int i=0;i<=3;i++)
		{
			int tx=way[p].x+dx[i];
			int ty=way[p].y+dy[i];
			if(tx>n||ty>m||tx<=0||ty<=0) continue;
			if(found[tx][ty]==0&&map[tx][ty]==0)
			{
				way[++q].x=tx;
				way[q].y=ty;
				way[q].last=p;
				found[tx][ty]=1;
				if(way[q].x==n&&way[q].y==m)
				{
					isf=1;
					return;
				}
			}
			
		}
		p++;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	scanf("%d",&map[i][j]);
	bfs();
	if(isf==1) 
	{
		ans[++step].x=1;
		ans[step].y=1;
		mysearch(q);
		printf("%d\n",step);
		for(int i=1;i<=step;i++)
		printf("%d %d\n",ans[i].x,ans[i].y);
	}
	else printf("Noway!\n");
	return 0;
}
