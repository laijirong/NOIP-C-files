//10293. ≥¬¿œ ¶∞· È
#include <cstdio>
#include <algorithm>
using namespace std;
int a,b,c,k,ans,aa[105],bb[105],cc[105],f[105][105][105];
int dp (int a,int b,int c)
{
	if (f[a][b][c]!=0) return f[a][b][c];
	int d=0,d1=0,d2=0,t;t=ans-a-b-c;
	if (a!=0) d=dp(a-1,b,c)+aa[a]*t;
	if (b!=0) d1=dp(a,b-1,c)+bb[b]*t;
	if (c!=0) d2=dp(a,b,c-1)+cc[c]*t;
	return f[a][b][c]=max(d,max(d1,d2));
}
int main ()
{
	freopen ("10293.in","r",stdin);
	scanf("%d%d%d",&a,&b,&c);
	for (int i=1;i<=a;i++) scanf("%d",&aa[i]);
	for (int i=1;i<=b;i++) scanf("%d",&bb[i]);
	for (int i=1;i<=c;i++) scanf("%d",&cc[i]);
	ans=a+b+c+1;
	printf("%d",dp(a,b,c));
	fclose(stdin);
	return 0;
}
