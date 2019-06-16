#include<cstdio>
#include<cmath>
int n;
double ans,s;
struct point
{
	double x,y;
} p,p1,p2;
using namespace std;
int main()
{
	scanf("%d",&n);
	scanf("%lf%lf%lf%lf",&p.x,&p.y,&p1.x,&p1.y);
	for(int i=1;i<=n-2;i++)
	{
		scanf("%lf%lf",&p2.x,&p2.y);
		s=(p1.x-p.x)*(p2.y-p.y)-(p2.x-p.x)*(p1.y-p.y);
		ans+=s;
		p1=p2;
	}
	ans=fabs(ans)/2;
	printf("%.1lf\n",ans);
	return 0;
}
