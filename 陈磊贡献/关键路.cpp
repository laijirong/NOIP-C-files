#include<cstdio>
using namespace std;
int n,head,last,answer,answ,in[2010],out[2010],dp[2010],seat[2010];
int ans[2010],mapout[2010][2010],d[2010];
int mapin[2010][2010];
int main()
{
	freopen("10314.in","r",stdin);
	freopen("10314.out","w",stdout);
	int x,y;
	scanf("%d",&n);
	while(scanf("%d%d",&x,&y)==2)
	{
		out[x]++;
		in[y]++;
		mapout[x][out[x]]=y;
		mapout[y][0]++;
		scanf("%d",&mapin[y][x]);
	}
	
	for(int i=1;i<=n;i++)
	if(in[i]==0) d[++head]=i;
	last=head;
	for(int i=1;i<=last;i++)
	{
		for(int j=1;j<=out[d[i]];j++)
		{
			in[mapout[d[i]][j]]--;
			if(in[mapout[d[i]][j]]==0)
			d[++last]=mapout[d[i]][j];
		}
	}
	
	for(int i=1;i<=last;i++)
	{
		int tt=0;
		for(int j=1;j<=n;j++)
		if(mapin[d[i]][j]!=0&&dp[j]+mapin[d[i]][j]>tt )
		{
			tt=dp[j]+mapin[d[i]][j];
			seat[d[i]]=j;
		}
			dp[d[i]]=tt;
	}
	
	for(int i=1;i<=n;i++)
	if(out[i]==0)
	if(dp[i]>answ)
	{
		answ=dp[i];
		answer=i;
	}
	printf("%d\n",answ);
	
	int pos=answer,sum=n;
	while(sum)
	{
		ans[sum--]=pos;
		pos=seat[pos];
		if(pos==0) break;
	}
	
	for(int i=sum+1;i<=n;i++)
	printf("%d ",ans[i]);
	printf("\n");
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
