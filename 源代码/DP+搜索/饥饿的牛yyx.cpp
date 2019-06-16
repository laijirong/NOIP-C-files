#include<cstdio>
using namespace std;
int f[100100],n;
struct mlong
{
int s,e;
bool operator < (mlong b) const
{
	return s<b.s;
}
}num[100100];
void change(mlong &a,mlong &b)
{
	mlong t=a;a=b;b=t;
}
void sort(int a,int b)
{
	mlong val=num[(a+b)/2];
	if(a==b) return;
	int i=a-1,j=b+1;
	while(1)
	{
		do i++;while(num[i]<val);
		do j--;while(val<num[j]);
		if(i>=j) break;
		change(num[i],num[j]);
	}
	sort(a,j);
	sort(j+1,b);
}	
int find(int a,int b,int c)
{
    if(a==b)
    {
    	if(num[a].s>=c) return a;
    	return n+1;
    }
	int mid=(a+b)/2;
    if(c<=num[mid].s) return find(a,mid,c);
    return find(mid+1,b,c);
}
int main()
{
	freopen("ss.in","r",stdin);
	freopen("ss.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d%d",&num[i].s,&num[i].e);
	  sort(1,n);
    int t;
    for(int i=n;i>=1;i--)
      {
      	f[i]=f[i+1];
      	t=find(1,n,num[i].e+1);
      	if(f[t]+num[i].e-num[i].s+1>f[i])
      	f[i]=f[t]+num[i].e-num[i].s+1;
      }
    printf("%d",f[1]);
	fclose(stdout);
	return 0;
}
