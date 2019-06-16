#include<cstdio>
#include<cstdlib>
using namespace std;
int n,p,root,d[100010];
struct ss
{
	int val,left,right;
} tree[100010];
void change(int &a,int &b)
{
	int t=a;a=b;b=t;
}
void inse(int &root,int a)
{
	if(root==0)
	{
		tree[++p].val=a;
		root=p;
		return ;
	}
	if(a<=tree[root].val)	inse(tree[root].left,a);
	else					inse(tree[root].right,a);
}
void out(int a)
{
	if(tree[a].left)	out(tree[a].left);
	printf("%d ",tree[a].val);
	if(tree[a].right)	out(tree[a].right);
}
int main()
{
	freopen("10131.in","r",stdin);
	freopen("10131.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&d[i]);
	
	for(int i=1;i<=n;i++)
	{
		int l=(rand()%30000*1000)%n+1;
		int s=(rand()%30000*1000)%n+1;
		change(d[l],d[s]);
	}
	for(int i=1;i<=n;i++)
	inse(root,d[i]);
	out(root);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
