#include<cstring>
#include<cstdio>
using namespace std;
int n,m,t,sx,sy,fx,fy,xx,yy,answer,used[10][10];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void search(int x,int y)
{
	if(x==fx&&y==fy)
	{
		answer++;
		return ;
	}
	for(int i=0;i<=3;i++)
	{
		int tx=x+dx[i],ty=y+dy[i];
		if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&used[tx][ty]==0)
		{
			used[tx][ty]=1;
			search(tx,ty);
			used[tx][ty]=0;
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&t);
	scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d",&xx,&yy);
		used[xx][yy]=1;
	}
	used[sx][sy]=1;
	search(sx,sy);
	printf("%d",answer);
	return 0;
}
