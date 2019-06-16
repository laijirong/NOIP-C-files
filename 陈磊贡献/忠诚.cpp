#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m;
int red[100010][50],zy[100010];
int main()
{
	int a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&red[i][0]);
	int sum=0;
	for(int i=1;pow(2,i)<=n;i++)
	{
		int pos=pow(2,i);
		while(sum<=pos)
		zy[sum++]=i;
	}
	for(int i=1;pow(2,i)<=n;i++)
	for(int j=1;j<=n-pow(2,i)+1;j++)
	{
		int tt=pow(2,i-1);
		red[j][i]=min(red[j][i-1],red[j+tt][i-1]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		if(a==b)
		{
			printf("%d ",red[a][0]);
			continue ;
		}
		int mid=(b-a)/2+1;
		int pos1=zy[mid];
		int t1=pow(2,pos1);
		printf("%d ",min(red[a][pos1],red[b-t1+1][pos1]));
	}
	return 0;
}
