#include<cstdio>
#include<iostream>
#define maxn 32005
using namespace std;
int n,m;
int v,p,q;
int main_w[maxn];
int main_c[maxn];
int annex_w[maxn][3];
int annex_c[maxn][3];
int f[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&v,&p,&q);
		if (q==0)
		{
			main_w[i]=v;
			main_c[i]=v*p;
		}
		else
		{
			annex_w[q][0]++;
			annex_w[q][annex_w[q][0]]=v;
			annex_c[q][annex_w[q][0]]=v*p;
		}
	}
	for(int i=1;i<=m;i++)
	for(int j=n;main_w[i]!=0&&j>=main_w[i];j--)
	{
		f[j]=max(f[j],f[j-main_w[i]]+main_c[i]);
		
		if(j>=main_w[i]+annex_w[i][1])
		f[j]=max(f[j],f[j-main_w[i]-annex_w[i][1]]+main_c[i]+annex_c[i][1]);
		
		if(j>=main_w[i]+annex_w[i][2])
		f[j]=max(f[j],f[j-main_w[i]-annex_w[i][2]]+main_c[i]+annex_c[i][2]);
		
		if(j>=main_w[i]+annex_w[i][1]+annex_w[i][2])
		f[j]=max(f[j],f[j-main_w[i]-annex_w[i][1]-annex_w[i][2]]+main_c[i]+annex_c[i][1]+annex_c[i][2]);
	}
	printf("%d\n",f[n]);
	return 0;
}
