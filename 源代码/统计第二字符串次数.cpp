//���������ַ�����ͳ�Ƶڶ������ڵ�һ�����г����Ĵ�����
#include <iostream>
#include <cstdio>
using namespace std;
int a[1000],flag=0,ans;
char s1[1000],s2[1000];

int main ()
{
	scanf("%s%s",&s1[1],&s2[1]);
	int l1=strlen(&s1[1]),l2=strlen(&s2[1]);
	for (int i=1;i<=l1-l2+1;i++)
		{
			flag=1;
			for (int j=1;j<=l2;j++)
				if (s1[i+j-1]!=s2[j])
					{
						flag=0;
						break;
					}
				ans+=flag;
		}
		
	cout<<ans;
	
	return 0;
}
