#include<cstdio>
using namespace std;
int n,f[40][40],x[1600],y[1600];
int main ()
{
//	freopen ("magic.in","r",stdin);
//	freopen ("magic.out","w",stdout);
	scanf("%d",&n);
	f[1][n/2+1]=1;
	x[1]=1;
	y[1]=n/2+1;
	for (int i=2; i<=n*n; i++)
		{
			if(x[i-1]==1&&y[i-1]!=n)
				{
					x[i]=n;
					y[i]=y[i-1]+1;
					f[n][y[i]]=i;
					continue;
				}
			if(x[i-1]!=1&&y[i-1]==n)
				{
					x[i]=x[i-1]-1;
					y[i]=1;
					f[x[i]][1]=i;
					continue;
				}
			if(x[i-1]==1&&y[i-1]==n)
				{
					x[i]=x[i-1]+1;
					y[i]=y[i-1];
					f[x[i]][y[i]]=i;
					continue;
				}
			if(x[i-1]!=1&&y[i-1]!=n)
				{

					if (f[x[i-1]-1][y[i-1]+1]==0)
						{
							x[i]=x[i-1]-1;
							y[i]=y[i-1]+1;
							f[x[i]][y[i]]=i;
						}
					else
						{
							x[i]=x[i-1]+1;
							y[i]=y[i-1];
							f[x[i]][y[i]]=i;
						}
					continue;
				}
		}
	for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=n; j++)
				printf("%d ",f[i][j]);
			printf("\n");
		}

	fclose (stdin);
	fclose (stdout);
	return 0;
}
