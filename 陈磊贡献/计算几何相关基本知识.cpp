#include<cstdio>
#include<cmath>
# define pi 3.1415926
using namespace std;
int sea;
double alpha;
struct point
{
	double x,y;
} p,o,a1,a2,b1,b2;
int deal(point aa1,point aa2,point bb1,point bb2)
{
	double xx,yy,r1,r2;
	xx=aa1.x;yy=aa1.y;
	r1=(aa2.x-xx)*(bb1.y-yy)-(bb1.x-xx)*(aa2.y-yy);
	r2=(aa2.x-xx)*(bb2.y-yy)-(bb2.x-xx)*(aa2.y-yy);
	if(r1*r2>=0)	return 1;
	
	xx=bb1.x;yy=bb1.y;
	r1=(bb2.x-xx)*(aa1.y-yy)-(aa1.x-xx)*(bb2.y-yy);
	r2=(bb2.x-xx)*(aa2.y-yy)-(aa2.x-xx)*(bb2.y-yy);
	if(r1*r2>=0)	return 1;
	return 0;
}
void red(point po,point l1,point l2,double &xx,double &yy)
{
	if(l1.x==l2.x)
	{
		xx=l1.x;yy=po.y;
		return ;
	}
	if(l1.y==l2.y)
	{
		xx=po.x;yy=l1.y;
		return ;
	}
	double k1,k2,b1,b2;
	k1=(l1.y-l2.y)/(l1.x-l2.x);
	b1=l1.y-l1.x*k1;
	k2=-(1/k1);
	b2=po.y-po.x*k2;
	xx=(b2-b1)/(k1-k2);
	yy=k1*xx+b1;
	return ;
}
double rmin(double a,double b)
{
	if(a<b) return a;
	return b;
}
double rmax(double a,double b)
{
	if(a>b) return a;
	return b;
}
void sixth(point po,point l1,point l2)
{
	point poo;
	double ans;
	red(po,l1,l2,poo.x,poo.y);
	
	if(poo.x>=rmin(l1.x,l2.x)&&poo.x<=rmax(l1.x,l2.x)&&poo.y>=rmin(l1.y,l2.y)&&poo.y<=rmax(l1.y,l2.y))
	{
		double s=(l2.x-l1.x)*(po.y-l1.y)-(po.x-l1.x)*(l2.y-l1.y);
		double dd=(l1.x-l2.x)*(l1.x-l2.x)+(l1.y-l2.y)*(l1.y-l2.y);
		dd=sqrt(dd);
		ans=fabs(s/dd);
		printf("%.2lf\n",ans);
		return ;
	}
	else
	{
		double s1=(po.x-l1.x)*(po.x-l1.x)+(po.y-l1.y)*(po.y-l1.y);
		double s2=(po.x-l2.x)*(po.x-l2.x)+(po.y-l2.y)*(po.y-l2.y);
		s1=sqrt(s1);s2=sqrt(s2);
		ans=rmin(s1,s2);
		printf("%.2lf\n",ans);
		return ;
	}
}
void fifth(point po,point l1,point l2)
{
	double k1,k2,b1,b2,xx,yy;
	if(l1.x==l2.x)
	{
		xx=l1.x;yy=po.y;
		printf("%.2lf %.2lf\n",2*xx-po.x,2*yy-po.y);
		return ;
	}
	if(l1.y==l2.y)
	{
		xx=po.x;yy=l1.y;
		printf("%.2lf %.2lf\n",2*xx-po.x,2*yy-po.y);
		return ;
	}
	k1=(l1.y-l2.y)/(l1.x-l2.x);
	b1=l1.y-l1.x*k1;
	k2=-(1/k1);
	b2=po.y-po.x*k2;
	xx=(b2-b1)/(k1-k2);
	yy=k1*xx+b1;
	printf("%.2lf %.2lf\n",2*xx-po.x,2*yy-po.y);
}
void forth(point po,point l1,point l2)
{
	if(l1.x==l2.x)
	{
		printf("%.2lf %.2lf\n",l1.x,po.y);
		return ;
	}
	if(l1.y==l2.y)
	{
		printf("%.2lf %.2lf\n",po.x,l1.y);
		return ;
	}
	double k1,k2,b1,b2,xx,yy;
	k1=(l1.y-l2.y)/(l1.x-l2.x);
	b1=l1.y-l1.x*k1;
	k2=-(1/k1);
	b2=po.y-po.x*k2;
	xx=(b2-b1)/(k1-k2);
	yy=k1*xx+b1;
	printf("%.2lf %.2lf\n",xx,yy);
}
void third(point x1,point x2,point y1,point y2)
{
	double tpx,tpy,xx,yy;
	tpx=(y2.x-y1.x)*(x1.y-x2.y)-(x2.x-x1.x)*(y1.y-y2.y);
	tpy=(x1.y-y1.y)*(x2.x-x1.x)*(y2.x-y1.x)+y1.x*(y2.y-y1.y)*(x2.x-x1.x)-x1.x*(x2.y-x1.y)*(y2.x-y1.x);
	xx=tpy/tpx;
	tpx=(x1.x-x2.x)*(y2.y-y1.y)-(x2.y-x1.y)*(y1.x-y2.x);
	tpy=x2.y*(x1.x-x2.x)*(y2.y-y1.y)+(y2.x-x2.x)*(y2.y-y1.y)*(x1.y-x2.y)-y2.y*(y1.x-y2.x)*(x2.y-x1.y);
	yy=tpy/tpx;
	printf("%.2lf %.2lf\n",xx,yy);
}
void second(point aa1,point aa2,point bb1,point bb2)
{
	point o,s,e;
	o.x=o.y=0;
	s.x=aa2.x-aa1.x;
	s.y=aa2.y-aa1.y;
	e.x=bb2.x-bb1.x;
	e.y=bb2.y-bb1.y;
	double re1=s.y/s.x,re2=e.y/e.x;
	re1=atan(re1);re2=atan(re2);
	if(s.x<0&&s.y>0) re1+=pi;
	if(e.x<0&&e.y>0) re2+=pi;
	if(s.x<0&&s.y<0) re1+=pi;
	if(e.x<0&&e.y<0) re2+=pi;
	if(s.x==0)
	{
		if(s.y>0)	re1= pi/2;
		else		re1=-pi/2;
	}
	if(e.x==0)
	{
		if(e.y>0)	re2= pi/2;
		else		re2=-pi/2;
	}
	if(s.y==0)
	{
		if(s.x>0)	re1=0.00;
		else		re1=pi;
	}
	if(e.y==0)
	{
		if(e.x>0)	re2=0.00;
		else		re2=pi;
	}
	re1=fabs(re1-re2);
	if(re1>=pi) re1=2*pi-re1;
	printf("%.2lf\n",re1);
}
void first(point pp,point oo,double al)
{
	point tp;
	pp.x-=oo.x;
	pp.y-=oo.y;
	tp.x=pp.x*cos(al)-pp.y*sin(al)+oo.x;
	tp.y=pp.y*cos(al)+pp.x*sin(al)+oo.y;
	printf("%.2lf %.2lf\n",tp.x,tp.y);
}
int main()
{
	freopen("10419.in","r",stdin);
	freopen("10419.out","w",stdout);
	while(scanf("%d",&sea)==1)
	{
		if(sea==1)
		{
			scanf("%lf%lf%lf%lf%lf",&p.x,&p.y,&o.x,&o.y,&alpha);
			alpha=-alpha;
			first(p,o,alpha);
			continue ;
		}
		if(sea==2)
		{
			scanf("%lf%lf%lf%lf",&a1.x,&a1.y,&a2.x,&a2.y);
			scanf("%lf%lf%lf%lf",&b1.x,&b1.y,&b2.x,&b2.y);
			second(a1,a2,b1,b2);
			continue ;
		}
		if(sea==3)
		{
			scanf("%lf%lf%lf%lf",&a1.x,&a1.y,&a2.x,&a2.y);
			scanf("%lf%lf%lf%lf",&b1.x,&b1.y,&b2.x,&b2.y);
			if(deal(a1,a2,b1,b2)) printf("NO\n");
			else third(a1,a2,b1,b2);
			continue ;
		}
		if(sea==4)
		{
			scanf("%lf%lf%lf%lf%lf%lf",&a1.x,&a1.y,&b1.x,&b1.y,&b2.x,&b2.y);
			if(a1.x/a1.y==b1.x/b1.y) printf("%.2lf %.2lf\n",a1.x,a1.y);
			else forth(a1,b1,b2);
			continue ;
		}
		if(sea==5)
		{
			scanf("%lf%lf%lf%lf%lf%lf",&a1.x,&a1.y,&b1.x,&b1.y,&b2.x,&b2.y);
			if(a1.x/a1.y==b1.x/b1.y) printf("%.2lf %.2lf\n",a1.x,a1.y);
			else fifth(a1,b1,b2);
			continue ;
		}
		if(sea==6)
		{
			scanf("%lf%lf%lf%lf%lf%lf",&a1.x,&a1.y,&b1.x,&b1.y,&b2.x,&b2.y);
			if(a1.x/a1.y==b1.x/b1.y) printf("0.00\n");
			else sixth(a1,b1,b2);
			continue ;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
