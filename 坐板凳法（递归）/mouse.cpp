#include<cstdio>
#include<string>
#include<cstdlib>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int row,col,a,map[20][20],used[20][20];
int best=300;
struct sxy
{
	int x;
	int y;
}way[300],bestway[300];
void copy(int a)
{
	for(int i=1;i<=a;i++)
	bestway[i]=way[i];
}
int search(int a,int x,int y)
{
	int tx,ty;
	for(int i=0;i<=3;i++)
	{  
	  tx=x+dx[i];ty=y+dy[i];
	  if(tx>=1&&tx<=row&&ty>=1&&ty<=col&&map[tx][ty]!=1&&used[tx][ty]==0)	
	  {  way[a].x=tx;
	     way[a].y=ty;
	     used[tx][ty]=1;
	   if(tx==row&&ty==col)
	   {
	   	if(a<best)
	   	{
	   		best=a;
	   		copy(a);
	   	}
	   }
	  	else
	  	if(a+row-tx+col-ty<best)
	  	search (a+1,tx,ty);
	  	used[tx][ty]=0;
	  }
	}	
}
int main()
{
	//freopen("mouse.in","r",stdin);
	//freopen("mouse.out","w",stdout);
	scanf("%d%d",&row,&col);
	 for(int i=1;i<=row;i++)
	   for(int j=1;j<=col;j++)
	scanf("%d",&map[i][j]);	
	way[1].x=way[1].y=1;
	used[1][1]=1;
	search(2,1,1);
	printf("%d\n",best);
	for(int i=1;i<=best;i++)	
	printf("%d %d\n",bestway[i].x,bestway[i].y);
	//fclose(stdout);
	return 0;
}
