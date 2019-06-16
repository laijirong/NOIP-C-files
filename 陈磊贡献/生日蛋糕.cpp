#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int r[30],h[30],answer=0x7fffffff,v,n;
void dfs(int a,int b,int ans,int ce)
{  
	if(b<0)			return ;
	if(a>n+1)		return ;
	if(ans>=answer)	return ;
     
    if(b==0&&a==n+1)
    {
		ans+=r[1]*r[1];
		if(ans<answer) answer=ans;
		return ;
    }
    
	if(ans+r[1]*r[1]>answer)				return ;
	if(b-(r[a-1])*(r[a-1])*(h[a-1])*ce>0)	return ;
	
	for(int i=r[a-1]-1;i>=ce;i--)
    for(int j=h[a-1]-1;j>=ce;j--)
    {
		if(b-i*i*j>=0)
		{
			r[a]=i;
			h[a]=j;
			dfs(a+1,b-i*i*j,ans+(2*i*j),ce-1);
		}
	}
}
int main()
{
    scanf("%d%d",&v,&n);
    r[0]=sqrt(v);
    h[0]=sqrt(v);
    dfs(1,v,0,n);
    if(answer==0x7fffffff) printf("S=0\n");
      else printf("%d\n",answer);
    return 0;
}
