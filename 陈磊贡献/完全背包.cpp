#include<cstdio>
#include<iostream>
using namespace std;
int n,s;
float dp[1010];
struct goods
{
	float val;
	int v;
} red[3010];
int main()
{
	freopen("11376.in","r",stdin);
	freopen("11376.out","w",stdout);
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)
	scanf("%d%f",&red[i].v,&red[i].val);
	for(int i=0;i<=n;i++)
	for(int j=red[i].v;j<=s;j++)
	dp[j]=max(dp[j],dp[j-red[i].v]+red[i].val);
		
	printf("%.2f\n",dp[s]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
