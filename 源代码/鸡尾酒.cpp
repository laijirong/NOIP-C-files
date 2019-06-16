#include<iostream>
 using namespace std;
 int main ()
 {
	double n,n1,t,x,y;
	cin>>n1>>n>>t;
	x=t/n;
	//system("echo -----------");
	for(int i=2;i<=n1;i++)
		{
			cin>>n>>t;
			y=t/n;
			if (y-x>0.05)
				cout<<y-x<<"better";
			else
				if (x-y>0.05)
					cout<<x-y<<"worse";
				else
					cout<<"same"; 
			//if((t1/n1)-(t/n)>0.05) 
			//	cout<<"better\n";
			//else
			//	if((t/n)-(t1/n1)>0.05) 
			//		cout<<"worse\n";
			//	else  cout<<"same\n";
		} 
 	return 0;
 }
