#include<bits/stdc++.h>
using namespace std;

int xval[101];
int yval[101];
int main()
{
	string s;
	cin>>s;
	xval[0]=0;
	yval[0]=0;
	for(int i=0;i<s.length();i++)
	{
		xval[i+1]=xval[i];
		yval[i+1]=yval[i];
		
		if(s[i]=='L')
		xval[i+1]--;
		else if(s[i]=='R')
		xval[i+1]++;
		else if(s[i]=='U')
		yval[i+1]++;
		else
		yval[i+1]--;	
	}
	
	for(int i=1;i<s.length()+1;i++)
	{
		for(int j=0;j<i-1;j++)
		{
			if(abs(xval[j]-xval[i])==1 and yval[j]==yval[i])
			{
				cout<<"BUG";
				return 0;
			}
			if(abs(yval[j]-yval[i])==1 and xval[i]==xval[j])
			{
				cout<<"BUG";
				return 0;
			}
		}
	}
	
	cout<<"OK";
	return 0;
	
}
