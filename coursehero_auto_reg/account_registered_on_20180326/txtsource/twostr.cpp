#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s1,s2;
		cin>>s1;
		cin>>s2;
		int flag=1;
		for(int i=0;i<s1.length();i++)
		{
			if(s1[i]>='a' and s1[i]<='z' and s2[i]>='a' and s2[i]<='z')
			{
				if(s1[i]!=s2[i])
				{
					flag=0;
					break;
				}
			}
		}
		
		if(flag)
		{
			cout<<"Yes"<<endl;
		}
		else
		cout<<"No"<<endl;
	}
	return 0;
}
