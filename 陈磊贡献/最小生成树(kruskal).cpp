#include<cstdio>
using namespace std;
int n,m,answer;
int head[3010],fa[3010];
struct ss
{
	int st,en,val;
} map[1000010],e[1000010],ans[3010];
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
void sort(int a,int b)
{
	if(a==b) return ;
	int mid=(a+b)/2;
	sort(a,mid);sort(mid+1,b);
	
	int p1=a,p2=mid+1,p=a;
	while(p1<=mid&&p2<=b)
	if(map[p1].val>map[p2].val)
	{
		e[p].val=map[p2].val;
		e[p].st=map[p2].st;
		e[p].en=map[p2].en;
		p++;p2++;
	}
	else
	{
		e[p].val=map[p1].val;
		e[p].st=map[p1].st;
		e[p].en=map[p1].en;
		p++;p1++;
	}
	
	for(int i=p1;i<=mid;i++)
	{
		e[p].val=map[i].val;
		e[p].st=map[i].st;
		e[p].en=map[i].en;
		p++;
	}
	for(int i=p2;i<=b;i++)
	{
		e[p].val=map[i].val;
		e[p].st=map[i].st;
		e[p].en=map[i].en;
		p++;
	}
	
	for(int i=a;i<=b;i++)
	{
		map[i].val=e[i].val;
		map[i].st=e[i].st;
		map[i].en=e[i].en;
	}
}
int main()
{
	freopen("11268.in","r",stdin);
	freopen("11268.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&map[i].st,&map[i].en,&map[i].val);
		
	}
	sort(1,m);
	for(int i=1;i<=n;i++)
	fa[i]=i;
	int num=0;
	for(int i=1;i<=m&&num<n;i++)
	{
		fa[map[i].st]=find(map[i].st);
		fa[map[i].en]=find(map[i].en);
		if(fa[map[i].st]==fa[map[i].en]) continue ;
		ans[++num].st=map[i].st;ans[num].en=map[i].en;
		fa[fa[map[i].st]]=fa[map[i].en];
		answer+=map[i].val;
	}
	printf("%d\n%d\n",answer,num);
	for(int i=1;i<=num;i++)
	printf("%d %d\n",ans[i].st,ans[i].en);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
