#include<iostream>
#include<cstdio>
using namespace std;
int n,m,sum,p,q,red;
int head[10010],tail[10010],used[10010],d[10010],len[10010];
int seat[10010],l[10010];
struct ss
{
	int last,val;
} mapz[500010];
struct sss
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
	seat[++red]=a;
	for(int i=tail[a];i!=0;i=mapf[i].last)
	if(used[mapf[i].start]!=0) search2(mapf[i].start);
}
void search1(int a)
{
	used[a]=1;
	for(int i=head[a];i!=0;i=mapz[i].last)
	if(used[mapz[i].val]==0)	search1(mapz[i].val);
	d[++p]=a;
	len[q]++;
}
int main()
{
	int x,y;
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
		if(used[d[j]]==1)
		{
			sum++;
			search2(d[j]);
			l[sum]=red;
		}
		p-=len[i];
	}
	
	printf("%d\n",sum);
	for(int i=1;i<=sum;i++)
	{
		printf("%d ",l[i]-l[i-1]);
		for(int j=l[i-1]+1;j<=l[i];j++)
		printf("%d ",seat[j]);
		printf("\n");
	}
	return 0;
}
