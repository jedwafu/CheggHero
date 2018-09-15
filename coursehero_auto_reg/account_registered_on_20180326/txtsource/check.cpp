#include<bits/stdc++.h>
using namespace std;

long long int arr[1000010];
long long int maxi[1000][1000];
map<int,int> freq;

int main()
{
	freq.clear();
	for(int i=0;i<1000;i++)
	for(int j=0;j<1000;j++)
	maxi[i][j]=0;
	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			for(int k=i;k<=j;k++)
			{
				maxi[i][j]=max(maxi[i][j],arr[k]);
			}
			freq[maxi[i][j]]++;
		}
	}
		
	for(int i=0;i<2000;i++)
	{
		if(freq[i])
		cout<<i<<" "<<freq[i]<<endl;
		}	
		
		
	/*for(int i=0;i<m;i++)
	{
		char c,x;
	    long long int k;
	    cin>>c;
	    cin>>k;
	    cin>>x;
	    long long total=0;
	    
		if(c=='<')
	    {
	       for(int i=0;i<k;i++)
	       {
	       	total+=freq[i];
		   }
		   cout<<total%2<<endl;
		}
		
		else if(c=='>')
		{
			for(int i=k+1;i<2000;i++)
			{
				total+=freq[i];
			}
			cout<<total%2<<endl;
		}
		
		else
		{
			cout<<freq[k]%2<<endl;
		}
		
	}
	*/
	return 0;
}
