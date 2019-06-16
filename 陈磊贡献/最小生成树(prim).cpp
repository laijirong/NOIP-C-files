#include<cstdio>
using namespace std;
int n,m,answer;
int head[3010],used[3010],fr[3010],now[3010];
struct s1
{
	int val,meter,last;
} map[2000010];
struct s2
{
	int met,from;
} point[3010];
void search(int a,int b)
{
	used[a]=1;
	for(int i=head[a];i!=0;i=map[i].last)
	if(used[map[i].val]==0&&map[i].meter<point[map[i].val].met)
	{
		point[map[i].val].met=map[i].meter;
		point[map[i].val].from=a;
	}
	int t1=0;
	for(int i=1;i<=n;i++)
	if(used[i]==0&&point[i].met<point[t1].met)
	t1=i;
	fr[b]=point[t1].from;	now[b]=t1;
	if(b<n)
	{
		answer+=point[t1].met;
		search(t1,b+1);
	}
}
void read(int a,int b,int c,int d)
{
	map[d].last=head[a];
	map[d].val=b;
	map[d].meter=c;
	head[a]=d;
}
int main()
{
	int xx,yy,zz;
	freopen("11268.in","r",stdin);
	freopen("11268.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=2;i<=2*m+1;i+=2)
	{
		scanf("%d%d%d",&xx,&yy,&zz);
		read(xx,yy,zz,i);
		read(yy,xx,zz,i^1);
	}
	for(int i=0;i<=n;i++)
	point[i].met=0x7fffffff;
	search(1,1);
	printf("%d\n%d\n",answer,n-1);
	for(int i=1;i<=n-1;i++)
	printf("%d %d\n",fr[i],now[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
