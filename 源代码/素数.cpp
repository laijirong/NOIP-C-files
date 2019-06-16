#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int a[10000020];
int main ()
{
	freopen("out.txt","w",stdout);
	int N=10000000;
	int n=int(sqrt(N));
	for (int i=3;i<=n;i+=2)   
		
		
			for (int j=i+i;j<=N;j+=i)
				a[j]++;
					
		
	printf("2 ");
	for (int i=3;i<=N;i+=2)
		if (a[i]==0) printf("%d ",i);
		fclose(stdin);
	return 0;
	
}


