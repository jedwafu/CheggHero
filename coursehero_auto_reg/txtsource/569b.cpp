#include<bits/stdc++.h>
using namespace std;

int arr[100010];
int freq[100010];
vector<int> absent;
vector<pair<int,int> > pres;

int main()
{
	
	int n;
	cin>>n;
	for(int i=0;i<=n;i++)
	freq[i]=0;
	
	for(int i=0;i<n;i++)
	{
	  cin>>arr[i];
	  freq[arr[i]]++;
    }
	
	for(int i=1;i<=n;i++)
	{
		if(freq[i]==0)
		absent.push_back(i);
	}
	
	int k=0;
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]<=n and freq[arr[i]]==1)
		continue;
		else
		{
			freq[arr[i]]--;
			arr[i]=absent[k];
			k++;
		}
		
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
