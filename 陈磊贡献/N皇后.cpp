#include<cstdio>
using namespace std;
int n,sum;
int used[20][20],seat[20];
void point(int a,int b)
{
	for(int i=1;i<=n;i++)
	used[a][i]++;
	
	for(int i=1;i<=n;i++)
	used[i][b]++;
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(i-a==j-b)
		used[i][j]++;
		if(a-i==j-b)
		used[i][j]++;
	}
}
void re(int a,int b)
{
	for(int i=1;i<=n;i++)
	used[a][i]--;
	
	for(int i=1;i<=n;i++)
	used[i][b]--;
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(i-a==j-b)
		used[i][j]--;
		if(a-i==j-b)
		used[i][j]--;
	}
}
void out(int a)
{
	sum++;
	for(int i=1;i<=a;i++)
	printf("%d",seat[i]);
	printf("\n");
	return ;
}
void search(int a)
{
	for(int i=1;i<=n;i++)
	if(used[a][i]==0)
	{
		seat[a]=i;
		point(a,i);
		if(a==n)	out(a);
		else		search(a+1);
		re(a,i);
	}
}
int main()
{
	freopen("10459.out","r",stdin);
	freopen("10459.out","w",stdout);
	scanf("%d",&n);
	search(1);
	printf("%d\n",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
