#include <cstdio>
using namespace std;
char d1[110],d2[110];
int n,m,f[110][110],t[128],g[][5]={{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,0}};
int max(int a,int b,int c)
{
	if (a>b) b=a;
	if (c>b) b=c;
	return b;
}
int main ()
{
//	freopen ("10033.in","r",stdin);
	scanf("%d%s%d%s",&n,&d1[1],&m,&d2[1]);
	t[int('A')]=0;t[int('C')]=1;t[int('G')]=2;t[int('T')]=3;
	for (int i=1;i<=n;i++) f[i][0]=f[i-1][0]+g[4][t[d1[i]]];
	for (int i=1;i<=m;i++) f[0][i]=f[0][i-1]+g[t[d2[i]]][4];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			f[i][j]=max(f[i-1][j-1]+g[t[d1[i]]][t[d2[j]]],f[i-1][j]+g[t[d1[i]]][4],f[i][j-1]+g[4][t[d2[j]]]);
	printf("%d\n",f[n][m]);
//	fclose(stdin);
	return 0;
} 
