#include<iostream>
#include<cstdio>
using namespace std;
int n,m,peo,mac,answer,sumc,sump;
int used[40],E[40][40],maxc[40],maxp[40],num[40],sea[40];
struct ss
{
	int ma,ef;
} real[40][40];
void change(int &a,int &b)
{
	int t=a;a=b;b=t;
}
void search(int a,int b,int c,int d)
{
	if(b+c<=answer||b+d<=answer)	return ;
	if(a==n+1)
	{
		if(b>answer)
		answer=b;
		return ;
	}
	for(int i=1;i<=num[sea[a]];i++)
	if(used[real[sea[a]][i].ma]==0)
	{
		used[real[sea[a]][i].ma]=1;
		search(a+1,b+real[sea[a]][i].ef,c-maxc[real[sea[a]][i].ma],d-maxp[sea[a]]);
		used[real[sea[a]][i].ma]=0;
	}
}
int main()
{
	freopen("10805.in","r",stdin);
	freopen("10805.out","w",stdout);
	scanf("%d%d",&n,&m);
	while(scanf("%d%d",&peo,&mac)==2)
	{
		scanf("%d",&E[peo][mac]);
		maxp[peo]=max(maxp[peo],E[peo][mac]);
		maxc[mac]=max(maxc[mac],E[peo][mac]);
		
		num[peo]++;
		real[peo][num[peo]].ma=mac;
		real[peo][num[peo]].ef=E[peo][mac];
		for(int j=num[peo];j>1;j--)
		{
			if(real[peo][j].ef>real[peo][j-1].ef)
			{
				change(real[peo][j].ef,real[peo][j-1].ef);
				change(real[peo][j].ma,real[peo][j-1].ma);
			}
			else break;
		}
	}
	for(int i=n;i>=1;i--)
	{
		sea[i]=i;
		for(int j=i;j<n;j++)
		if(num[sea[j]]>num[sea[j+1]]) change(sea[j],sea[j+1]);
		else break;
	}
	for(int i=1;i<=n;i++)
	{
		sumc+=maxc[i];
		sump+=maxp[i];
	}
	search(1,0,sumc,sump);
	printf("%d %d\n",n,answer);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
