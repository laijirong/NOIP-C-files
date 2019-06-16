//10133. ×Ö´®¾àÀë 
#include<cstdio>
#include<cmath>
#include<string.h>
using namespace std;
char a[2001],b[2001];
int l1,l2,k,s[2001][2001];
int g(char a,char b)
{
	int t=abs(int(a)-int(b));
	return t;
}
int min(int a,int b,int c)
{
	if(a>b) a=b;
	if(a>c) a=c;
	return a;
}
int main()
{
	freopen("10133.in","r",stdin);
	scanf("%s%s",&a[1],&b[1]);
	scanf("%d",&k);
	l1=strlen(&a[1]);
	l2=strlen(&b[1]);
	for(int i=1;i<=l1;i++)
	 s[i][0]=s[i-1][0]+k;
	for(int i=1;i<=l2;i++)
	 s[0][i]=s[0][i-1]+k;
	for(int i=1;i<=l1;i++)
	 for(int j=1;j<=l2;j++)
	  {
	  	s[i][j]=min(s[i-1][j]+k,s[i][j-1]+k,s[i-1][j-1]+g(a[i],b[j]));
	  }
	printf("%d",s[l1][l2]);
	fclose(stdout);
	return 0;
}
