//计算表达式 
#include <cstdio>
#include<iostream>
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
	switch (a)
	{
		case '+'||'-'||'*'||'/' :return 1;break;
		return 0;
	}
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
	if (a==b) return ans(a,b);
	int f='!',pos;
	for (int i=b;i>=a;i--)
	if (judge(data[i])&&grade(data[i])<grade(f))
	{	pos=i;
		f=data[i];
	}
	if (f=='!')
		return cal(a,b);
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
