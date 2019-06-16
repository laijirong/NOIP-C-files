#include <cstdio>
#include<cstring>
using namespace std;
char str[300],w[][7]={"puton","out","output","one","in","input"};
int rec[300],used[300],l[25],n,len;
int check (int a,int b)
{
	if (b<l[a]) return 0;
	for(int i=0;i<l[a];i++)
		if(str[b-i]!=w[a][l[a]-1-i]) return 0;
	return 1;
}
int judge(int a)
{
	if (a==0) return 1;
	if (used[a]) return rec[a];
	int t=0;
	for (int i=0;i<6;i++)
	 	if (check(i,a)&&judge(a-l[i])) {t=1;break;}
	used[a]=1;
	rec[a]=t;	
	return t;
		
}
void pre(int i)
{
	scanf("%s",&str[1]);
	len=strlen(&str[1]);
	for (int i=1;i<=len;i++)
		rec[i]=used[i]=0;
	if (judge(len))
		printf("YES\n");
	else printf("NO\n");
}
int main ()
{
	freopen("10050.in","r",stdin);
	for (int i=0;i<6;i++)
		l[i]=strlen(w[i]);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		pre(i);
		return 0;
}
