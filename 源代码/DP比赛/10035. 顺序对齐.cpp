//10035. Ë³Ðò¶ÔÆë
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char db1[3005],db2[3005];
int l1,l2,ans,f[3005][3005][2][2];
int g(char a,char b)
{
	if (a==b) return 2;else return 0;
}
int max(int a,int b,int c)
{
	if (a>b) b=a;if (c>b) b=c;return b;
}
int main ()
{
//	freopen ("10035.in","r",stdin);
	scanf("%s%s",&db1[1],&db2[1]);
	l1=strlen(&db1[1]);l2=strlen(&db2[1]);
	for (int i=1;i<=l1;i++)
		for (int j=1;j<=l2;j++)
			{
				f[i][j][0][0]=max(f[i-1][j-1][0][0],f[i-1][j-1][1][0],f[i-1][j-1][0][1])+g(db1[i],db2[j]);
				f[i][j][1][0]=max(f[i-1][j][0][0]-1,f[i-1][j][1][0],f[i-1][j][0][1]-1);
				f[i][j][0][1]=max(f[i][j-1][0][0]-1,f[i][j-1][1][0]-1,f[i][j-1][0][1]);
			}
	ans=max(f[l1][l2][0][0],f[l1][l2][1][0],f[l1][l2][0][1]);
	printf("%d",ans);
	return 0;
} 
