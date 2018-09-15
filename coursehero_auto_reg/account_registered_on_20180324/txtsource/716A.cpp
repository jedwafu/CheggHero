#include<bits/stdc++.h>
using namespace std;

#define ll long long int

string s;
bool seen[27];
char arr[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int main()
{
	cin>>s;
	int len=s.length();
	
	if(len<26)
	{
		cout<<-1<<endl;
		return 0;
	}

	for(int i=0;i<len;i++)
	{
		 if(i+25>=len)
		 	break;

         for(int j=0;j<27;j++)
         	seen[j]=false;

         int count=0;
         int count2=0;
		 for(int j=i;j<i+26;j++)
		 {
            if(s[j]=='?')
            	count++;
            else
            	seen[s[j]-'A']=true;
		 }
		 for(int j=0;j<26;j++)
		 	if(seen[j]==false)
		 		count2++;

		 	if(count2==count)
		 	{
		 		int iter1=i;
		 		int iter2=0;
		 		while(iter1<i+26)
		 		{
		 			if(s[iter1]=='?')
		 			{
		 				while(seen[iter2] and iter2<26)
		 					iter2++;
		 				s[iter1]=arr[iter2];
		 				iter2++;
		 			}
		 			else
		 				iter1++;
		 		}

		 		for(int j=i+26;j<len;j++)
		 			if(s[j]=='?')
		 				s[j]='A';

		 		cout<<s<<endl;
		 		return 0;	
		 	}
		 	else if(s[i]=='?') 
		 		s[i]='A';
	}

	cout<<-1<<endl;
	return 0;

}