#include<cstdio>
using namespace std;
int h,l,a,b,c,d;
int dx[]={2,1,-1,-2,-2,-1,1,2},dy[]={1,2,2,1,-1,-2,-2,-1},used[100][100];
long long tt=0;
void meme(int x,int y)
{
	int tx,ty;
	for(int i=0;i<=7;i++)
	{
		tx=x+dx[i];ty=y+dy[i];
		if(tx>=1&&tx<=h&&ty>=1&&ty<=l&&used[tx][ty]==0)
		 {used[tx][ty]=1;;
		  if(tx==c&&ty==d)  	
		  tt++;
		 else meme(tx,ty);
		 used[tx][ty]=0;
		 }
	}
}
int main()
{
	//freopen
	scanf("%d%d%d%d%d%d",&h,&l,&a,&b,&c,&d);
	if(a==c&&b==d)
	{
		printf("1");
		return 0;
	}
	used[a][b]=1;
	meme(a,b);
	printf("%lld",tt);
	return 0;
}
