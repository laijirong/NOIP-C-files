//10034. ¼¢¶öµÄÅ£(Çø¼ä£©
#include <cstdio>
#include <algorithm>
using namespace std;
int n,f[10000010];
struct cow
{
	int s,e;
	int operator < (cow other) const
	{
		if (s<other.s) return 1;//s<other.s;
		if (s>other.s) return 0;//s>other.s;
		return e<other.e;
	}
}d[100010];
int find(int a,int b,int c)
{
    if(a==b)
    {
    	if(d[a].s>=c) return a;
    	return n+1;
    }
	int mid=(a+b)/2;
    if(c<=d[mid].s) return find(a,mid,c);
    return find(mid+1,b,c);
}
int main ()
{
	freopen ("10034.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
			scanf("%d%d",&d[i].s,&d[i].e);
	sort(d+1,d+n+1);
	for (int i=n;i>=1;i--)
		{
			f[i]=f[i+1];
			int t=find(1,n,d[i].e+1);
			f[i]=max(f[i],f[t]+d[i].e-d[i].s+1);
		}
	printf("%d",f[1]);
	return 0;
}
