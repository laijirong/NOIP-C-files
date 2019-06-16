#include<cstdio>
#include<cstring>
using namespace std;
char str[1010];
struct red
{
	int d[1100],len;
	red(){}
	red(int a)
	{
		while(a)
		{
			d[++len]=a%10;
			a/=10;
		}
	}
	red(char *ss)
	{
		len=strlen(ss);
		for(int i=0;i<len;i++)
		d[i+1]=ss[len-i-1]-'0';
	}
	red out()
	{
		for(int i=len;i>=1;i--)
		printf("%d",d[i]);
	}
};
int max(int a,int b)
{
	if(a>b) return a;
	return b;
}
red operator +(red a,red b)
{
	red t;
	int w=0;
	t.len=max(a.len,b.len);
	for(int i=a.len+1;i<=b.len;i++)
	a.d[i]=0;
	for(int i=b.len+1;i<=a.len;i++)
	b.d[i]=0;
	for(int i=1;i<=t.len;i++)
	{
		t.d[i]=a.d[i]+b.d[i]+w;
		w=t.d[i]/10;
		t.d[i]%=10;
	}
	while(w)
	{
		t.d[++t.len]=w%10;
		w/=10;
	}
	return t;
}
int main()
{
	freopen("10119.in","r",stdin);
	freopen("10119.out","w",stdout);
	red A=0;
	while(scanf("%s",str)==1)
	A=A+str;
	A.out();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
