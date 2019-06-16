#include <cstdio>
#include <algorithm>
using namespace std;
char s[5010];
int n,sel,f[2][5010];
int main ()
{
	scanf("%d%s",&n,&s[1]);
	for (int i=n;i>=1;i--)
		{
			sel^=1;
			for (int j=i+1;j<=n;j++)
			{
				if (s[i]==s[j])
					f[sel][j]=f[sel^1][j-1];
				else
					f[sel][j]=min(f[sel^1][j],f[sel][j-1])+1;
			}
		}
	printf("%d",f[sel][n]);
	return 0;
}
