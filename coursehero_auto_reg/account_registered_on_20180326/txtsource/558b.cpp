#include<bits/stdc++.h>
using namespace std;

int beg[1000010],end[1000010],counts[1000010],span[1000010];
int n,inp,maxi=0,ans=1;
int main()
{
	for(int i=0;i<1000010;i++)
	{
		end[i]=counts[i]=0;
		span[i]=beg[i]=100000;
	}
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>inp;
		
		if(beg[inp]>i)
		beg[inp]=i;
		
		end[inp]=i;
		
		span[inp]=max(0,end[inp]-beg[inp]);
		counts[inp]++;
		
		if(counts[inp]>maxi)
		{
			ans=inp;
			maxi=counts[inp];
		}
		
		else if(counts[inp]==maxi)
		{
			if(span[inp]<span[ans])
			ans=inp;
		}
		
	}
	
	cout<<beg[ans]<<" "<<end[ans];
	
	
}
