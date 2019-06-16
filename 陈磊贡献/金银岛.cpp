#include<cstdio>
#include<iostream>
using namespace std;
int T,zy[110],e[110];
double w,n,ans;
struct ss
{
	double wei,val,xn;
} red[110];
void sort(int a,int b)
{
	if(a==b) return ;
	int mid=(a+b)/2;
	sort(a,mid);
	sort(mid+1,b);
	
	int p1=a,p2=mid+1,p=a;
	while(p1<=mid&&p2<=b)
	if(red[zy[p1]].xn<red[zy[p2]].xn)
	e[p++]=zy[p2++];
	else e[p++]=zy[p1++];
	
	for(int i=p1;i<=mid;i++)
	e[p++]=zy[i];
	for(int i=p2;i<=b;i++)
	e[p++]=zy[i];
	
	for(int i=a;i<=b;i++)
	zy[i]=e[i];
}
int main()
{
	scanf("%d",&T);
	for(int mm=1;mm<=T;mm++)
	{
		scanf("%lf%lf",&w,&n);
		for(int i=1;i<=n;i++)
		{
			zy[i]=i;
			scanf("%lf%lf",&red[i].wei,&red[i].val);
			red[i].xn=red[i].val/red[i].wei;
		}
		sort(1,n);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=red[zy[i]].xn*min(w,red[zy[i]].wei);
			w-=min(w,red[zy[i]].wei);
			if(w==0) break ;
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}
