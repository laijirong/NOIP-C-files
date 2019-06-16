#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,len,l[110],dp[110];
char sen[110],words[110][20];
int check(int a,int b)
{
	int flag=0;
	for(int i=1;i<=l[b];i++)
	if(sen[a+i]!=words[b][i])
	{
		flag=1;
		break ;
	}
	if(flag) return 0;
	return l[b];
}
int main()
{
	freopen("10047.in","r",stdin);
	freopen("10047.out","w",stdout);
	scanf("%s",&sen[1]);
	len=strlen(&sen[1]);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",&words[i][1]);
		l[i]=strlen(&words[i][1]);
	}
	for(int i=1;i<=len;i++)
	dp[i]=0x7fffffff/2;
	
	for(int i=1;i<=len;i++)
	for(int j=1;j<=n;j++)
	if(sen[i]==words[j][1])
	{
		int t=check(i-1,j);
		if(t) dp[i+t-1]=min(dp[i+t-1],dp[i-1]+1);
	}
	printf("%d\n",dp[len]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
