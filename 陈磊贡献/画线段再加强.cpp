#include<cstdio>
using namespace std;
int sta,end,root,n,p;
struct tree
{
	int ls,rs,left,right,lazy,ans;
} red[2000100];
int find(int a)
{
	if(a==0) return -1;
	return a;
}
void inse(int &root,int a,int b)
{
	root=++p;
	red[p].left=a;
	red[p].right=b;
}
void work(int a,int b,int c,int d)
{
	if(a<=red[d].left&&b>=red[d].right)
	{
		red[d].lazy=c;
		if(!c) red[d].lazy=2;
		if(c==1)	red[d].ans=red[d].right-red[d].left+1;
		else		red[d].ans=0;
		return ;
	}
	if(find(red[d].ls)==-1)
	inse(red[d].ls,red[d].left,(red[d].left+red[d].right)/2);
	if(find(red[d].rs)==-1)
	inse(red[d].rs,(red[d].left+red[d].right)/2+1,red[d].right);
	if(red[d].lazy==2&&c==0)
	{
		red[d].ans=0;
		return ;
	}
	if(red[d].lazy==1)
	{
		red[find(red[d].ls)].lazy=red[find(red[d].rs)].lazy=red[d].lazy;
		red[find(red[d].ls)].ans=red[find(red[d].ls)].right-red[find(red[d].ls)].left+1;
		red[find(red[d].rs)].ans=red[find(red[d].rs)].right-red[find(red[d].rs)].left+1;
		red[d].lazy=0;
	}
	if(red[d].lazy==2)
	{
		red[find(red[d].ls)].lazy=red[find(red[d].rs)].lazy=red[d].lazy;
		red[find(red[d].ls)].ans=red[find(red[d].rs)].ans=0;
		red[d].lazy=0;
	}
	if(a<=(red[d].left+red[d].right)/2)		work(a,b,c,red[d].ls);
	if(b>(red[d].left+red[d].right)/2)		work(a,b,c,red[d].rs);
	red[d].ans=red[red[d].ls].ans+red[red[d].rs].ans;
}
int main()
{
	freopen("10993.in","r",stdin);
	freopen("10993.out","w",stdout);
	scanf("%d%d%d",&sta,&end,&n);
	end-=sta;
	root=++p;
	red[p].left=1;
	red[p].right=end;
	int a,b,c;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&c,&a,&b);
		if(a==b) continue ;
		a-=sta;b-=sta;
		work(a+1,b,c^1,root);
		printf("%d\n",red[root].ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
