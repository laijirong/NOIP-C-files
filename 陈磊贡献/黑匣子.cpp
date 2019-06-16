#include<cstdio>
#include<iostream>
using namespace std;
int n,sum,root,p;
char a,b,c;
struct ss
{
	int val,left,right,son;
} tree[30010];
void inse(int &root,int a)
{
	if(root==0)
	{
		tree[++p].val=a;
		tree[p].son=1;
		root=p;
		return ;
	}
	tree[root].son++;
	if(a<=tree[root].val)	inse(tree[root].left,a);
	else					inse(tree[root].right,a);
}
int findl(int a)
{
	if(a==0) return 0;
	return tree[a].son;
}
int find(int a,int k)
{
	int ls=findl(tree[a].left);
	if(ls>=k)		return find(tree[a].left,k);
	if(ls==k-1)		return tree[a].val;
	if(ls<k-1)		return find(tree[a].right,k-ls-1);
}
int main()
{
	freopen("10572.in","r",stdin);
	freopen("10572.out","w",stdout);
	while(cin>>a>>b>>c)
	{
		if(a=='A')
		{
			cin>>a>>n>>b;
			inse(root,n);
			continue ;
		}
		if(a=='G')
		{
			if(sum>=p)
			{
				printf("0 ");
				continue ;
			}
			printf("%d ",find(root,++sum));
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
