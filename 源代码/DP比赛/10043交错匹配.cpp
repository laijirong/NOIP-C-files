//10043. Ωª¥Ì∆•≈‰
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,ans,p1,p2,f[210][210],db[210],db1[210];
int main ()
{
//	freopen ("10043.in","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&db[i]);
	for (int i=1;i<=m;i++) scanf("%d",&db1[i]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			{
				p1=0;p2=0;f[i][j]=max(f[i-1][j],f[i][j-1]);
				if (db[i]!=db1[j])
					{
						for (int k=i-1;k>=1;k--)
							if (db[k]==db1[j]) {p1=k;break;}
							if (p1==0) continue;
						for (int k=j-1;k>=1;k--)
							if (db[i]==db1[k]) {p2=k;break;}
							if (p2==0) continue;
						f[i][j]=max(f[i][j],f[p1-1][p2-1]+2);
					}
			}
	printf("%d",f[n][m]);
	fclose(stdin);
	return 0;
}
