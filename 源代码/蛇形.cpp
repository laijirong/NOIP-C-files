//技巧；预测；dir预判方向，x=1，y=0是初始位置预判第一个位置 
#include <iostream>
#include <cstdio>
using namespace std;
int a[1000][1000],p=1,dir,x,y,tx,ty;
int ax[]={0,1,0,-1};
int ay[]={1,0,-1,0};
int main ()
{
	int m,n;
	cin>>m>>n;
	a[1][n+1]=a[m+1][n]=a[m][0]=1;
	for (x=1,y=0,dir=0;p<=m*n;)
		{
			tx=x+ax[dir];
			ty=y+ay[dir];
			if (a[tx][ty]!=0)
				{
					dir=(dir+1)%4;
					continue;
				}
			a[tx][ty]=p++;
			x=tx;y=ty;
			
		}
	for (int i=1;i<=m;i++)
		{
			for (int j=1;j<=n;j++)
			cout<<a[i][j]<<"\t";
			cout<<endl;
		}
	return 0;
	
}
