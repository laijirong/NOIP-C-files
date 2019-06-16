//sum 0: (n<=10^9)
//#include  <iostream>
//using namespace std;
//int main ()
//{
//	int n,s=0;
//	cin>>n;
//	for (int i=1;i<=n;i++)
//		s=s+i/5+i/25+i/125+i/(125*5)+i/(125*25)+i/(125*125)+i/(125*125*5)+i/(125*125*25)+i/(125*125*125)+i/(125*125*125*5)
//		+i/(125*125*125*25)+i/(125*125*125*125)+i/(125*125*125*125*5);
//		cout<<s<<endl;
//	return 0;
//}

//ÈÝ³âÔ­Àí
#include  <iostream>
using namespace std;
int main ()
{
	int n,s=0;
	cin>>n;
	for (int i=1;i<=n;i++)
		s=s+i/2+i/3+i/5-i/6-i/10-i/15+i/30;
	cout<<s;
	return 0;
}
