#include <cstdio>
#include <cstdlib>
#define maxn 350//即int maxn=350;
using namespace std;
int sumr[maxn],maxm[maxn],summ,used[maxn],tmax=0;
struct ss
{
  int m,v;
  ss (){ };//为保证 ss da[maxn][maxn]不报错 ;
  ss(int a,int b){m=a;v=b;}//强制转换-->50行 ； 
  
  bool operator <(ss b)const{return v<b.v;}//const即限定符,它把一个变量转换成一个常量； 
};//bool类函数取值false和true，0为false，非0为true； 
int n;
ss da[maxn][maxn];//da[num_man][num_robot]； 
void change(ss &a,ss &b){ss t=a;a=b;b=t;}//传入变量地址； 
void sort(ss a[])
{
  for(int i=1;i<a[0].m;i++)
   for(int j=i+1;j<=a[0].m;j++)
    if(a[i]<a[j]) change(a[i],a[j])	;
}
void search(int a,int score,int summ)
{
   int tscore,tsumm;
   for(int i=1;i<=da[a][0].m;i++)
     if(used[da[a][i].m]==0){
        tscore=score+da[a][i].v;
        tsumm=summ-maxm[da[a][i].m];
        used[da[a][i].m]=1;
        if(a==n){
          	if(tscore>tmax) tmax=tscore;
          }
       else
	   if(tscore+sumr[a+1]>tmax&&tsumm+tscore>tmax) search(a+1,tscore,tsumm);
	   used[da[a][i].m]=0; 
	   }
 }
void changeline(int a,int b)
{
  for(int i=0;i<=n;i++)	
   change(da[a][i],da[b][i]);
}
int main()
{
	//freopen("yes.in","r",stdin);
	//freopen("yes.out","w",stdout);
	int a,b,c;
	scanf("%d%d",&n,&n);
	while(scanf("%d%d%d",&a,&b,&c)==3)//如果成功输入返回3，循环进行；反之返回0，退出循环； 
	{
	 da[a][++da[a][0].m]=ss(b,c);	
	 if(maxm[b]<c) maxm[b]=c;
    }

   for(int i=1;i<n;i++)	
     for(int j=i+1;j<=n;j++)
       if(da[i][0].m>da[j][0].m)
         changeline(i,j);
	
	for(int i=1;i<=n;i++)
	  sort(da[i]);
	
	for(int i=n;i>=1;i--)	
	  sumr[i]=sumr[i+1]+da[i][1].v;
	for(int i=1;i<=n;i++)  
	  summ+=maxm[i];
	
	search(1,0,summ); 

  printf("%d %d\n",n,tmax);	
// fclose(stdout);
	return 0;
}
