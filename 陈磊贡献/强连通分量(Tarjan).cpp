#include<cstdio>
using namespace std;
int n,m,pos,sum,red,zy;
int head[10010],used[10010],seat[10010];
int l[10010],ans[10010];
struct s1
{
	int last,val;
} map[500010];
struct s2
{
	int dfn,low;
} Tarjan[10010];
void search(int a)
{
	used[a]=zy;
	seat[++pos]=a;
	Tarjan[a].dfn=Tarjan[a].low=pos;
	for(int i=head[a];i!=0;i=map[i].last)
	{
		
		if(used[map[i].val]==0)	search(map[i].val);
		
		if(Tarjan[map[i].val].low<Tarjan[a].low&&used[map[i].val]==zy)
		Tarjan[a].low=Tarjan[map[i].val].low;
		
	}
	
	if(Tarjan[a].dfn==Tarjan[a].low)
	{
		l[++sum]=pos-Tarjan[a].dfn+1;
		for(int i=Tarjan[a].dfn;i<=pos;i++)
		{
			ans[++red]=seat[i];
			used[seat[i]]=-1;
		}
		pos=Tarjan[a].dfn-1;
	}
}
int main()
{
	int x,y;
	freopen("10718.in","r",stdin);
	freopen("10718.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		map[i].last=head[x];
		map[i].val=y;
		head[x]=i;
	}
	for(int i=1;i<=n;i++)
	if(used[i]==0)
	{
		zy++;
		pos=0;
		search(i);
	}
	red=0;
	printf("%d\n",sum);
	for(int i=1;i<=sum;i++)
	{
		printf("%d ",l[i]);
		for(int j=1;j<=l[i];j++)
		printf("%d ",ans[++red]);
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
