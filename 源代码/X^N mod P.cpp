//µİ¹é£¬²»ÊìÏ¤£¬²ğb£¬b/2£¬ÎªÆæ*a 
#include <cstdio>
using namespace std;
int f(int a,int b,int c)
{
	if (b==0) return 1%c;
	int t=f(a,b/2,c);
	t=t*t%c;
	if (b%2==1) 
		return (t*(a%c))%c;
	else return t;
}

int main ()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d^%d mod %d=%d",a,b,c,f(a,b,c));
	return 0;
}
