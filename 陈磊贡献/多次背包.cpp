#include<cstdio>
#include<iostream>
using namespace std;
int n,c;
double dp[5][2010];
struct goods
{
	double w,co;
	int v,k;
} red[1010];
int main()
{
	freopen("10479.in","r",stdin);
	freopen("10479.out","w",stdout);
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%d%d",&red[i].w,&red[i].v,&red[i].k);
		red[i].k=min(red[i].k,c/red[i].v);
	}
	for(int i=1;i<=n;i++)
	for(int k=1;k<=red[i].k;k++)
	for(int j=c;j>=k*red[i].v;j--)
	dp[i%2][j]=max(dp[(i-1)%2][j],dp[(i-1)%2][j-k*red[i].v]+k*red[i].w);
	
	printf("%.2lf\n",dp[n%2][c]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
