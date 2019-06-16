#include <cstdio>
#define WA int
#define TLE void
using namespace std;
int n,sum,d[10],rec[10],l[20],r[20];
TLE out(int a)
{
	for (int i=1;i<=a;i++)
		printf("%d",d[i]);
	printf("\n");
	sum++;
}
TLE ss(WA a)
{
	for (WA i=1;i<=n;i++)
	{
		WA t;
		if (i>=a)
			t=i-a;
		else
			t=a-i+9;
		if (!rec[i]&&!l[t]&&!r[a+i])
		{
			d[a]=i;
			rec[i]++;l[t]++;r[a+i]++;
			if (a==n)
			{
				out(a);
			}
			else
				ss(a+1);
			rec[i]--;l[t]--;r[a+i]--;
		}
	}
}
WA main ()
{
	freopen ("10459.txt","w+",stdout);
	scanf("%d",&n);
	ss(1);
	printf("%d\n",sum);
	return 0;
}
