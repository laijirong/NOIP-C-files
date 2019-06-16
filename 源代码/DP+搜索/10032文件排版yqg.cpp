#include<cstdio>
#include<cstring>
using namespace std;
char a[1001];
int len[10001],f[10001],p,n,s,taxt[40][80];
int main()
{
	scanf("%d",&n);
	while(scanf("%s",a)==1)
	len[++p]=strlen(a);
	for(int i=1;i<n;i++)
		taxt[1][i]=500;
	taxt[1][n]=0;
	int tp,tot,t;
	for(int i=2;i<=40;i++)
	  	for(int j=i;j<=n;j++)
	  	{
	    	tp=(n-j)%(i-1);t=(n-j)/(i-1);
	    	tot=tp*t*t+(i-tp-1)*(t-1)*(t-1);
	    	taxt[i][j]=tot;
      	}
    for(int i=1;i<=p;i++)
    {
    	s=1;
    	f[i]=f[i-1]+taxt[1][len[i]];
    	int totlen=len[i],tlen=len[i];
    	for(int j=i-1;j>=1;j--)
    	{
    		if(totlen+len[j]+1<=n)
    	 	{
    	 		totlen+=len[j]+1;
    	 		tlen+=len[j];
    	 		int t1=f[j-1]+taxt[++s][tlen];
    	 		if(t1<f[i])f[i]=t1;
    	 	}
    	 	else break;
    	}
    }
   	printf("Minimal badness is %d.",f[p]);
	return 0;
}
