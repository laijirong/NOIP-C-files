#include <cstdio>
using namespace std;
int array[1000020];
int maxsum(int a,int b)
{
	if (a==b) return array[a];
	int mid=(a+b)/2;
	int lmax=maxsum(a,mid);
	int rmax=maxsum(mid+1,b);
	int temp=0,max1=-0x7fffffff,max2=-0x7fffffff;
	for(int i=mid;i>=a;i--)
		{
			temp+=array[i];
			if (temp>max1) max1=temp;
		}
	temp=0;
	for(int i=mid+1;i<=b;i++)
		{
			temp+=array[i];
			if (temp>max2) max2=temp;
		}
	int max=max1+max2;
	if (lmax>rmax) rmax=lmax;
	if (rmax>max) max=rmax;
	return max;
	
}
int main ()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&array[i]);
	printf("%d",maxsum(1,n));
	return 0;
}
