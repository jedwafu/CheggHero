#include <bits/stdc++.h>
using namespace std;

#define ll long long int
map<string,int> freq;
int main()
{
	int t;
	string s;
	cin>>t;
	char c;
	while(t--)
	{
		cin>>c;
		if(c=='+' or c=='-')
		{
			cin>>s;
			int len=s.length();
			for(int i=0;i<len;i++)
				if((s[i]-'0')%2)
					s[i]='1';
				else
					s[i]='0';

            while(s.length()<20)
            	s.insert(s.begin(),'0');
			//bitset<64> x = num;
			//string s= x.to_string();
			if(c=='+')
			freq[s]++;
		    else
		    freq[s]--;
			//cout<<s<<endl;
		}
		if(c=='?')
		{
		    string s;
		    cin>>s;
		    
		    while(s.length()<20)
		    	s.insert(s.begin(),'0');
			cout<<freq[s]<<endl;
		}
	}
	return 0;
}