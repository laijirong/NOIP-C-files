#include<cstdio>
using namespace std;
int data[100],used[100];
 void out(int a)
{
	for(int i=1;i<=a;i++)
	  printf("%d ",data[i]);
	printf("\n");
}
void search(int a)
{
	for(int i=1;i<=5;i++)
	  if(used[i]==0&&data[a-1]<i)
	  {
	    data[a]=i;
	    used[i]=1;
	    if(a==3)
	  	  out(a);
	    else 
		  search(a+1);
		used[i]=0;
	  }
}
int main()
{
	search(1);
	return 0;
}
