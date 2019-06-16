#include <cstdio>
int c[10001],ans[10001];
int k,max,min;
int gcd(int a,int b)
{
	if(a%b==0)
	return b;
	else
	return gcd(b,a%b);
}
int red(int a,int b)
{
	int m=a,n=b;
	while(a||b)
	{
		int tt=gcd(m,n);
		if(tt==1)
		break;
		m/=tt;
		n/=tt;
	}
	if(m==1)
	return n;
	return 0;
}
int search(int a,int b)
{
	if(k==max)
	{
		if((a==1)&&(b>=min))
		{
			c[k]=b;
			if((b<ans[k])||(ans[k]==0))
			{
				for(int j=1;j<=k;j++)
				ans[j]=c[j];
			}
			return 1;
		}
		return 0;
	}
	int flag=0,t=min;
	for(int i=min;i<=(max-k+1)*b/a;i++)
	{
		c[k]=i;
		int B=b*i,A=a*i-b;
		if(A<0)  continue;
		int gc=gcd(B,A);
		A/=gc;
		B/=gc;
		k++;
		min=i+1;
		if (search(A,B))
		flag=1;
		k--;
		min=t;
	}
	return flag;
}
int main()
{
	freopen("10540.in","r",stdin);
	freopen("10540.out","w",stdout);
	int x,y;
	scanf("%d%d",&x,&y);
	if(red(x,y))
	{
		printf("1/%d\n",red(x,y));
		return 0;
	}
	for(int i=1;;i++)
	{
		k=1;max=i;min=1;
		if (search(x,y))
		{
			for(int j=1;j<i;j++)
			printf("1/%d+",ans[j]);
			printf("1/%d\n",ans[i]);
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
