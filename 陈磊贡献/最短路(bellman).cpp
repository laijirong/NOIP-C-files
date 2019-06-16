#include<cstdio>
using namespace std;
int n,sta,end,head,tail;
int red[2010],zy[2010],map[2010][2010],used[2010];
int main()
{
	int x=0,y=0,z=0;
	freopen("11269.in","r",stdin);
	freopen("11269.out","w",stdout);
	scanf("%d%d%d",&n,&sta,&end);
	if(sta==end)
	{
		printf("0\n");
		return 0;
	}
	while(scanf("%d%d%d",&x,&y,&z)==3)
	map[x][y]=map[y][x]=z;
	
	if(x==0&&y==0&&z==0)
	{
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	if(map[sta][i])
	{
		red[i]=map[sta][i];
		zy[++tail]=i;
		used[i]=1;
	}
	else red[i]=0x7fffffff;
	
	head=1;
	while(head<=tail)
	{
		for(int i=1;i<=n;i++)
		if(map[zy[head%n]][i]&&map[zy[head%n]][i]+red[zy[head%n]]<red[i])
		{
			red[i]=map[zy[head%n]][i]+red[zy[head%n]];
			if(used[i]==0)
			{
				zy[(++tail)%n]=i;
				used[i]=1;
			}
		}
		used[zy[head%n]]=0;
		head++;
	}
	printf("%d\n",red[end]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
