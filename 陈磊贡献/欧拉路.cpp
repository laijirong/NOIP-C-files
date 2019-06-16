#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m,sta,odd;
int way[10010],head[10010];
struct ss
{
	int last,val,used;
}	map[400010];
void read(int a,int b,int c)
{
	map[c].val=b;
	map[c].last=head[a];
	head[a]=c;
}
void search(int a)
{
	for(int &i=head[a];i!=0;i=map[i].last)
	if(way[a]!=0&&map[i].used==0)
	{
		if(i<=m)
		{
			way[a]--;
			way[map[i].val]--;
			map[i+m].used=map[i].used=1;
			search(map[i].val);
		}
		if(i>m)
		{
			way[a]--;
			way[map[i].val]--;
			map[i-m].used=map[i].used=1;
			search(map[i].val);
		}
	}
	printf("%d ",a);
}
int main()
{
	int size =20<< 20;
	char *x = (char*)malloc(size) + size;
	__asm__("movl %0, %%esp\n" :: "r"(x));

	int xx,yy;
	freopen("10721.in","r",stdin);
	freopen("10721.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==0)
	{
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&xx,&yy);
		read(xx,yy,i);
		read(yy,xx,i+m);
		way[xx]++;
		way[yy]++;
	}
	for(int i=1;i<=n;i++)
	if(way[i]!=0)
	{
		sta=i;
		break;
	}
	for(int i=1;i<=n;i++)
	if(way[i]%2!=0&&way[i]!=0)
	{
		if(odd==0) sta=i;
		odd++;
	}
	if(odd!=2&&odd!=0)
	{
		printf("0\n");
		return 0;
	}
	printf("1\n");
	search(sta);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
