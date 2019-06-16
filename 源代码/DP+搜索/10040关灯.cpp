//10040. นุตฦ
#include <cstdio>
#include <algorithm>
using namespace std;
int n,v,wm[1010],d[1010],w[1010],f[1010][1010][2];
int main ()
{
	freopen ("10040.in","r",stdin);
	scanf("%d%d",&n,&v);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&d[i],&w[i]);
	for (int i=1;i<=n;i++)
		wm[i]=wm[i-1]+w[i];
	f[v][v][0]=f[v][v][1]=0;
	for (int i=v+1;i<=n;i++)
		{
			f[v][i][1]=f[v][i-1][1]+(wm[n]-wm[i-1]+wm[v]-w[v])*(d[i]-d[i-1]);
			f[v][i][0]=f[v][i][1]+(wm[n]-wm[i]+wm[v]-w[v])*(d[i]-d[v]);
		}
	for (int i=v-1;i>=1;i--)
		{
			f[i][v][0]=f[i+1][v][0]+(wm[n]-wm[v]+wm[i+1]-w[i+1])*(d[i+1]-d[i]);
			f[i][v][1]=f[i][v][0]+(wm[n]-wm[v]+wm[i]-w[i])*(d[v]-d[i]);
		}
	for (int i=v-1;i>=1;i--)
		for (int j=v+1;j<=n;j++)
			{
				int tmp=d[j]-d[i],t=wm[n]-wm[j]+wm[i],tt=wm[n]-wm[j-1]+wm[i-1];
				f[i][j][0]=min(f[i+1][j][0]+t*(d[i+1]-d[i]),f[i+1][j][1]+t*tmp);
				f[i][j][1]=min(f[i][j-1][1]+tt*(d[j]-d[j-1]),f[i][j-1][0]+tt*tmp);
			}
	printf("%d",min(f[1][n][0],f[1][n][1]));
	return 0;
} 
