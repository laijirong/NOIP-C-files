//µ›πÈ¡∑œ∞
#include <cstdio>
//#include <iostream>
using namespace std;
int d[1000];
int f(int x,int y,int a)
{
	if (x==y)
		if (y==a) return 1;
		return -1;
		
		int mid=(x+y)/2;
		if (a<=mid) return f(x,mid,a);
		if (a>mid) return f(mid+1,y,a);
}

void swap(int a,int b)
{
	int t=b;b=a;a=t;
}

int main()
{
	int n,m,ju;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
			if (d[i]>d[j])
				swap(d[i],d[j]);
	scanf("%d",m);
	for (int i=1;i<=m;i++)
		{
			scanf("%d",&ju);
			printf("%d\n",f(1,n,ju));
		}
			
	return 0;
}
