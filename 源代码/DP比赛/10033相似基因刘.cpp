#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int DNA[][10]={{0},{0,5,-1,-2,-1,-3},{0,-1,5,-3,-2,-4},{0,-2,-3,5,-2,-2},{0,-1,-2,-2,5,-1},{0,-3,-4,-2,-1}};
char str[3][110];
int f[110][110],data[110][110];
int dp(int a,int b)
{
	if(f[a][b]!=0) 
	 return f[a][b];
	if(a==0||b==0)
	 {
	 int t=0;
	 if(a==0)
	  { 
	  for(int j=b;j>=0;j--)
	   t+=DNA[5][data[2][j]];
	  return f[a][b]=t;
      }
     if(b==0) 
	  {
	  for(int j=a;j>=0;j--) 
	   t+=DNA[5][data[1][j]]; 
	  return f[a][b]=t;
	  }
	 } 
	int t1=data[1][a],t2=data[2][b],f1,f2,f3;
    f1=dp(a-1,b-1)+DNA[t1][t2];
	f2=dp(a-1,b)+DNA[t1][5];
	f3=dp(a,b-1)+DNA[5][t2];
	f[a][b]=max(f1,max(f2,f3));
	return f[a][b];  
}
int main()
{
	int l[3];
//	freopen("ss.in","r",stdin);
//	freopen("ss.out","w",stdout);
	scanf("%d%s%d%s",&l[1],&str[1][1],&l[2],&str[2][1]);
	for(int i=1;i<=2;i++)
	for(int j=1;j<=l[i];j++)
	  {
	    if(str[i][j]=='A') data[i][j]=1;
		if(str[i][j]=='C') data[i][j]=2;
		if(str[i][j]=='G') data[i][j]=3;
		if(str[i][j]=='T') data[i][j]=4;
	  }
	printf("%d",dp(l[1],l[2]));
//	freopen(stdout);
	return 0;
}
