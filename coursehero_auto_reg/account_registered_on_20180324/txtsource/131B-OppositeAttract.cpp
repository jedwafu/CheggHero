#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int main() {
	ll n;
	ll arr[22];
	memset(arr,0,sizeof(arr));
	ll countZero=0;
	ll ans=0;
	cin>>n;
	// this is my first idea but got the TLE
/*	for(int i=0;i<n;i++){
	    for(int j=i+1;j<n;j++){
	        if(arr[i]==(-arr[j])){
	            count++;
	        }
	    }
	}*/
	ll t;
    for(int i=0;i<n;i++){
      cin>>t;  
      if(t==0){
         countZero+=1;
      }
      // now the idea is to do this in llinear time
      else if(t>0){
          arr[t]++;
          // convert the value on the array of 1 to 20
      }
      else {
          arr[-t+10]++;
      }
    }
    for(int i=1;i<=10;i++){
        ans+=arr[i]*arr[10+i];
    }// for special condition we are taking here
    ans+=countZero*(countZero-1)/2;
    cout<<ans;
	return 0;
}