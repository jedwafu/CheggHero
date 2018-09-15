#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int m,n;
	cin>>n>>m;
	if(n==1)
	cout<<1;
	
	else if(m==n)
	cout<<n-1;
	else if(m==1)
	cout<<2;
	
	else if(2*m>n+1 and m!=1)
    cout<<m-1;
    else
    cout<<m+1;
	
	return 0;
}
