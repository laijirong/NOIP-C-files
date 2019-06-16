#include<cstdio>
using namespace std;
int seat[110];
void out(int a)
{
	for(int i=1;i<=a;i++)
	  printf("%d",seat[i]);
	printf("\n");
}
void search(int a,int b)
{
	for(int i=1;i<=2;i++)
	  if(b>=i)
	  {
	    seat[a]=i;
	  	if(b==i) out(a);//所有情况列举完毕，递归自动返回上一级，即search(a-1,b+i);
		else search(a+1,b-i);
	  }
}

int main()
{
	int n;
	scanf("%d",&n);
	search(1,n);
	return 0;
}
