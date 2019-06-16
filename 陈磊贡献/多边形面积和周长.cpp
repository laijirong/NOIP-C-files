#include<cstdio>
#include<cmath>
#define pi 3.1415926
using namespace std;
int n,pos1,sum,sumans;
double pos2=9999999999.00,px,py,anss,ansl;
struct point
{
	double x,y,alpha;
} zy[100010],red[100010],ans[100010],e[100010],pp;
void sort(int a,int b)
{
	if(a==b) return ;
	int mid=(a+b)/2;
	sort(a,mid);	sort(mid+1,b);
	
	int p1=a,p2=mid+1,p=a;
	while(p1<=mid&&p2<=b)
	if(red[p1].alpha>red[p2].alpha)	e[p++]=red[p2++];
	else							e[p++]=red[p1++];
	
	for(int i=p1;i<=mid;i++)
	e[p++]=red[i];
	for(int i=p2;i<=b;i++)
	e[p++]=red[i];
	
	for(int i=a;i<=b;i++)
	red[i]=e[i];
}
double al(point po)
{
	if(po.x==0&&po.y>0) return pi/2;
	if(po.y==0)
	{
		if(po.x>0) return 0.0;
		if(po.x<0) return pi;
	}
	double answ=atan(po.y/po.x);
	if(po.x<0) answ+=pi;
	return answ;
}
int main()
{
	freopen("10420.in","r",stdin);
	freopen("10420.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&red[i].x,&red[i].y);
		if(red[i].y==pos2)
		if(red[i].x<red[pos1].x) pos1=i;
		if(red[i].y<pos2)
		{
			pos1=i;
			pos2=red[i].y;
		}
	}
	px=red[pos1].x;
	py=red[pos1].y;
	for(int i=1;i<=n;i++)
	{
		red[i].x-=px;
		red[i].y-=py;
		red[i].alpha=al(red[i]);
	}
	red[pos1].alpha=0.0;
	pp=red[pos1];
	for(int i=pos1;i>1;i--)
	red[i]=red[i-1];
	red[1]=pp;
	sort(2,n);
	zy[++sum]=red[1];
	for(int i=2;i<=n;i++)
	{
		if(red[i].alpha!=zy[sum].alpha)	zy[++sum]=red[i];
		if(red[i].alpha==0.0)	zy[++sum]=red[i];
		if(red[i].y>zy[sum].y) zy[sum]=red[i];
	}
	ans[++sumans]=zy[1];
	ans[++sumans]=zy[2];
	for(int i=3;i<=sum;i++)
	{
		ans[++sumans]=zy[i];
		while(1)
		if((ans[sumans-1].x-ans[sumans-2].x)*(ans[sumans].y-ans[sumans-2].y)-(ans[sumans].x-ans[sumans-2].x)*(ans[sumans-1].y-ans[sumans-2].y)<=0)
		ans[sumans-1]=ans[sumans--];
		else break;
	}
	ansl+=sqrt((ans[2].x-ans[1].x)*(ans[2].x-ans[1].x)+(ans[2].y-ans[1].y)*(ans[2].y-ans[1].y));
	for(int i=3;i<=sumans;i++)
	{
		anss+=(ans[i-1].x-ans[1].x)*(ans[i].y-ans[1].y)-(ans[i].x-ans[1].x)*(ans[i-1].y-ans[1].y);
		ansl+=sqrt((ans[i].x-ans[i-1].x)*(ans[i].x-ans[i-1].x)+(ans[i].y-ans[i-1].y)*(ans[i].y-ans[i-1].y));
	}
	ansl+=sqrt((ans[1].x-ans[sumans].x)*(ans[1].x-ans[sumans].x)+(ans[1].y-ans[sumans].y)*(ans[1].y-ans[sumans].y));
	anss=fabs(anss/2);
	printf("%.2lf %.2lf\n",anss,ansl);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
	
