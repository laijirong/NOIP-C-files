//读入一个由字母（大小写字母）构成的字符串，统计各个字母出现的次数（注意：大小写统计在一起）
#include <iostream>
#include <cstdio>
using namespace std;
int a[8020];
char str[1000];
int main ()
{
	int n;
	scanf("%s",&str[1]);
	n=strlen(&str[1]);
	char m;
	for (int i=1;i<=n;i++)
		{
			m=*&str[i];
			//if (m>='a') m=m-32;
			for (int j='A';j<='z';j++)
				{
					if (m%j==0) a[j]++;
				}
		}
	for (int i='A';i<='Z';i++)
		cout<<char (i)<<" "<<a[i]+a[i+32]<<endl;
	return 0;	
}
