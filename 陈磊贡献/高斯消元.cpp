#include<cmath>
#include<cstdio>
using namespace std;
int n;
double zy=1e-8,red[110][110];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n+1;j++)
	scanf("%lf",&red[i][j]);
	
	for(int i=1;i<=n;i++)
	{
		if(fabs(red[i][i])<=zy)
		{
			puts("No Solution");
			return 0;
		}
		
		for(int j=i+1;j<=n+1;j++)
		red[i][j]/=red[i][i];
		
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue ;
			for(int k=i+1;k<=n+1;k++)
			red[j][k]-=red[j][i]*red[i][k];
		}
	}
	for(int i=1;i<=n;i++)
	printf("%.2lf\n",red[i][n+1]);
	return 0;
}
