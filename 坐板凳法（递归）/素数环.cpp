#include<cstdio>
#include<cmath>
using namespace std;
int data[100],used[100],ss[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1};
void out(int a)
{
	for(int i=1;i<10;i++)
	  if(ss[data[i]+data[i+1]]==0||ss[data[1]+data[10]]==0)
	    return;
	for(int i=1;i<=10;i++)
	  printf("%d ",data[i]);
    printf("\n");
}
void search(int a)
{
  for(int i=2;i<=10;i++)
	  if(a<=10&&used[i]==0)
	  {
	    data[a]=i;
	    used[i]=1;
	    if(a==10)
	      out(a);
	    else 
		  search(a+1);
	    used[i]=0;
	  }
}
int main()
{
	 data[1]=1;
	search(2);
	return 0;
}
