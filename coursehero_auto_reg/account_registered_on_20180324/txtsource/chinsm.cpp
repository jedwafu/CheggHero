#include <bits/stdc++.h>
using namespace std;

int arr[100010];
int main() 
{
    int n,k;
    cin>>n>>k;
    long long ans=0;
    
	for(int i=1;i<=n;i++)
    cin>>arr[i];
    
    for(int i=1;i<=n;i++){	
    for(int j=i+1;j<=n;j++){
        
		if(arr[i]%arr[j]==k){
            ans=ans+(j-i);
            break;
        }
        
        else if(j==n)
        ans+=j-i+1;
    }
    }
    
   cout<<ans+1;
   return 0;
}  
