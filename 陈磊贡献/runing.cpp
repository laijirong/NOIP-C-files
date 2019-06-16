#include<iostream>
#include<cstdio>
using namespace std;
int t,n,sum,pos;
double vv,xx,minn,maxx;
struct ss
{
	int dis,spe;
} red[100010];
int main()
{
	freopen("runing.in","r",stdin);
	freopen("runing.out","w",stdout);
	scanf("%d",&t);
	for(int mm=1;mm<=t;mm++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		scanf("%d%d",&red[i].dis,&red[i].spe);
		sum=0;
		for(int i=1;i<=n;i++)
		{
			pos=0;minn=0;maxx=0x7fffffff;
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue ;
				vv=red[i].spe-red[j].spe;
				xx=red[j].dis-red[i].dis;
				if(vv==0)
				{
					if(red[i].dis>red[j].dis) continue ;
					else
					{
						pos=1;
						break;
					}
				}
				if(vv>0) minn=max(minn,xx/vv);
				if(vv<0) maxx=min(maxx,xx/vv);
				if(minn>=maxx)
				{
					pos=1;
					break;
				}
			}
			if(pos==0) sum++;
		}
		printf("%d\n",sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
