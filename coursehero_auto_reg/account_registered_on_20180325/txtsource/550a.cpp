#include<bits/stdc++.h>
using namespace std;

string s;

int main()
{
	cin>>s;
    int l=-1;
    int r=-1;
	int len=s.length();

	for(int i=0;i<len-1;i++)
	if(s[i]=='B' and s[i+1]=='A')
		{
			l=i+1;
			break; 
		}
	
    for(int i=len-1;i>0;i--)
    if(s[i-1]=='B' and s[i]=='A')
       {
           r=i-1;
           break;
       }
    
    if(l==-1 or r ==-1)
    {
    	cout<<"NO"<<endl;
    	return 0;
    } 
    for(int i=0;i<len-1;i++)
    {
    	if(s[i]=='A' and s[i+1]=='B')
    	{
    		if((i-1>=0 and l<=i-1) or ( i+2<=len and r>=i+2))
    		{
    			cout<<"YES"<<endl;
    			return 0;
    		}
    	}
    }
    cout<<"NO"<<endl;
    return 0;
}