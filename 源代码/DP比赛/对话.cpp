#include<cstdio>
#include <cstring>
using namespace std;
char str[300];
int n,len;
int l[10];
int rec[300],used[300];
char W[][7]={"input","output","in","out","one","puton"};
int check(int a,int b)
{
  if(b<l[a])	return 0;
   for(int i=0;i<l[a];i++)
    if(str[b-i]!=W[a][l[a]-1-i]) return 0;
  return 1;		
}
int dp(int a)
{
  if(a==0) return 1;
  if(used[a]) return rec[a];
 
  int t=0;
  for(int i=0;i<6;i++)
   if(check(i,a)&&dp(a-l[i])) {t=1;break;} 
 
  used[a]=1;
  rec[a]=t;
  return t; 
 }
void doit()
{
 scanf("%s",&str[1]);
 len=strlen(&str[1]);
 for(int i=1;i<=len;i++)	
  rec[i]=used[i]=0;
 
 if(dp(len))
   puts("YES");
 else
   printf("%s\n","NO");  
	
}
int main()
{
	freopen("10050.in","r",stdin);
	freopen("10050.out","w",stdout);
	for(int i=0;i<6;i++)
	 l[i]=strlen(W[i]);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
      doit();

}
