#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	char ch;
	cin>>n>>m;
	bool flag=true;
	for(int i=0;i<n;i++)
	{
		for(int i=0;i<m;i++)
		{
            cin>>ch;
            if(ch=='C' or ch=='M' or ch=='Y')
            	flag=false;
		}
	}
	if(flag)
		cout<<"#Black&White"<<endl;
	else
		cout<<"#Color"<<endl;

	return 0;
}