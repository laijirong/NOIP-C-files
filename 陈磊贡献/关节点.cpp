#include<cstdio>
using namespace std;
int n,m,zy,red,sum;
int used[2010],map[2010][2010],son[2010],num[2010],pos[2010][2010];
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
			if(a==1) red++;
			pos[a][i]=1;
			son[a]++;
			used[i]=1;
			search(i,a);
			if(Tarjan[i].low>Tarjan[a].dfn)
			num[a]++;
		}
		if(used[i]>0&&Tarjan[i].low<Tarjan[a].low)
		Tarjan[a].low=Tarjan[i].low;
		if(pos[a][i]==1) used[i]=-1;
	}
}
int main()
{
	int x,y;
	freopen("10312.in","r",stdin);
	freopen("10312.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		map[x][y]=1;
		map[y][x]=1;
	}
	used[1]=1;
	search(1,0);
	
	if(red>1) sum++;
	for(int i=2;i<=n;i++)
	if(son[i]!=0&&num[i]>=1) sum++;
	printf("%d\n",sum);
	if(red>1) printf("%d ",1);
	for(int i=2;i<=n;i++)
	if(son[i]!=0&&num[i]>=1) printf("%d ",i);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
