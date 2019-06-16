#include<cstdio>
using namespace std;
int n,m,bestlen=300;
int map[20][20],used[20][20];

struct ss
{
	int x,y;
} way[300],bestway[300];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void deal(int a)
{
	if(a>bestlen) return ;
	for(int i=1;i<=a;i++)
	{
		bestway[i].x=way[i].x;
		bestway[i].y=way[i].y;
	}
	bestlen=a;
}
void out(int a)
{
	printf("%d\n",a);
	for(int i=1;i<=a;i++)
	printf("%d %d\n",bestway[i].x,bestway[i].y);
}
void search(int x,int y,int a)
{
	int tx,ty;
	for(int i=0;i<=3;i++)
	{
		tx=x+dx[i];ty=y+dy[i];
		if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&(map[tx][ty]==0)&&(used[tx][ty]==0))
		{
			used[tx][ty]=1;
			way[a].x=tx;way[a].y=ty;
			if(tx==n&&ty==m) 
			deal(a);
			if(a+n-tx+m-ty<bestlen) search(tx,ty,a+1);
			used[tx][ty]=0;
		}
	}
}
int main()
{
	freopen("mouse.in","r",stdin);
//	freopen("mouse.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	scanf("%d",&map[i][j]);
	search(1,0,1);
	if(bestlen==300) printf("Noway!");
	else  out(bestlen);
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
