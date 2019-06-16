#include<cstdio>
using namespace std;
int posx,posy,poss,ins;
int d1[5][5],d2[5][5],way[5][5][1000];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int check(int a)
{
	for(int i=1;i<=3;i++)
	for(int j=1;j<=3;j++)
	if(way[i][j][a]!=d2[i][j])
	return 0;
	
	return 1;
}
void copy(int a)
{
	for(int i=1;i<=3;i++)
	for(int j=1;j<=3;j++)
	way[i][j][a]=way[i][j][a-1];
}
void change (int a,int b,int c,int d,int e)
{
	int t=way[a][b][e];
	way[a][b][e]=way[c][d][e];
	way[c][d][e]=t;
}
void out(int a)
{
	printf("%d\n",a);
	for(int k=0;k<=a;k++)
	{
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=3;j++)
			printf("%d ",way[i][j][k]);
			printf("\n");
		}
		printf("\n");
	}
}
void search(int a,int b,int c,int d)
{
	for(int i=0;i<=3;i++)
	{
		int tx=a+dx[i],ty=b+dy[i];
		if(tx<=3&&tx>=1&&ty<=3&&ty>=1&&ins==0)
		{
			copy(c);
			change(a,b,a+dx[i],b+dy[i],c);
			if(check(c))
			{
				ins=1;
				poss=1;
			}
			else
			if(c<d) search(tx,ty,c+1,d);
		}
	}
}
int main()
{
	freopen("10460.in","r",stdin);
	freopen("10460.out","w",stdout);
	int pos=0;
	for(int i=1;i<=3;i++)
	for(int j=1;j<=3;j++)
	{
		scanf("%d",&d1[i][j]);
		way[i][j][0]=d1[i][j];
		if(d1[i][j]==0)
		{
			posx=i;
			posy=j;
		}
	}
	for(int i=1;i<=3;i++)
	for(int j=1;j<=3;j++)
	{
		scanf("%d",&d2[i][j]);
		if(d2[i][j]!=d1[i][j]) pos=1;
	}
	
	if(pos==0)
	{
		printf("0\n");
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=3;j++)
			printf("%d ",d1[i][j]);
			printf("\n");
		}
	}
	else
	{
		for(int i=1;;i++)
		{
			poss=0;
			search(posx,posy,1,i);
			if(poss)
			{
				out(i);
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
