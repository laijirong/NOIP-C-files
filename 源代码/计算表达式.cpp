#include <cstdio>
#include<iostream>
#include<string.h>
using namespace std;
char data[200020];
int ans(int a,int b)
{
	int t=0;
	for (int i=a;i<=b;i++)
		t=t*10+data[i]-'0';
	return t;
}
int judge(char a)
{
	if(a=='+'||a=='-'||a=='*'||a=='/')  return 1;
	return 0;
}
int grade(char a)
{
	switch (a)
	{
		case '!' : return 3;
		case '*':case '/' : return 2;
		case '+':case '-' : return 1;
	}
}
int cal (int a,int b)
{
	char f='!';
	int pos,sum=0;
	for (int i=b;i>=a;i--)
	{
		if (data[i]==')') sum++;
		if (data[i]=='(') sum--;
		if (judge(data[i])&&grade(data[i])<grade(f)&&sum==0)
		{	pos=i;
			f=data[i];
		}
	}	
	if (f=='!')
	{
		if (data[a]=='(')  return cal(a+1,b-1);
		return ans(a,b);
	}
	switch (f)
	{
		case '+' :return cal(a,pos-1)+cal(pos+1,b);
		case '-' :return cal(a,pos-1)-cal(pos+1,b);
		case '*' :return cal(a,pos-1)*cal(pos+1,b);
		case '/' :return cal(a,pos-1)/cal(pos+1,b);
	}
}
int main()
{
	scanf("%s",&data[1]);
	int len=strlen(&data[1]);
	printf("%d",cal(1,len));
	return 0;
}
