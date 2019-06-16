//10034. ¼¢¶öµÄÅ£
#include <cstdio>
using namespace std;
const int n=10000000+10;
int m,p,f[n],head[n];
struct ss
{
	int val,last;
}e[100010];
int main ()
{
//	freopen("10034.in","r",stdin);
	scanf("%d",&m);
	for (int i=1,t1,t2;i<=m;i++)
		{
			scanf("%d%d",&t1,&t2);
			e[++p].val=t2;
			e[p].last=head[t1];
			head[t1]=p;
		}
	for (int i=10000000,t;i>=1;i--)
		{
			f[i]=f[i+1];
			t=head[i];
			while (t)
			{
				if (f[i]<f[e[t].val+1]+e[t].val-i+1)
					f[i]=f[e[t].val+1]+e[t].val-i+1;
				t=e[t].last;
			}
		}
	printf("%d",f[1]);
	return 0;
}
