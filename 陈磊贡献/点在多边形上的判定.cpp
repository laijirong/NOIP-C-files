#include<iostream>
#include<cstdio>
using namespace std;
int n,m,sum,getans;
int ans[3010];
struct Point
{
	double x,y;
} pp[3010];
struct POINT
{
	double x,y;
} p[3010],point[5];
struct PEAK
{
	double x,y;
} q[3010];
struct LINE
{
	double x1,y1,x2,y2;
} l[3010];
struct PL
{
	double x0,x1,y;
} pl[3010];
double mult(Point a, Point b, Point c)  
{
	return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}
int intersect(Point aa, Point bb, Point cc, Point dd)  
{
	if(max(aa.x,bb.x)<min(cc.x,dd.x))	return 0;
	if(max(aa.y,bb.y)<min(cc.y,dd.y))	return 0;
	if(max(cc.x,dd.x)<min(aa.x,bb.x))	return 0;
	if(max(cc.y,dd.y)<min(aa.y,bb.y))	return 0;
	if(mult(cc,bb,aa)*mult(bb,dd,aa)<0)	return 0;
	if(mult(aa,dd,cc)*mult(dd,bb,cc)<0)	return 0;
	return 1;  
}
void judge3(LINE a,PL b)
{
	pp[1].x=a.x1;pp[1].y=a.y1;
	pp[2].x=a.x2;pp[2].y=a.y2;
	pp[3].x=b.x0;pp[3].y=b.y;
	pp[4].x=b.x1;pp[4].y=b.y;
	if(intersect(pp[1],pp[2],pp[3],pp[4])==1) sum++;
}
int judge2(LINE a,PL b)
{
	if(b.y==min(a.y1,a.y2)) return 1;
	return 0;
}
int judge1(LINE a,PL b)
{
	double t1=min(a.x1,a.x2);
	double t2=min(a.y1,a.y2);
	double t3=max(a.x1,a.x2);
	double t4=max(a.y1,a.y2);
	if((b.x1-a.x1)*(a.y2-a.y1)-(a.x2-a.x1)*(b.y-a.y1)==0&&b.x1<=t3)
	{
		getans=1;
		return 1;
	}
	return 0;
}
int  judge0(LINE a,PL b)
{
	double t1=min(a.x1,a.x2);
	double t2=min(a.y1,a.y2);
	double t3=max(a.x1,a.x2);
	double t4=max(a.y1,a.y2);
	if(t2<=b.y&&t1<=b.x1&&t4>=b.y&&t3>=b.x0) return 0;
	return 1;
}
void judge(LINE a,PL b)
{
	if(judge0(a,b)==1) return;
	if(judge1(a,b)==1) return;
	if(judge2(a,b)==1) return;
	judge3(a,b);
}
int main()
{
	freopen("10421.in","r",stdin);
	freopen("10421.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%lf%lf",&q[i].x,&q[i].y);
	for(int i=1;i<n;i++)
	{
		l[i].x1=q[i].x;l[i].y1=q[i].y;
		l[i].x2=q[i+1].x;l[i].y2=q[i+1].y;
	}
	l[n].x1=q[n].x;l[n].y1=q[n].y;
	l[n].x2=q[1].x;l[n].y2=q[1].y;
	for(int i=1;i<=m;i++)
	scanf("%lf%lf",&p[i].x,&p[i].y);
	for(int i=1;i<=m;i++)
	{
		pl[i].x0=-100001;
		pl[i].x1=p[i].x;
		pl[i].y=p[i].y;
	}
	for(int i=1;i<=m;i++)
	{
		sum=0;
		for(int j=1;j<=n;j++)
		{
			if(getans==1)
			{
				sum=1;
				getans=0;
				break;
			}
			judge(l[j],pl[i]);
		}
		if(sum%2==1) ans[i]=1;
	}
	for(int i=1;i<=m;i++)
	if(ans[i]==1)	printf("YES\n");
	else			printf("NO\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
