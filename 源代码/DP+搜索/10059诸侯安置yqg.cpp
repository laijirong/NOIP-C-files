#include<cstdio>
using namespace std;
int n,f[210][210],l[210],m,ans;
int main()
{
	scanf("%d%d",&n,&m);
	if(!m)
	{
		printf("1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
		l[i*2-1]=l[i*2]=i*2-1;
	f[0][0]=1;
	for(int i=1;i<=2*n-1;i++)
		for(int j=1;j<=i;j++)
			for(int k=j-1;k<i;k++)
				f[i][j]=(f[i][j]+f[k][j-1]*(l[i]-j+1))%504;
	for(int i=m;i<=n*2-1;i++)
		ans=(ans+f[i][m])%504;
	printf("%d",ans%504);
	return 0;
}
