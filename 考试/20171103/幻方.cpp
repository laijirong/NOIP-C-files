#include<cstdio>
using namespace std;
int n;
int d[40][40];
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d",&n);
	int t=(1+n)/2;
	d[1][t]=1;
	int a=1,b=t;
	for(int i=2;i<=n*n;i++)
	{
	
		if(a==1&&b!=n) 
		{
			d[n][b+1]=i;
			a=n;b=b+1;
			continue;
		}
		if(a!=1&&b==n)
		{
			d[a-1][1]=i;
			a=a-1;b=1;
			continue;
		}
		if(a==1&&b==n)
		{
			d[a+1][b]=i;
			a=a+1;b=b;
			continue;
		}
		if(a!=1&&b!=n)
		{
			if(d[a-1][b+1]==0)
			{
				d[a-1][b+1]=i;
				a=a-1;b=b+1;
			}
			else
			{
				d[a+1][b]=i;
				a=a+1;b=b;
			}
			continue;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		printf("%d ",d[i][j]);
		printf("\n");
	}
	fclose(stdout);
	return 0;
}
