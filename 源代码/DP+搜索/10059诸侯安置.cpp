//10059. 诸侯安置
#include <cstdio>
using namespace std;
int n,k,ans,f[250][250];//数组？开小了(100） 
int main ()
{
//	freopen ("10059.in","r",stdin);
	scanf("%d%d",&n,&k);
	if (k<=2*n-1)
		{
			f[0][0]=1;
			for (int i=1;i<=2*n-1;i++)
				for (int j=1;j<=i;j++) 
					for (int l=j-1;l<i;l++)
					{
						if (i%2==0)
							f[i][j]=(f[i][j]+f[l][j-1]*(i-j))%504;
						else
							f[i][j]=(f[i][j]+f[l][j-1]*(i-j+1))%504;
					}
			for (int i=k;i<=2*n-1;i++) ans+=f[i][k];
		}
	printf("%d",ans%504);
	return 0;
}
