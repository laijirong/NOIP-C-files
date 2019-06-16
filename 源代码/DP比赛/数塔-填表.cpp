#include<cstdio>
#include<algorithm>
using namespace std;
int data[101][101];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			scanf("%d",&data[i][j]);
	for(int i=n-1;i>=1;i--)
		for(int j=1;j<=i;j++)
			data[i][j]+=max(data[i+1][j],data[i+1][j+1]);
	printf("%d\n",data[1][1]);
	return 0;
}
