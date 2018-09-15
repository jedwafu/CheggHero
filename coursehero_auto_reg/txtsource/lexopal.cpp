#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	string s;
	cin>>t;
	while(t--)
	{
        cin>>s;
        int n=s.length();
        bool flag=true;
        if(n%2)
        {
        	if(s[n/2]=='.')
        		s[n/2]='a';
        }   
        
        	for(int i=0;i<n/2;i++)
             {
             	if(s[i]=='.' and s[n-1-i]=='.')
             		s[i]=s[n-1-i]='a';
             	else if(s[i]=='.')
             		s[i]=s[n-1-i];
             	else if(s[n-1-i]=='.')
             		s[n-1-i]=s[i];
             	else if(s[i]!=s[n-1-i])
             	{
             		flag=false;
             		break;
             	}
             }

        if(flag)
        	cout<<s<<endl;
        else
        	cout<<-1<<endl;

	}
	return 0;
}