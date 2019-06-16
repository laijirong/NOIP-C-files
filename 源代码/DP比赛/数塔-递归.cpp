//ÊıËş
#include <cstdio>
using namespace std;
int digital[320][320],m,rec[320][320],sel[320][320];	
int f(int a,int b)
{
	if (a==m)
		return digital[a][b];
	if (rec[a][b]>0) return rec[a][b];
	int t1=f(a+1,b),t2=f(a+1,b+1);
	if (t1<t2) {
		t1=t2;
		sel[a][b]=1;
	}
	rec[a][b]=digital[a][b]+t1;
	return rec[a][b];
}
void out(int a,int b)
{
	if (a==m) return ;
	printf("%d\n",sel[a][b]);
	out(a+1,b+sel[a][b]);
}
int main ()
{
	freopen ("in.in","r",stdin);
	int i,j;
	scanf("%d",&m);
	for (i=1;i<=m;i++)
		for (j=1;j<=i;j++)
			scanf("%d",&digital[i][j]);
	printf("%d\n",f(1,1));
	out(1,1);
	fclose(stdout);
	return 0;
} 
