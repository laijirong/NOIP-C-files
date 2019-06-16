//10031 - ÅÖÄĞº¢
#include<stdio.h>
#include<string.h>
using namespace std;
int dx[]={-1,-1,0,0},dy[]={-1,0,-1,0},dz[]={-1,0,0,-1};
int used[110][110][110],sept[110][110][110],f[110][110][110];
char str[5][110];
int l[4];
int search(int a,int b,int c)
{
	if(used[a][b][c]!=0)  return f[a][b][c];
	if(a==0||b==0||c==0) return 0;
	if(str[1][a]==str[2][b]&&str[2][b]==str[3][c])
	  {
	  	used[a][b][c]=1;
	  	sept[a][b][c]=0;
	  	return f[a][b][c]=search(a-1,b-1,c-1)+1;
	  }
	  int max=-1,t,sel;
	for(int i=1;i<=3;i++)
	{
	  t=search(a+dx[i],b+dy[i],c+dz[i]);
	  if(t>max)
	  {
	    max=t;
	    sel=i;
	  }
	}
	sept[a][b][c]=sel;
	f[a][b][c]=max;
	used[a][b][c]=1;
	return max;
}
void out(int a,int b,int c)
{
    if(a==0||b==0||c==0) return;
    int t=sept[a][b][c];
    out(a+dx[t],b+dy[t],c+dz[t]);
    if(t==0)
      printf("%c",str[1][a]);
}
int main()
{
	
	for(int i=1;i<=3;i++)
	{
	  scanf("%s",&str[i][1]); 
	  l[i]=strlen(&str[i][1]);
	}
	search(l[1],l[2],l[3]);
	out(l[1],l[2],l[3]);
	return 0;
}
