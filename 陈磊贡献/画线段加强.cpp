#include<cstdio>
using namespace std;
int sta,end,root,n,p,len;
struct tree
{
	int ls,rs,left,right,lazy;
} red[3000100];
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
		return ;
	}
	if(find(red[d].ls)==-1)
	inse(red[d].ls,red[d].left,(red[d].left+red[d].right)/2);
	
	if(find(red[d].rs)==-1)
	inse(red[d].rs,(red[d].left+red[d].right)/2+1,red[d].right);
	
	if(red[d].lazy==2&&c==0) return ;
	if(red[d].lazy)
	{
		red[find(red[d].ls)].lazy=red[find(red[d].rs)].lazy=red[d].lazy;
		red[d].lazy=0;
	}
	if(a<=(red[d].left+red[d].right)/2)		work(a,b,c,red[d].ls);
	if(b>(red[d].left+red[d].right)/2)		work(a,b,c,red[d].rs);
}
void check(int root)
{
	if(red[root].lazy==2) return ;
	if(red[root].lazy==1)
	{
		len+=red[root].right-red[root].left+1;
		return ;
	}
	if(red[root].left==red[root].right) return ;
	check(red[root].ls);
	check(red[root].rs);
}
int main()
{
	freopen("10992.in","r",stdin);
	freopen("10992.out","w",stdout);
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
	}
	check(root);
	printf("%d\n",len);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
