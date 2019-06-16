#include<cstdio>
using namespace std;
int n,c,t[200000],s[200000];
int main ()
{
	freopen ("message.in","r",stdin);
//	freopen ("message.out","w",stdout);
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d",&t[i]);
	for (int i=1; i<=n; i++)
		{
			s[i]=s[i-1];
			++c;
			if (s[i]==i)
				break;
		}
	printf("%d",c);

	fclose (stdin);
	fclose (stdout);
	return 0;
}
