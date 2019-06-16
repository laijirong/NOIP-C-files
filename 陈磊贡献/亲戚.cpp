#include<cstdio>
using namespace std;
int n,m,p,pos,father[500010];
int find(int a)
{
    int t1=a,t2;
    while(father[a]!=a) a=father[a];
    while(father[t1]!=t1)
    {
    	t2=father[t1];
    	father[t1]=a;
    	t1=t2;
    }
    return a;
}
int main()
{
	int x,y;
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)
	father[i]=i;
	for(int i=1;i<=m;i++)
	{
		pos=0;
		scanf("%d%d",&x,&y);
		father[find(x)]=find(y);
	}
	for(int i=1;i<=n;i++)
	father[i]=find(i);
	for(int i=1;i<=p;i++)
	{
		scanf("%d%d",&x,&y);
		if(father[x]==father[y])	printf("Yes\n");
		else					printf("No\n");
	}
	return 0;
}
