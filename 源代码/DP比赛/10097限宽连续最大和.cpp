#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,ans,db[100010],f[100010],s[100010],qz[100010],pos[100010];
int main ()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&db[i]);
	for (int i=1;i<=n;i++)
		qz[i]=db[i]+qz[i-1];

	int t,p1=1,p2=1;
	for (int i=1;i<=n;i++)
		{
			t=db[i]-qz[i];
			while (t>=s[p1]&&p2>=p1)
				p2--;
			s[++p2]=t;
			pos[p2]=i;
			if (i-pos[p1]+1>m)
				p1++;
			f[i]=s[p1]+qz[i];
		}
	for (int i=1;i<=n;i++)
		ans=max(ans,f[i]);
	printf("%d",ans);
	return 0;
}
