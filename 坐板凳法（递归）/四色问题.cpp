#include<cstdio>
using namespace std;
int n,flag;
int count=0;
int data[21][21],zata[21][21],cover[21],t[21];
void search(int a)
{
	for(int i=1;i<=4;i++)
	  if(a<=n)
	  {
	  flag=0;
	  cover[a]=i;
	  if(t[a]==0);
	  else
	  { 
	  for(int j=1;j<=t[a];j++)
	    if(zata[a][j]<a&&cover[a]==cover[zata[a][j]]) 
		  flag=1;                                                                      
	  }
      if(flag==0)
      {
      	if(a==n)  count++;
		else  search(a+1);
      }
	  }
}
int main()
{
	freopen("four.in","r",stdin);
	freopen("four.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	  {
	    scanf("%d",&data[i][j]);
	     if(data[i][j]==1)
	       zata[i][++t[i]]=j;
      }
      search(1);
      printf("%d",count);
    fclose(stdout);
	return 0;
}
