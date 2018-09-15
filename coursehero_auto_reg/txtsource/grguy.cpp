#include<bits/stdc++.h>
using namespace std;

int counts=0,len;
string s1,s2;
bool arr1(int i);
bool arr2(int i);

bool arr1(int i)
{
	if(i==len-1)
	return true;
	
	if(s1[i+1]=='.')
	return arr1(i+1);
	
	else if(s2[i+1]=='.')
	{
	counts++;	
	return arr2(i+1);
    }
    else return false;
}

bool arr2(int i)
{
	if(i==len-1)
	return true;
	
	if(s2[i+1]=='.')
	return arr2(i+1);
	
	else if(s1[i+1]=='.')
	{
	counts++;
	return arr1(i+1);
    }
    else return false;
}

int main()
{
	int t;
	
	
	cin>>t;
	while(t--)
	{
		int maxcount=0;
		int flag=1;
		cin>>s1;
		cin>>s2;
		len=s1.length();
		
		for(int i=0;i<len;i++)
		{
			if(s1[i]=='#' and s2[i]=='#')
			{
			  cout<<"No"<<endl;
			  flag=0;
			  break;
			}
		}
		
		if(flag==1)
		{
			cout<<"Yes"<<endl;
			bool val1=arr1(-1);
			
			if(val1==true)
			maxcount=counts;
			
			counts=0;
			
			if(arr2(-1))
			maxcount=min(maxcount,counts);
			
			counts=0;
			cout<<maxcount<<endl;
		}
	}
	return 0;
}
