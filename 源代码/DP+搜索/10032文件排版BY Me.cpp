//10032. ÎÄ¼şÅÅ°æ
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,p,f[100010],len[100010],ll[100010];
char s[110];
int g(int a,int b)
{
	if (a==1&&b<n) return 500;
	if (a==1&&b==n) return 0;
	int t=n-b,m,ext;
	ext=t%(a-1);
	m=t/(a-1);
	return ext*m*m+(a-1-ext)*(m-1)*(m-1);
}
int main ()
{
	freopen ("10032.in","r",stdin);
	scanf("%d",&n);
	while (scanf("%s",s)==1)
		len[++p]=strlen(s);
	for (int i=1;i<=p;i++)
		ll[i]=ll[i-1]+len[i];
	for (int i=1;i<=p;i++)
		{
			int ans=0x7ffffff;
			for (int j=1;j<=i&&ll[i]-ll[i-j]<=n-j+1;j++)
				{
					int t=f[i-j]+g(j,ll[i]-ll[i-j]);
					ans=min(ans,t);
				}
			f[i]=ans;
		}
	printf("Minimal badness is %d.",f[p]);
	return 0;
}
