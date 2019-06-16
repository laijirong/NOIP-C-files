#include<iostream>
#include<cstdio>
using namespace std;
int n,m,odd,sta,p=1;
int way[1000],head[1000],fa[1000];
struct ss
{
	int last,val,used;
}map[200010];
int find(int a)
{
	int t1=a,t2;
	while(fa[a]!=a)	a=fa[a];
	while(fa[t1]!=a)
	{
		t2=fa[t1];
		fa[t1]=a;
		t1=t2;
	}
	return a;
}
void search(int a)
{
	for(int &i=head[a];i!=0;i=map[i].last)
	if(map[i].used==0&&way[a]!=0)
	{
		way[a]--;
		way[map[i].val]--;
		map[i^1].used=map[i].used=1;
		search(map[i].val);
	}
	printf("%d ",a);
}
void read(int a,int b)
{
	map[++p].val=b;
	map[p].last=head[a];
	head[a]=p;
}
int main()
{
	int x,y;
	freopen("10052.in","r",stdin);
	freopen("10052.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	fa[i]=i;
	while(scanf("%d%d",&x,&y)==2)
	{
		read(x,y);	read(y,x);
	 	way[x]++;	way[y]++;
	 	fa[find(x)]=find(y);
	}
	for(int i=1;i<=n;i++)
	{
		fa[i]=find(i);
		if(way[i]!=0)	sta=i;
	}
	if(sta==0)
	{
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(fa[i]!=fa[1])
		{
			printf("0\n");
			return 0;
		}
		if(way[i]%2!=0&&way[i]!=0) 
		{
	 		if(odd==0) sta=i;
	 		odd++;
		}
	}
	if(odd)
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
