#include <cstdio>
using namespace std;
int n,m,cmd1,cmd2,pos;
struct ss{
	int sfs;
	char job[20];
}d[100200];
int main ()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d%s",&d[i].sfs,d[i].job);
	pos=1;
	for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&cmd1,&cmd2);
			if (cmd1==d[pos].sfs)
				pos-=cmd2;
			else
				pos+=cmd2;
			if (pos>n) pos-=n;
			if (pos<1) pos+=n;
		}
	printf("%s",d[pos].job);
	return 0;
}
