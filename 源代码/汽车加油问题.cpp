//#10049. ¼ÓÓÍÎÊÌâ
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
float t=99999.00,s,m,rate,cst,dis[200],p[200],f[200],ans=t;
int main ()
{
	freopen ("10049.in","r",stdin);
	scanf("%f%f%f%f%d",&s,&m,&rate,&cst,&n); 
	for (int i=1;i<=n;i++)
		{
			scanf("%f%f",&dis[i],&p[i]);
			p[i]/=100;
		}
	for (int i=1;i<=n;i++)
		f[i]=t;f[0]=cst;
	for (int i=1;i<=n;i++)
		for (int j=i-1;j>=0;j--)
			{
				if (dis[i]-dis[j]>m*rate) break;
				if (dis[i]-dis[j]>m/2*rate)
					f[i]=min(f[i],f[j]+p[i]*((dis[i]-dis[j])/rate)+2);
			}
	for (int i=n;i>=0;i--)
		{
			if (s-dis[i]>m*rate) break;
			ans=min(ans,f[i]);
		}
	printf("%.2f",ans);
	return 0;
}
