#include<iostream>
#include<cstdio>
using namespace std;
int a[1000][1000];//xÐÐ,yÁÐ 
int n;
int max(int x, int y)
{
	if(x==n) return a[x][y];
	int t=max(x+1,y);
	int t2=max(x+1,y+1);
	if(t>t2) return a[x][y]+max(x+1,y);
	else return a[x][y]+max(x+1,y+1);
}
int main()
{
	freopen("10235.in","r",stdin);
	freopen("10235.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++) 
		scanf("%d",&a[i][j]);
	printf("%d",max(1,1));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

