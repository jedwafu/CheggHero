#include<iostream>
using namespace std;

#define loop(i,a,b) for(i=a;i<b;i++)
int main()
{
	long long int a;
	int i,n,k;
	
	cin>>a>>n>>k;
	n++;
	
	loop(i,0,k)
	{
		cout<<a%n<<" ";
		a=a/n;
	}
	
	cout<<endl;
	return 0;
}

