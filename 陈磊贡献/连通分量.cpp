#include<cstdio>
using namespace std;
int n,m,sum,head[500010],ff[500010],red[500010];
int find(int a)
{
    int t1=a,t2;
    while(head[a]!=a) a=head[a];
    while(head[t1]!=t1)
    {
    	t2=head[t1];
    	head[t1]=a;
    	t1=t2;
    }
    return a;
}
int main()
{
	int x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	head[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		head[find(y)]=find(x);
	}
	for(int i=1;i<=n;i++)
	head[i]=find(i);
	
	for(int i=1;i<=n;i++)
	red[head[i]]++;
	
	for(int i=1;i<=n;i++)
	if(red[i]!=0) sum++;
	printf("%d\n",sum);
	
	for(int i=1;i<=n;i++)
	if(red[i]!=0)
	{
		sum=0;
		printf("%d ",red[i]);
		for(int j=1;j<=n&&sum<=red[i];j++)
		if(head[j]==i)
		{
			printf("%d ",j);
			sum++;
		}
		printf("\n");
	}
	return 0;
}
