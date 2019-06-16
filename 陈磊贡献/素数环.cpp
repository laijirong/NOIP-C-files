#include<cstdio>
using namespace std;
int seat[20],used[20];
void out()
{
	for(int i=1;i<10;i++)
	printf("%d ",seat[i]);
	printf("%d\n",seat[10]);
}
int check(int a,int b)
{
	int flag=1,t=a+b;
	for(int i=2;i<t;i++)
	if(t%i==0)
	{
		flag=0;
		break;
	}
	return flag;
}
void search(int a)
{
	if(a==11&&check(seat[1],seat[10]))	out();
	if(a==11) return ;
	
	for(int i=1;i<=10;i++)
	if(used[i]==0&&check(seat[a-1],i))
	{
		seat[a]=i;
		used[i]=1;
		search(a+1);
		used[i]=0;
	}
}
int main()
{
	search(1);
	return 0;
}
