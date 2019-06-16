#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int Max=1e5;
typedef long long lglg;
lglg sub,par,dep,ans[Max],tmp[Max];
lglg gcd(lglg a,lglg b)
{
	if(a%b==0)
		return b;
	return gcd(b,a%b);
}
lglg fp(lglg a,lglg b)
{
	lglg i;
	for (i=2;;i++)
		if(b<a*i)
            break;
    return i;
}
int jdg(lglg a)
{
	int bak=1;
	if (!ans[a])
		return 1;
	for (lglg i=a;i>=1;i--)
	{
		if (ans[i]==tmp[i])
			continue;
		if (tmp[i]>ans[i])
		{
			bak=0;
			break;
		}
		else
			break;
	}
	return bak;
}
int ss(lglg a,lglg b,lglg m,lglg d)
{
	int bak;
	if (d==dep)
	{
		if (a!=1) return 0;
		for (int i=1;i<=dep;i++)
			if (tmp[i]==b)
				return 0;
		tmp[d]=b;
		sort(tmp+1,tmp+1+d);
		if (jdg(d))
			memcpy(ans,tmp,sizeof(lglg));
		return 1;
	}
	bak=0;
	m=max(m,fp(a,b));
	lglg a1,b1,g;
	for (int i=m;;i++)
	{
		if (b*(dep+1-d)<=a*i)
            break;
        tmp[d]=i;
        a1=a*i-b,b1=b*i;
        g=gcd(a1,b1);
		a1=a1/g,b1=b1/g;
		if (ss(a1,b1,i+1,d+1))
			bak=1;
	}
	return bak;
}
int main ()
{
	scanf("%lld%lld",&sub,&par);
	memset(ans,-0x7fffffff,sizeof(ans));
	int g=gcd(sub,par);
	int a=sub/g,b=par/g;
	if (sub==1)
	{
		printf("1/%lld\n",par);
		return 0;
	}
	else
	{
		for (dep=1;;dep++)
			if (ss(a,b,fp(a,b),0)) break;
		for (int i=1;i<dep;i++)
			printf("1/%lld+",ans[i]);
		printf("1/%lld\n",ans[dep]);
	}
	return 0;
}