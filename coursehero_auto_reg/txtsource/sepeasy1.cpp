#include<bits/stdc++.h>
using namespace std;

long long int arr[200010];
map<long long int,int> freq;
int counts[200010];
int main()
{
     int n;
     cin>>n;
     
     for(int i=0;i<n;i++)
     {
     	cin>>arr[i];
     	counts[i]=0;
     }
     if(n==1)
     {
     	cout<<0;
     	return 0;
     }

     counts[n-1]=1;
     freq[arr[n-1]]=1;
     for(int i=n-2;i>=0;i--)
     {
     	freq[arr[i]]++;
     	if(freq[arr[i]]>1)
     		counts[i]=counts[i+1];
     	else
     		counts[i]=counts[i+1]+1;
     }

     freq.clear();
     long long ans=0;
     for(int i=0;i<n-1;i++)
     {
     	freq[arr[i]]++;
     	if(freq[arr[i]]==1)
     	{
     		ans+=counts[i+1];
     	}
     }
     cout<<ans;
     return 0;

}