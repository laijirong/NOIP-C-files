#include<cstdio>
using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int dep=0,ok=0;
struct ss
{
	int x,y;
	int d[3][3];
	int operator ==(ss b)
	{
	  for(int i=0;i<3;i++)
	    for(int j=0;j<3;j++)
		  if(d[i][j]!=b.d[i][j])
		    return 0;
	  return 1;
	}
};
void change(int &a,int &b)
{
	int t=a;a=b;b=t;
}
void read(ss &a)
{
	for(int i=0;i<3;i++)
	  for(int j=0;j<3;j++)
	  {
	 	scanf("%d",&a.d[i][j]);
	 	if(a.d[i][j]==0)
		  {a.x=i;a.y=j;}	 	
	 }
}
ss start,finish;
ss seat[100];
void search(int a,ss b)
{
	int tx,ty;
	ss tt;
	for(int i=0;i<4;i++)
	{
		if(ok) return;
		tx=b.x+dx[i];
		ty=b.y+dy[i];
		if(tx>=0&&tx<3&&ty>=0&&ty<3)
		 {
		 	tt=b;
		 	change(tt.d[b.x][b.y],tt.d[tx][ty]);
		 	tt.x=tx;tt.y=ty;
		 	seat[a]=tt;
		 	if(tt==finish)		
		 	  ok=1;		
		 	else
		 	  if(a+1<=dep) 
			    search(a+1,tt);		 		 		 	
		 }
	}
}
void out(ss a)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
	      printf("%d ",a.d[i][j]);
	    printf("\n");
	}
    printf("\n");	 
}
int main()
{
	read(start);
	read(finish);
	seat[0]=start;
	if(start==finish)
	{
		printf("0\n");
		out(start);return 0;
	}
	for(;;)
	{
		dep++;ok=0;
		search(1,start);
		if(ok) break;		
	}
    printf("%d\n",dep);
	for(int i=0;i<=dep;i++)
	 out(seat[i]);
	return 0;		
}
