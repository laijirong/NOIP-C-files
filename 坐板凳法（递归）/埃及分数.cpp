#include<cstdio>
#include<cmath>
using namespace std;
int ok;
long long abs(long long a)
{
 	if(a>0) return a;
 	return -a;
}
struct s_fs
{
 	long long fz,fm;
 	s_fs(){ }
 	
 	s_fs(long long a,long long b)
 	{
 		fz=a;fm=b;
 	}
	 long long gcd(long long a,long long b)
 	{
  	if(b==0) return a;
  	return gcd(b,a%b);	
 	}
 	s_fs operator -(s_fs b)	
  	{
  		s_fs t;
  		long long g=gcd(fm,b.fm);
  		t.fm=fm/g*b.fm;
  		t.fz=fz*(b.fm/g)-b.fz*(fm/g);
  	  
		g=gcd(t.fm,abs(t.fz));
  	 	t.fm/=g;
  		t.fz/=g;
 	 	return t;
 	 }
};
s_fs A,B,seat[100],best[100];
void copy(int a)
{
  	for(int i=1;i<=a;i++)
  	 best[i]=seat[i];	
}
void out(int a,s_fs b[])
{
 // printf("%lld/%lld=",A.fz,A.fm);
 	 for(int i=1;i<a;i++)	
 	  printf("%lld/%lld+",b[i].fz,b[i].fm);
 	  printf("%lld/%lld\n",b[a].fz,b[a].fm);
}
int isok(s_fs a[],s_fs b[],int c)
{
   for(int i=c;i>=1;i--)	
    {
    	 if(a[i].fm<b[i].fm) return 1;
    	 if(a[i].fm>b[i].fm) return 0;
    }
   return 0; 
}
 void search(int a,s_fs b,int def)//defÎªÉî¶È£» 
{
  s_fs tt;
  for(int i=int(def*b.fm/b.fz);i>=seat[a-1].fm+1;i--)
    {
      seat[a]=s_fs(1,i);
      tt=b-seat[a];
	  if(tt.fz<0) break;
	  if(tt.fz==0)
	   {
	    ok=1;
	  //out(a,seat);
	    if(isok(seat,best,a))
	      copy(a);
	    }
	  else
	   if(def>0) search(a+1,tt,def-1); 
    }	
}
int main()
{
	//freopen("fs.in","r",stdin);
	//freopen("fs.out","w",stdout);
	scanf("%lld%lld",&A.fz,&A.fm);
	seat[0].fm=1;
	for(int i=1;i<100;i++)
	 best[i].fm=0x7fffffff;

	for(int i=1;i<=100;i++)
	 {
	    search(1,A,i);
	   	 if(ok) {out(i,best);break;}
      }
	return 0;
}

