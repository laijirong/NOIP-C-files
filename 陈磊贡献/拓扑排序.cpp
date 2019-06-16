#include<cstdio>
using namespace std;
int n,map[2010][2010],head,last,d[2010],in[2010],out[2010];
int main()
{
	freopen("10310.in","r",stdin);
	freopen("10310.out","w",stdout);
	int x,y;
	scanf("%d",&n);
	while(scanf("%d%d",&x,&y)==2)
	{
		out[x]++;
		in[y]++;
		map[x][out[x]]=y;
	}
	for(int i=1;i<=n;i++)
	if(in[i]==0) d[++head]=i;
	last=head;
	for(int i=1;i<=last;i++)
	{
		for(int j=1;j<=out[d[i]];j++)
		{
			in[map[d[i]][j]]--;
			if(in[map[d[i]][j]]==0)
			d[++last]=map[d[i]][j];
		}
	}
	if(last==n)
	{
		for(int i=1;i<=n;i++)
		printf("%d ",d[i]);
		printf("\n");
	}
	else printf("NO\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
