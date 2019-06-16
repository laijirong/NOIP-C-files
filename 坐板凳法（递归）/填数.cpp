#include<cstdio>
#include<cmath> 
using namespace std;	
int data[20];
int used[100];
void out()
{
	if(int(sqrt(data[1]))!=sqrt(data[1]))
	  return;
	if(int(sqrt(data[2]*10+data[3]))!=sqrt(data[2]*10+data[3]))
	  return;
	if(int(sqrt(data[4]*100+data[5]*10+data[6]))!=sqrt(data[4]*100+data[5]*10+data[6]))
	  return;
	if(int(sqrt(data[7]*1000+data[8]*100+data[9]*10+data[10]))!=sqrt(data[7]*1000+data[8]*100+data[9]*10+data[10]))
	  return;
	if(data[4]==0||data[7]==0) return;
	printf("%d %d%d %d%d%d %d%d%d%d\n",data[1],data[2],data[3],data[4],data[5],data[6],data[7],data[8],data[9],data[10]);
}
void search(int a)
{
  for(int i=0;i<=9;i++)
	  if(used[i]==0&&a<=10)
	  {
	  	 
	    data[a]=i;
	    used[i]=1;
	    if(a==10)
	  	  out();
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
