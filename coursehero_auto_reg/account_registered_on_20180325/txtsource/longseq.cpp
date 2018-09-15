#include<bits/stdc++.h>
using namespace std;

string s;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
      cin>>s;
      int count1=0,count2=0;
      int n=s.length();
      for(int i=0;i<n;i++)
      {
           if(s[i]=='0')
           	count1++;
           else
           	count2++;
      }
      if(n==1)
      cout<<"Yes"<<endl;
      else
      	{
      		if(count1==1 or count2==1)
      			cout<<"Yes"<<endl;
      		else
      			cout<<"No"<<endl;
      	}

	}
	return 0;
}