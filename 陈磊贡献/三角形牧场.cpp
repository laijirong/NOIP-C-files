#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=40+5;
int a[maxn];
bool f[888][888];
int n;
double maxx=-1;
bool Tri(int i,int j,int k)
{
	if(i+j>k&&i+k>j&&k+j>i)	return 1;
    else					return 0;
}
double Helen(double i,double j,double k)
{
	double p;
	p=(i+j+k)/2;
	return sqrt(p*(p-i)*(p-j)*(p-k));
}
int main()
{
	freopen("10137.in","r",stdin);
	freopen("10137.out","w",stdout);
	scanf("%d",&n);
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		tot+=a[i];
	}
	int half=tot/2;
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	for(int j=half;j>=0;j--)
	for(int k=j;k>=0;k--)
	if(j>=a[i]&&f[j-a[i]][k]||k>=a[i]&&f[j][k-a[i]])
	f[j][k]=1;
	
	for(int i=half;i>=1;i--)
	for(int j=i;j>=1;j--)
	if(f[i][j])
	{
		int k=tot-i-j;
		if(Tri(i,j,k))
		{
			double val=Helen(i,j,k);
			if(val>maxx)maxx=val;
		}
	}
	if(maxx==-1)	 printf("-1\n");
	else 	printf("%d\n",int(maxx*100));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
