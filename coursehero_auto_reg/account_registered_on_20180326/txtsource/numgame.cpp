#include<iostream>

using namespace std;

int main()
{
	int t;
	long long int n;
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n%2)
		cout<<"BOB"<<endl;
		
		else
		cout<<"ALICE"<<endl;
		
	}
	
	return 0;
}
