#include<bits/stdc++.h>
using namespace std;

void print(int start,int k)
{
	
	for(int i=start+1;i<start+k;i++)
	cout<<start<<" "<<i<<endl;
	
	for(int i=start+k;i<start+2*k-1;i++)
	{
	   for(int j=start+1;j<start+k;j++)
	   cout<<i<<" "<<j<<endl;
	}
	
	for(int i=start+k;i<start+2*k-1;i+=2)
	{
		cout<<i<<" "<<i+1<<endl;
	}
}

int main()
{
	int k;
	cin>>k;
	if(k%2==0)
	{
		cout<<"NO";
		return 0;
	}
	
	cout<<"YES"<<endl;
	cout<<4*k-2<<" "<<(2*k-1)*k<<endl;
	
	cout<<1<<" "<<2*k<<endl;
	
	print(1,k);
	print(2*k,k);
	return 0;
}
