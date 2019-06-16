#include<iostream>
#include<cstdio>
using namespace std;
int n,st,en,pos;
int map[2010][2010],used[2010],met[2010];
void search(int a)
{
	used[a]=1;
	for(int i=1;i<=n;i++)
	if(used[i]==0&&map[a][i]!=0&&map[a][i]+met[a]<met[i])
	met[i]=map[a][i]+met[a];
	
	int t1=0;
	for(int i=1;i<=n;i++)
	if(met[i]<met[t1]&&used[i]==0)
	t1=i;
	if(t1==0) pos=1;
	if(t1!=en&&pos==0) search(t1);
}
int main()
{
	int x=0,y=0,z=0;
	freopen("11269.in","r",stdin);
	freopen("11269.out","w",stdout);
	scanf("%d%d%d",&n,&st,&en);
	while(scanf("%d%d%d",&x,&y,&z)==3)
	map[x][y]=map[y][x]=z;
	if(x==0&&y==0&&z==0)
	{
		printf("0\n");
		return 0;
	}
	for(int i=0;i<=n;i++)
	met[i]=0x7fffffff;
	used[st]=1;
	for(int i=1;i<=n;i++)
	if(map[st][i]!=0)
	met[i]=map[st][i];
	int tt=0;
	for(int i=1;i<=n;i++)
	if(met[i]<met[tt])
	tt=i;
	
	search(tt);
	if(pos==0)	printf("%d\n",met[en]);
	else		printf("0\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
