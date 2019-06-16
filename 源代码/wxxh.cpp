#include<string>
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("wxxh.n","r",stdin);
	freopen("บวบว.vbs","w",stdout);
	string s;
	int x=0;
	while(getline(cin,s)&&x<=99)
	{
		x++;
		cout<<s<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
