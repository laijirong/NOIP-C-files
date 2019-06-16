//最大连续和 
#include<iostream>
#include<cstdio>
using namespace std;
int d[100010];
int f(int a,int b)
{
	if(a==b) return d[a];
	int mid=(a+b)/2;
	int t1=f(a,mid),t2=f(mid+1,b);
	
	int m1=d[mid],n1=d[mid];
	for(int i=mid-1;i>=a;i--)
	{
		m1+=d[i];
		if(m1>n1) n1=m1;
	}
	
	int m2=d[mid+1],n2=d[mid+1];
	for(int i=mid+2;i<=b;i++)
	{
		m2+=d[i];
		if(m2>n2) n2=m2;
	}
	int max=n1+n2;
	if(t1<t2) t1=t2;
	t2=max;
	if(t1<t2) t1=t2;
	return t1;
	
}
int main()
{
	//freopen("10096.in","r",stdin);
	//freopen("10096.out","w",stdout);
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	scanf("%d",&d[i]);
	printf("%d",f(1,N));
	//fclose(stdin);
	return 0;
}

