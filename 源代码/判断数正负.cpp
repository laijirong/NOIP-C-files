#include  <cstdio>
#include<iostream>
using namespace std;
int main ()
{
	int N;
	scanf("%d",&N);
	if (N>=0)
		{if (N>0)
			printf("positive");
		else 
			printf("zero");
		}
	else 
	printf("negative");
	return 0;
}

