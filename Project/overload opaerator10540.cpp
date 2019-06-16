/*overload operatror*/
#include <cstdio>
using namespace std;
const int Max=1e5;
int isub,ipar,dep,per,send,ans[Max];
void swp(int &a,int &b)
{
	int t=a;a=b;b=t;
}
int gcd(int a,int b)
{
	if (a<b)
		swp(a,b);
	if (a%b!=0)
		gcd(b,a%b);
	else
		return b;
}
struct s{
	int sub,par,tmp[Max];
	int operator -(s a)
	{
//		return float(gcd(a,this->b)*(a-this->b)/(a*this->b/gcd(a,this->b)));
	}
}e[1000];
void out(int a)
{
	for (int i=1;i<dep;i++)
		printf("1/%d+",ans[i]);
	printf("%d",ans[dep]);
}
void compare(int a)
{
	if (e[per].tmp[a]==e[per].tmp[a])
		compare(a-1);
	else
		for (int i=1;i<=send;i++)
			ans[i]=e[per].tmp[i];

}
void ss(int a,int r,int dpt)
{
	for (int i=1;;i++)
	{
		
	}
}
int main ()
{
	scanf("%d%d",&isub,&ipar);
	for (int i=1;;i++)
	{
		dep++;
		ss(i,float(isub/ipar),dep);
	}
	return 0;
}
