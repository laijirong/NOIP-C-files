//HDU 4819
#include<cstdio>
#include<iostream>
using namespace std;
int t,n,m,p,a,b,c,x1,x2,y1,y2,ansa,ansi,ans,root,zy[810][810];
struct tree
{
	int son[4];
	int maxz,minz;
} red[1000010*5];
void make(int &root,int u,int l,int d,int r)
{
	if(d<u||r<l)	return ;
	root=++p;
	if(u==d&&l==r)
	{
		red[root].maxz=red[root].minz=zy[u][r];
		return ;
	}
	
	make(red[root].son[0],u,l,(u+d)/2,(l+r)/2);
	make(red[root].son[1],u,(l+r)/2+1,(u+d)/2,r);
	make(red[root].son[2],(u+d)/2+1,l,d,(l+r)/2);
	make(red[root].son[3],(u+d)/2+1,(l+r)/2+1,d,r);
	
	red[root].maxz=red[red[root].son[0]].maxz;
	red[root].minz=red[red[root].son[0]].minz;
	for(int i=1;i<=3;i++)
	{
		if(red[red[root].son[i]].maxz>red[root].maxz)
		red[root].maxz=red[red[root].son[i]].maxz;
		if(red[red[root].son[i]].minz<red[root].minz)
		red[root].minz=red[red[root].son[i]].minz;
	}
}
void work(int root,int u,int l,int d,int r)
{
	if(x1<=u&&y1<=l&&x2>=d&&y2>=r)
	{
		ansa=max(ansa,red[root].maxz);
		ansi=min(ansi,red[root].minz);
		return ;
	}
	if(x1<=(u+d)/2&&y1<=(l+r)/2&&red[root].son[0])
	work(red[root].son[0],u,l,(u+d)/2,(l+r)/2);
	
	if(x1<=(u+d)/2&&y2>(l+r)/2&&red[root].son[1])
	work(red[root].son[1],u,(l+r)/2+1,(u+d)/2,r);
	
	if(x2>(u+d)/2&&y1<=(l+r)/2&&red[root].son[2])
	work(red[root].son[2],(u+d)/2+1,l,d,(l+r)/2);
	
	if(x2>(u+d)/2&&y2>(l+r)/2&&red[root].son[3])
	work(red[root].son[3],(u+d)/2+1,(l+r)/2+1,d,r);
}
void change(int root,int u,int l,int d,int r)
{
	if(u==d&&u==a&&l==r&&l==b)
	{
		red[root].maxz=red[root].minz=ans;
		return ;
	}
	if(a<=(u+d)/2&&b<=(l+r)/2&&red[root].son[0])
	change(red[root].son[0],u,l,(u+d)/2,(l+r)/2);
	if(a<=(u+d)/2&&b>(l+r)/2&&red[root].son[1])
	change(red[root].son[1],u,(l+r)/2+1,(u+d)/2,r);
	if(a>(u+d)/2&&b<=(l+r)/2&&red[root].son[2])
	change(red[root].son[2],(u+d)/2+1,l,d,(l+r)/2);
	if(a>(u+d)/2&&b>(l+r)/2&&red[root].son[3])
	change(red[root].son[3],(u+d)/2+1,(l+r)/2+1,d,r);
	
	red[root].maxz=red[red[root].son[0]].maxz;
	red[root].minz=red[red[root].son[0]].minz;
	for(int i=1;i<=3;i++)
	{
		if(red[red[root].son[i]].maxz>red[root].maxz)
		red[root].maxz=red[red[root].son[i]].maxz;
		if(red[red[root].son[i]].minz<red[root].minz)
		red[root].minz=red[red[root].son[i]].minz;
	}
}
int main()
{
	scanf("%d",&t);
	red[0].maxz=-0x7fffffff;
	red[0].minz=0x7fffffff;
	for(int mm=1;mm<=t;mm++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		scanf("%d",&zy[i][j]);
		make(root,1,1,n,n);
		
		scanf("%d",&m);
		printf("Case #%d:\n",mm);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			c--;
			x1=a-c/2;y1=b-c/2;x2=a+c/2;y2=b+c/2;
			ansa=-0x7fffffff;
			ansi=0x7fffffff;
			work(root,1,1,n,n);
			ans=ansa+ansi>>1;
			printf("%d\n",ans);
			change(root,1,1,n,n);
		}
	}
	return 0;
}
