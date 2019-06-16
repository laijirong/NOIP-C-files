#include<cstdio>
using namespace std;
int n,m,x,y,map[2010][2010],num[2010],used[2010],pos[2010];
void search(int a)
{
	pos[a]=1;
	for(int i=1;i<=num[a];i++)
	if(used[map[a][i]]==0)
	{
		used[map[a][i]]=1;
		search(map[a][i]);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		num[x]++;num[y]++;
		map[x][num[x]]=y;
		map[y][num[y]]=x;
	}
	used[1]=1;
	search(1);
	for(int i=1;i<=n;i++)
	if(pos[i]==0)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	return 0;
}
