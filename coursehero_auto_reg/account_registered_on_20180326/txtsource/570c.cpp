#include<bits/stdc++.h>
using namespace std;
string s;

int main()
{
	int n,m;
	cin>>n>>m;
	cin>>s;
	int val=0;
	
	for(int i=0;i<s.length();i++)
	{
		int count=0,j=0;
		if(s[i]=='.')
		{
			j=i;
			while(s[j]=='.' and j<s.length())
			{
				count++;
				j++;
			}
		
		 val+=count-1;
		 i=j-1;
		if(j==s.length())
		break;
	    }
	}
	
	int a;
	char c;
	for(int i=0;i<m;i++)
	{
		cin>>a>>c;
		if(c=='.')
		{
			if(s[a-1]!='.')
			{
				if(a==1)
				{
					if(s[1]=='.')
					val++;
					
				}
				else if(a==s.length())
				{
					if(s[s.length()-2]=='.')
					val++;
				}
				
				else if(s[a-2]=='.' and s[a]=='.')
				{
					val+=2;
				}
				else if(s[a-2]=='.' or s[a]=='.')
				val++;
				
				s[a-1]=c;
			}
		}
		else
		{
			if(s[a-1]=='.')
			{
				if(a==1)
				{
					if(s[1]=='.')
					val--;
				}
				else if(a==s.length())
				{
					if(s[s.length()-2]=='.')
					val--;
				}
				else if(s[a-2]=='.' and s[a]=='.')
				val-=2;
				else if(s[a-2]=='.' or s[a]=='.')
				val--;
				
				s[a-1]=c;
			}
		}
		cout<<val<<endl;
	}
	return 0;
}
