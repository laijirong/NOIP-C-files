 #include<iostream>
 using namespace std;
 int main ()
 {
	int k,a=1,b=1;1<=k&&k<46;
	cin>>k;
	for(int i=3;i<=k;i++)
		{
			if(a%2==0)
				a=a+b;
			if(b%2!=0)
				b=b+a;	
		}
	if (k%2!=0) cout<<b;
	if (k%2==0) cout<<a;
 	return 0;
 }
