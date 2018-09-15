#include<bits/stdc++.h>
using namespace std;

long long int arr[200010];
map<long long int ,int>freq;
int counts[200010];
int starts[200010];

int main()
{
	int n;
	cin>>n;
    freq.clear();

	for(int i=1;i<=n;i++)
		cin>>arr[i];
    
    counts[1]=1;
    freq[arr[1]]++;
    int flag=1;

    if(n==1)
    {
    	cout<<1;
    	return 0;
    }

    for(int i=2;i<=n;i++)
    {
         freq[arr[i]]++;
         if(freq[arr[i]]==1)
         {
         	counts[i]=counts[i-1]+1;
         	flag=i;
         }

         else
         	counts[i]=counts[i-1];
    }

    freq.clear();
    
    for(int i=1;i<=flag;i++)
    	freq[arr[i]]++;

    
    for(int i=1;i<=flag;i++)
    {
       if(freq[arr[i]]>1)
       {
       	freq[arr[i]]--;
       }

       else
       {
          starts[flag]=i;
          break;  
       }    
    }
    
    int j=starts[flag];

    for(int i=flag+1;i<=n;i++)
    {
    	freq[arr[i]]++;
        while(freq[arr[j]]>1)
        {
        	freq[arr[j]]--;
        	j++;
        }
        starts[i]=j;
    }
    long long ans=0;
    for(int i=flag;i<=n;i++)
    {
    	ans+=starts[i];
    }
    cout<<ans<<endl;

return 0;
}
