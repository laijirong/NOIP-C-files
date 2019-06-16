#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int len,ans;
char s[100010];
int main()
{
	freopen("10466.in","r",stdin);
	freopen("10466.out","w",stdout);
	scanf("%s",&s[1]);
	len=strlen(&s[1]);
	for(int i=1;i<=len;i++)
	{
		int l=i,r=i;
		while(s[i]==s[r+1])
		r++;
		i=r;
		while(s[l-1]==s[r+1])
		{
			l--;
			r++;
		}
		ans=max(ans,r-l+1);
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
