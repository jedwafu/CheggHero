#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int arr[20];
int minarr[20];
int minindex[20];
int main()
{
	int m;
	cin>>m;
    
    for(int i=1;i<=12;i++)
    	cin>>arr[i];
    		
    	
    
    minarr[1]=arr[1];
    minindex[1]=1;
    for(int i=2;i<=12;i++)
    {
    	if(arr[i]<minarr[i-1])
    	{
    		minarr[i]=arr[i];
    		minindex[i]=i;
    	}
    	else
    	{
    		minarr[i]=minarr[i-1];
    		minindex[i]=minindex[i-1];
    	}
    }

    int ans=0,start=0,end=0;

    for(int i=12;i>1;i--)
    {
        int units = m/minarr[i-1];
        if(units==0)
        	continue;

    	else if(units*(arr[i]- minarr[i]) > ans or (units*(arr[i]-minarr[i])==ans and minarr[i]< arr[start]))
    	{
    		ans=units*(arr[i]-minarr[i]);
    		start=minindex[i-1];
    		end=i;
    	}
    }

    if(ans==0)
    	cout<<"IMPOSSIBLE"<<endl;
    else
    	cout<<start<<" "<<end<<" "<<ans;

    return 0;
}