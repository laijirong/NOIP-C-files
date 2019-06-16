#include<cstdio>
#include<iostream>
using namespace std;
int o2,n2,n,dp[30][80];
struct ss
{
	int oi,ni,wei;
} red[1010];
int main()
{
	freopen("10046.in","r",stdin);
	freopen("10046.out","w",stdout);
	int t1,t2;
	scanf("%d%d%d",&o2,&n2,&n);
	for(int i=1;i<=n;i++)
	scanf("%d%d%d",&red[i].oi,&red[i].ni,&red[i].wei);
    for(int i=0;i<=o2;i++)
	for(int j=0;j<=n2;j++)
	dp[i][j]=0x7fffffff/2;
	dp[0][0]=0;
	for(int k=1;k<=n;k++)
	for(int i=o2;i>=0;i--)
	for(int j=n2;j>=0;j--)
	{
		t1=i-red[k].oi;
		t2=j-red[k].ni;
		if(t1<0)	t1=0;
		if(t2<0)	t2=0;
		dp[i][j]=min(dp[i][j],dp[t1][t2]+red[k].wei);
	}
	printf("%d\n",dp[o2][n2]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
