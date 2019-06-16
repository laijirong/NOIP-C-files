//10133. ×Ö´®¾àÀë
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
char s[2010],s1[2010];
int k,l,ll,ans,f[2010][2010];
int main ()
{
	freopen ("10133.in","r",stdin);
	scanf("%s%s%d",&s[1],&s1[1],&k);
	l=strlen(&s[1]);ll=strlen(&s1[1]);
	for (int i=1;i<=l;i++) f[i][0]=k*i;
	for (int i=1;i<=ll;i++) f[0][i]=k*i;
	for (int i=1;i<=l;i++)
		for (int j=1;j<=ll;j++)
			f[i][j]=min(f[i-1][j-1]+abs(s[i]-s1[j]),min(f[i-1][j]+k,f[i][j-1]+k));
	printf("%d",f[l][ll]);
	fclose(stdin);
	return 0;
}
