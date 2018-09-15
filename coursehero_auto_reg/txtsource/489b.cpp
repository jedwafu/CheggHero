#include<bits/stdc++.h>
using namespace std;
int boys[100];
int girls[100];
int main()
{
	int n,m,pairs=0,flag=1;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>boys[i];
	
	cin>>m;
	for(int i=0;i<m;i++)
	cin>>girls[i];
	
	sort(boys,boys+n);
	sort(girls,girls+m);
	
	int k=0;
	for(int i=0;i<n;i++)
	{
		while(boys[i]-girls[k]>1 && flag==1)
		{
			k++;
			if(k==m)
			flag=0;
		}
		
		if(flag==0)
		break;
		
		if(boys[i]-girls[k]>=-1)
		{
			pairs++;
			k++;
			if(k==m)
			break;
		}
	}
	cout<<pairs;
	return 0;
}
