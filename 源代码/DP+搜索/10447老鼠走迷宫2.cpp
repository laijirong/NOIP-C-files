#include <cstdio>
using namespace std;
int m,n,s=300,d[20][20],rec[20][20],xb[]={0,0,1,-1},yb[]={1,-1,0,0};
struct w{
	int x, y;
} way[300],py[300];
void out(int a)
{
	printf("%d\n",a);
	for(int i=1;i<=a;i++)
	printf("%d %d\n",py[i].x,py[i].y);
}
void jdg (int a)
{
	if (a>s) return;
	for (int i=1;i<=a;i++)
		py[i]=way[i];	
	s=a;
}
void ss(int x,int y,int p)
{
	for (int i=0; i<=3;i++)
	{
		int tx=x+xb[i],ty=y+yb[i];
		if (tx>=1&&tx<=m&&ty>=1&&ty<=n&&(!d[tx][ty])&&(!rec[tx][ty]))
		{
			way[p].x=tx;way[p].y=ty;
			rec[tx][ty]=1;
			if (tx==m&&ty==n)
				jdg(p);
			else if (p+m-tx+n-ty<s)
				ss(tx,ty,p+1);
			rec[tx][ty]=0;
		}
	}
}
int main()
{
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&d[i][j]);
	ss(1,0,1);
	if (s==300)
		printf("Noway!\n");
	else
		out(s);
	return 0;
}