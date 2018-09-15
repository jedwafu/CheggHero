#include<bits/stdc++.h>
using namespace std;

bool pangram(bool freq[])
{
	for(int i=0;i<26;i++)
	if(freq[i]==false)
	return false;
	
	return true;
}

bool palindrome(string s,int a,int b)
{
	if(a==b or a>b)
	return true;
	
	if(s[a]==s[b])
	return palindrome(s,a+1,b-1);
	else
	return false;
}

int main()
{
	int t;
	bool freq[30];
	string s;
	
	cin>>t;
	
	while(t--)
	{
		for(int i=0;i<26;i++)
		freq[i]=false;
		
		cin>>s;
		
		for(int i=0;i<s.length();i++)
		{
			freq[s[i]-'a']=true;
		}
		
		bool val1=palindrome(s,0,s.length()-1);
		bool val2=false;
		if(s.length()>25)
		val2=pangram(freq);
		
		if(val1 and val2)
		cout<<"palingram"<<endl;
		else if(val1)
		cout<<"palindrome"<<endl;
		else if(val2)
		cout<<"pangram"<<endl;
		else
		cout<<"none"<<endl;
	}
	return 0;
}
