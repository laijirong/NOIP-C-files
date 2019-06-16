 #include<iostream>
 using namespace std;
 int main ()
 {
 	int m,n,d=0;m>=0;m<=n;n<=300;
 	scanf("%d%d",&m,&n);
	 for (int i=m;i<=n;i++)
 		{
 			if (i%2==1)
 				d=d+i;
 		}
 	printf("%d",d);
 	return 0;
 }
