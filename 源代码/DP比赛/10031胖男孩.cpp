//10031. ÅÖÄÐº¢
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s1[128],s2[128],s3[128];
int f[128][128][128],fr[][4]={{1,1,0,0},{1,0,1,0},{1,0,0,1}};
int l1,l2,l3,ll,sel[128][128][128];
void out (int a,int b,int c)
{
	if (a==0||b==0||c==0) return ;
	int t=sel[a][b][c];
	out(a-fr[0][t],b-fr[1][t],c-fr[2][t]);
	if (t==0) printf("%c",s1[a]);
}
int main ()
{
	freopen ("10031.in","r",stdin);
	scanf("%s%s%s",&s1[1],&s2[1],&s3[1]);
	l1=strlen(&s1[1]);l2=strlen(&s2[1]);l3=strlen(&s3[1]);
	for (int i=1;i<=l1;i++)
		for (int j=1;j<=l2;j++)
			for (int k=1;k<=l3;k++)
				{
					if (s1[i]==s2[j]&&s1[i]==s3[k])
						{
							f[i][j][k]=f[i-1][j-1][k-1]+1;
							continue;
						}
					int t=-1,ss;
					for (int l=1;l<=3;l++)
						if (t<f[i-fr[0][l]][j-fr[1][l]][k-fr[2][l]])
							{
								t=f[i-fr[0][l]][j-fr[1][l]][k-fr[2][l]];
								ss=l;
							}
					f[i][j][k]=t;	sel[i][j][k]=ss;
				}
	out(l1,l2,l3);
	fclose(stdin);
	return 0;
}
