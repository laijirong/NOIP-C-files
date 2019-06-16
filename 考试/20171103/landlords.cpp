#include<cstdio>
#include <algorithm>
using namespace std;
int t,n,ans,a[60],b[60];
int main ()
{
//	freopen ("landlords.in","r",stdin);
//	freopen ("landlords.out","w",stdout);
	scanf("%d%d",&t,&n);
	for (int i=1; i<=n; i++)
		scanf("%d%d",&a[i],&b[i]);
	sort(a+1,a+1+n);
	for (int i=1; i<=t; i++)
		{
			if (n==4)
				{
					if ((a[1]!=a[2]&&a[2]==a[3]&&a[2]==a[4])||(a[1]==a[2]&&a[1]==a[3]&&a[1]!=a[4])||(a[1]==a[2]&&a[1]==a[3]&&a[1]==a[4]))
						ans+=1;
					if (a[1]==a[2]&&a[1]!=a[3]&&a[3]==a[4])
						ans+=2;
					if ((a[3]==a[2]&&a[1]!=a[3]&&a[3]!=a[4]&&a[1]!=a[4])||(a[1]!=a[2]&&a[2]!=a[3]&&a[1]!=a[3]&&a[3]==a[4])||(a[1]==a[2]&&a[2]!=a[3]&&a[4]!=a[3]&&a[3]!=a[4]))
						ans+=3;
					if (a[1]!=a[2]&&a[1]!=a[3]&&a[1]!=a[4]&&a[2]!=a[3]&&a[2]!=a[4]&&a[3]!=a[4])
						ans+=4;
				}
			if (n==3)
				{
					if (a[1]==a[2]&&a[1]==a[3])
						ans+=1;
					if (a[1]==a[2]&&a[1]!=a[3]||a[1]!=a[2]&&a[2]==a[3])
						ans+=2;
					if (a[1]!=a[2]&&a[1]!=a[3]&&a[2]!=a[3])
						ans+=3;
				}
			if (n==2)
				{
					if (a[1]==a[2])
						ans+=1;
					if (a[1]!=a[2])
						ans+=2;
				}

		}
	printf("%d",ans);
//	fclose (stdin);
//	fclose (stdout);
	return 0;
}
