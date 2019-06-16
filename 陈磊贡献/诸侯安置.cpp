#include <cstdio>
using namespace std;
int n,m,ans;
int d[210],f[210][210];
int main()
{
    scanf("%d%d",&n,&m);
    int t=2*n-1;
	for(int i=1;i<=n;i++) d[i*2-1]=d[i*2]=i*2-1;
	f[0][0]=1;
	
	for(int i=1;i<=t;i++)
	for(int j=1;j<=i;j++)
	for(int k=j-1;k<i;k++)
	f[i][j]=(f[i][j]+f[k][j-1]*(d[i]-j+1))%504;

    for(int i=m;i<=t;i++) 
	ans+=f[i][m];
	
    printf("%d\n",ans%504);
    fclose(stdout);
    return 0;
}
