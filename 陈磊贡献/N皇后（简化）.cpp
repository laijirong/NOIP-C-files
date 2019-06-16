#include<cstdio>
#include<cmath>
using namespace std;
int n,sum;
int used[20],seat[20],le[500],ri[100];
void out(int a)
{
	for(int i=1;i<=a;i++)
	printf("%d",seat[i]);
	printf("\n");
	sum++;
}
void search(int a)
{
	for(int i=1;i<=n;i++)
	{
		int t;
		if(i>=a) t=i-a;
		else	 t=a-i+100;
		if(used[i]==0&&le[t]==0&&ri[i+a]==0)
		{
			seat[a]=i;
			used[i]++;
			le[t]++;
			ri[i+a]++;
			
			if(a==n) out(a);
			else	 search(a+1);
			
			used[i]--;
			le[t]--;
			ri[i+a]--;
		}
	}
}
int main()
{
	scanf("%d",&n);
	search(1);
	printf("%d\n",sum);
	return 0;
}
