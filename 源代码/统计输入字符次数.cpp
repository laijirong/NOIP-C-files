//����һ������ĸ����Сд��ĸ�����ɵ��ַ�����ͳ�Ƹ�����ĸ���ֵĴ�����ע�⣺��Сдͳ����һ��
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
