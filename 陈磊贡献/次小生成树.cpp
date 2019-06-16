#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int T,n,m,sum,answer,ans,sou;
int head[10010],fa[10010],used[10010],deepth[10010],dd[10010];
struct s1
{
	int st,en,vall;
} map[100010],e[100010],out[200010];
struct s2
{
	int num,val,last;
} red[100010];
struct s3
{
	int deep,point,most;
} zy[10010][20];
int find(int a)
{
	int t1=a,t2;
	while(fa[a]!=a) a=fa[a];
	while(fa[t1]!=t1)
	{
		t2=fa[t1];
		fa[t1]=a;
		t1=t2;
	}
	return a;
}
void dfs(int a,int b,int c)
{
	used[a]=1;
	deepth[a]=b;
	dd[b]=a;
	for(int i=0;pow(2,i)<b;i++)
	{
		int t1=pow(2,i),t2=pow(2,i-1);
		zy[a][i].deep=b-t1;
		zy[a][i].point=dd[zy[a][i].deep];
		if(i==0)		zy[a][i].most=red[c].val;
		else			zy[a][i].most=max(zy[a][i-1].most,zy[dd[b-t2]][i-1].most);
	}
	for(int i=head[a];i!=0;i=red[i].last)
	if(used[red[i].num]==0) dfs(red[i].num,b+1,i);
}
void change(int &a,int &b)
{
	int t=a;a=b;b=t;
}
void sort(int a,int b)
{
	if(a==b) return ;
	int mid=(a+b)/2;
	sort(a,mid);sort(mid+1,b);
	
	int p1=a,p2=mid+1,p=a;
	while(p1<=mid&&p2<=b)
	if(map[p1].vall>map[p2].vall)
	{
		e[p].vall=map[p2].vall;
		e[p].st=map[p2].st;
		e[p].en=map[p2].en;
		p++;p2++;
	}
	else
	{
		e[p].vall=map[p1].vall;
		e[p].st=map[p1].st;
		e[p].en=map[p1].en;
		p++;p1++;
	}
	
	for(int i=p1;i<=mid;i++)
	{
		e[p].vall=map[i].vall;
		e[p].st=map[i].st;
		e[p].en=map[i].en;
		p++;
	}
	for(int i=p2;i<=b;i++)
	{
		e[p].vall=map[i].vall;
		e[p].st=map[i].st;
		e[p].en=map[i].en;
		p++;
	}
	
	for(int i=a;i<=b;i++)
	{
		map[i].vall=e[i].vall;
		map[i].st=e[i].st;
		map[i].en=e[i].en;
	}
}
int main()
{
	freopen("10749.in","r",stdin);
	freopen("10749.out","w",stdout);
	scanf("%d",&T);
	for(int mm=1;mm<=T;mm++)
	{
		sum=answer=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&map[i].st,&map[i].en,&map[i].vall);
			if(map[i].st==map[i].en)
			{
				i--;
				m--;
			}
		}
		if(m==n-1)
		{
			printf("-1\n");
			continue ;
		}
		sort(1,m);
		for(int i=1;i<=n;i++)
		fa[i]=i;
		sum=sou=0;
		for(int i=1;i<=m;i++)
		{
			fa[map[i].st]=find(map[i].st);
			fa[map[i].en]=find(map[i].en);
			if(fa[map[i].st]==fa[map[i].en])
			{
				sou++;
				out[sou].st=map[i].st;
				out[sou].en=map[i].en;
				out[sou].vall=map[i].vall;
				continue ;
			}
			red[++sum].num=map[i].en;red[sum].last=head[map[i].st];
			head[map[i].st]=sum;red[sum].val=map[i].vall;
			
			red[++sum].num=map[i].st;red[sum].last=head[map[i].en];
			head[map[i].en]=sum;red[sum].val=map[i].vall;
			
			fa[fa[map[i].st]]=fa[map[i].en];
			answer+=map[i].vall;
		}
		if(sum/2!=n-1)
		{
			printf("-1\n");
			continue ;
		}
		dfs(1,1,0);
		ans=0x7fffffff;
		for(int i=1;i<=sou;i++)
		{
			int mo=0;
			int a=out[i].st,b=out[i].en;
			if(deepth[a]<deepth[b]) change(a,b);
			if(deepth[a]!=deepth[b])
			{
				while(1)
				{
					int dee=0;
					if(deepth[a]-1==deepth[b])
					{
						mo=max(mo,zy[a][0].most);
						a=zy[a][0].point;
						break;
					}
					while(deepth[a]-pow(2,dee+1)>deepth[b])
					dee++;
					mo=max(mo,zy[a][dee].most);
					a=zy[a][dee].point;
				}
			}
			if(a==b)
			{
				ans=min(ans,answer-mo+out[i].vall);
				continue ;
			}
			while(1)
			{
				int dee=0;
				if(zy[a][0].point==zy[b][0].point)
				{
					int tt=max(zy[a][0].most,zy[b][0].most);
					mo=max(mo,tt);
					break;
				}
				while(zy[a][dee+1].point!=zy[b][dee+1].point)
				dee++;
				int tt=max(zy[a][dee].most,zy[b][dee].most);
				mo=max(mo,tt);
				a=zy[a][dee].point;
				b=zy[b][dee].point;
			}
			ans=min(ans,answer+out[i].vall-mo);
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
		head[i]=fa[i]=used[i]=deepth[i]=dd[i]=0;
		
		for(int i=1;i<=n;i++)
		for(int j=0;j<=15;j++)
		zy[i][j].point=zy[i][j].most=zy[i][j].deep=0;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
