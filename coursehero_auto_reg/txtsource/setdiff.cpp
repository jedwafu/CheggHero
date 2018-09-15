#include<iostream>
#include<cstdlib>

using namespace std;

int compare (const void *elem1, const void *elem2){
    return *(int*)elem1 - *(int*)elem2;
}

long long int arr[100002];
long long int pow[100002];
#define mod 1000000007
int main()
{
	int t,n,i;
	long long int sum,term1,term2;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		sum=0;
		for(i=0;i<n;i++)
		cin>>arr[i];
	
	    qsort(arr, n, sizeof(long long int), compare);
	    
		
	    for(i=0;i<n;i++)
	    {
	    	arr[n-i]=arr[n-1-i];
		}
    
		    
    pow[0]=1;
    for(i=1;i<=n-1;i++)
    {
    	pow[i]=(2*(pow[i-1]%mod))%mod;
    	if(pow[i]<0)
    	pow[i]=pow[i]+mod;
	}
	
	
    for(i=1;i<=n/2;i++)
    {
    	term1= ((arr[n-i+1]-arr[i])%mod);
    	if(term1<0)
    	term1=term1+mod;
    	
    	
    	term2=((pow[i-1]%mod)*((pow[n-(2*i-1)]%mod-1)%mod))%mod;
		if(term2<0)
    	term2=term2+mod;
    	
    	sum= (sum%mod +(term1*term2)%mod)%mod;
    	if(sum<0)
    	sum=sum+mod;
	}

    cout<<sum<<endl; 
	
    }
    return 0;
}
