#include<cstdio>
using namespace std;
int n,m,head,tail;
int red[100010],zy[100010],used[100010],he[100010];
int check[100010];
struct ss
{
	int val,last,met;
} map[200010];
int main()
{
	int x=0,y=0,z=0;
	freopen("11269.in","r",stdin);
	freopen("11269.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==0)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		map[i].val=y;
		map[i].met=z;
		map[i].last=he[x];
		he[x]=i;
	}
	
	for(int i=1;i<=n;i++)
	red[i]=0x7fffffff;
	
	for(int i=he[1];i!=0;i=map[i].last)
	{
		red[map[i].val]=map[i].met;
		zy[++tail]=map[i].val;
		used[map[i].val]=1;
	}
	head=1;
	while(head<=tail)
	{
		for(int i=he[zy[head%n]];i!=0;i=map[i].last)
		if(red[zy[head%n]]+map[i].met<red[map[i].val])
		{
			red[map[i].val]=red[zy[head%n]]+map[i].met;
			if(used[map[i].val]==0)
			{
				zy[(++tail)%n]=map[i].val;
				used[map[i].val]=1;
			}
		}
		used[zy[head%n]]=0;
		head++;
	}
	if(red[n]==0x7fffffff)	printf("-1\n");
	else					printf("%d\n",red[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
