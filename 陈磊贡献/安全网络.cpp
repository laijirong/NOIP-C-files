#include<iostream>
#include<cstdio>
using namespace std;
int T,n,m,sum,p,q;
int head[10010],tail[10010],used[10010],seat[10010],len[10010];
struct s1
{
	int last,val;
} mapz[500010];
struct s2
{
	int last,start;
} mapf[500010];
void read1(int a,int b,int c)
{
	mapz[c].last=head[a];
	mapz[c].val=b;
	head[a]=c;
}
void read2(int a,int b,int c)
{
	mapf[c].last=tail[b];
	mapf[c].start=a;
	tail[b]=c;
}
void search2(int a)
{
	used[a]=0;
	for(int i=tail[a];i!=0;i=mapf[i].last)
	if(used[mapf[i].start]==1) search2(mapf[i].start);
}
void search1(int a)
{
	used[a]=1;
	for(int i=head[a];i!=0;i=mapz[i].last)
	if(used[mapz[i].val]==0)	search1(mapz[i].val);
	seat[++p]=a;
	len[q]++;
}
int main()
{
	int x,y;
	freopen("10837.in","r",stdin);
	freopen("10837.out","w",stdout);
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			read1(x,y,i);
			read2(x,y,i);
		}
		for(int i=1;i<=n;i++)
		if(used[i]==0)
		{
			q++;
			search1(i);
		}
		for(int i=q;i>=1;i--)
		{
			for(int j=p;j>=p-len[i];j--)
			if(used[seat[j]]==1)
			{
				sum++;
				search2(seat[j]);
			}
			p-=len[i];
		}
		printf("%d\n",sum);
		
		for(int i=1;i<=10010;i++)
		head[i]=tail[i]=used[i]=seat[i]=len[i]=0;
		sum=p=q=0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
