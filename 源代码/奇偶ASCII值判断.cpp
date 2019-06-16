#include  <cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
int main ()
{
	int a,b;
	char c;
	cin>>a>>b>>c;
	if ((c='+') || (c='-') || (c='*') || (c='/'))
		if (c=a+b)
			cout<<(int)c;
		else 
			if (c=a-b)
				cout<<(int)c;
			else
					if (c=a*b)
						cout<<(int)c;
					else
							if (b==0)
								cout<<"Divided by zero";
							else 
									cout<<(int)c;
	else cout<<"Invalid operator!";
	system("pause");
	return 0;
}

