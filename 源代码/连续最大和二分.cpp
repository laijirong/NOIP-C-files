#include<cstdio>
#include<algorithm>
using namespace std;
int a1[100001];
int ntot(int a,int b)
{
	if(a==b) return a1[a];
	int mid=(a+b)/2;
	int xa=ntot(a,mid),xb=ntot(mid+1,b);
	int amax=a1[mid],bmax=a1[mid+1],totx=0,toty=0;
	for(int i=mid;i>=a;i--) amax=max(totx+=a1[i],amax);
	for(int i=mid+1;i<=b;i++) bmax=max(toty+=a1[i],bmax);
	return max(max(xa,xb),amax+bmax); 
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a1[i]);
	printf("%d",ntot(1,n));
	return 0;
}
