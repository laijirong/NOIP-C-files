#include<cstdio>
using namespace std;
int str[32768];
void out(int a)
{
	for(int i=1;i<=a;i++)
	  printf("%d",str[i]);
	printf("\n");  
	
}
void search(int a,int b)
{
	for(int i=1;i<=2;i++)
	  if(b>=i*2)
	  {
		str[a]=i*2;
		if(b==i*2) out(a);
		else search(a+1,b-(i*2));
      }
}
int main()
{
	int n;
	scanf("%d",&n);
	search(1,n);
	return 0;
}
