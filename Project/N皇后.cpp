#include <cstdio>
using namespace std;
int n,sum,de[10],rec[10][10];
void re(int a,int b)
{
	for (int i=1;i<=n;i++)
		{
			rec[a][i]--;
			rec[i][b]--;
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if ((a-i==j-b)||(i-a==j-b))
				rec[i][j]--;
}
void up(int a,int b)
{
	for (int i=1;i<=n;i++)
		{
			rec[a][i]++;
			rec[i][b]++;
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if ((a-i==j-b)||(i-a==j-b))
				rec[i][j]++;
}
void out(int a)
{
	for (int i=1;i<=a;i++)
		printf("%d",de[i]);
	printf("\n");
	sum++;
}
void ss(int a)
{
	for (int i=1;i<=n;i++)
		if (!rec[a][i])
		{
			de[a]=i;
			up(a,i);
			if (a==n)
				out(a);
			else
				ss(a+1);
			re(a,i);
		}
}
int main ()
{
	scanf("%d",&n);
	ss(1);
	printf("%d\n",sum);
	return 0;
}
