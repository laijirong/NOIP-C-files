#include<cstdio>
using namespace std;
int n,m,zy,red;
int used[2010],map[2010][2010],pos[2010][2010];
struct ss
{
	int dfn,low;
} Tarjan[2010];
void search(int a,int b)
{
	zy++;
	Tarjan[a].dfn=Tarjan[a].low=zy;
	for(int i=1;i<=n;i++)
	if(map[a][i]!=0&&i!=b)
	{
		if(used[i]==0)
		{
			pos[a][i]=1;
			used[i]=1;
			search(i,a);
			if(Tarjan[i].low>Tarjan[a].dfn)
			map[a][i]=10;
		}
		if(used[i]>0&&Tarjan[i].low<Tarjan[a].low)
		Tarjan[a].low=Tarjan[i].low;
		if(pos[a][i]==1) used[i]=-1;
	}
}
int main()
{
	int x,y;
	freopen("10313.in","r",stdin);
	freopen("10313.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		map[x][y]=1;
		map[y][x]=1;
	}
	used[1]=1;
	search(1,0);
	
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(map[i][j]==10)
	{
		map[j][i]=1;
		red++;
	}
	printf("%d\n",red);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(map[i][j]==10)
	printf("%d %d\n",i,j);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
