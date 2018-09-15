/* Using code from euclid.cc from the Stanford ICPC Notebook.*/



#include <bits/stdc++.h>
using namespace std;


#define ll long long int
ll m =1000000007;

ll arr[1000010];
ll dp1[1000010];
ll dp2[1000010];
ll dp3[1000010];
ll pow2[1000010];

ll mod(ll a, ll b) {
	return ((a%b) + b) % b;
}

// computes gcd(a,b)
ll gcd(ll a, ll b) {
	while (b) { ll t = a%b; a = b; b = t; }
	return a;
}

// computes lcm(a,b)
ll lcm(ll a, ll b) {
	return a / gcd(a, b)*b;
}

// (a^b) mod m via successive squaring
int powermod(ll a, ll b, ll m)
{
	ll ret = 1;
	while (b)
	{
		if (b & 1) ret = mod(ret*a, m);
		a = mod(a*a, m);
		b >>= 1;
	}
	return ret;
}

// returns g = gcd(a, b); finds x, y such that d = ax + by
ll extended_euclid(ll a, ll b, ll &x, ll &y) {
	ll xx = y = 0;
	ll yy = x = 1;
	while (b) {
		ll q = a / b;
		ll t = b; b = a%b; a = t;
		t = xx; xx = x - q*xx; x = t;
		t = yy; yy = y - q*yy; y = t;
	}
	return a;
}


// computes b such that ab = 1 (mod n), returns -1 on failure
ll mod_inverse(ll a, ll n) {
	ll x, y;
	ll g = extended_euclid(a, n, x, y);
	if (g > 1) return -1;
	return mod(x, n);
}


int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
    ll ans=0;

	for(int i=1;i<=n;i++)
		cin>>arr[i];
    
    pow2[0]=1;
    for(int i=1;i<=n;i++)
    pow2[i]= mod(2*pow2[i-1],m);
    
    ll temp;
    if(n>2)
    {
     temp=pow2[n-1]-n;
    dp1[2]=mod(arr[2]*temp,m);

    temp=pow2[n]-pow2[n-2]-n-1;
    dp2[2]=mod(arr[2]*temp,m);

    dp3[2]=mod(arr[2]*(n-1),m);
    temp=mod(n*arr[2],m);
    
    ans=mod(ans+dp1[2],m);
    //cout<<"now ans is "<<ans<<endl;
    ans=mod(ans+dp2[2],m);
    //cout<<"now ans is "<<ans<<endl;
    ans=mod(ans+dp3[2],m);
    //cout<<"now ans is "<<ans<<endl;
    ans=mod(ans+temp,m);
    //cout<<"now ans is "<<ans<<endl;
    }
    
    temp=pow2[n]-1;
    temp=mod(arr[1]*temp,m);
    ans=mod(ans+temp,m);
    //cout<<"now ans is "<<ans<<endl;

    temp=pow2[n]-1;
    temp=mod(arr[n]*temp,m);
    ans=mod(ans+temp,m);
    // cout<<"now ans is "<<ans<<endl;

    for(int i=2;i<n-1;i++)
    {
      temp=mod_inverse(arr[i],m);
      //cout<<"mod inverse is "<<temp<<endl;
      temp=mod(dp1[i]*temp,m);
      //cout<<"after division "<<temp<<endl;
      temp=mod(temp*arr[i+1],m);
      dp1[i+1]=temp;
      temp=mod((i+1)*pow2[n-i-1],m);
      temp=mod(temp*arr[i+1],m);
      dp1[i+1]=mod(dp1[i+1]+temp,m);
      temp=mod((n-i+1)*pow2[i-1],m);
      temp=mod(temp*arr[i+1],m);
      dp1[i+1]=mod(dp1[i+1]-temp,m);

      temp=mod_inverse(2*arr[i],m);
      temp=mod(dp2[i]*temp,m);
      temp=mod(temp*arr[i+1],m);
      dp2[i+1]=temp;
      temp=mod(arr[i+1]*pow2[n-i-1],m);
      dp2[i+1]=mod(dp2[i+1]+temp,m);
      temp=mod_inverse(2,m);
      temp=mod((n+1)*temp,m);
      temp=mod(arr[i+1]*temp,m);
      dp2[i+1]=mod(dp2[i+1]-temp,m);

      temp=mod_inverse(arr[i],m);
      temp=mod(2*temp,m);
      temp=mod(temp*dp3[i],m);
      temp=mod(temp*arr[i+1],m);
      dp3[i+1]=temp;
      temp=mod(arr[i+1]*(n+1),m);
      dp3[i+1]=mod(dp3[i+1]+temp,m);
      temp=mod(pow2[i]*arr[i+1],m);
      dp3[i+1]=mod(dp3[i+1]-temp,m);
    
      temp=mod(n*arr[i+1],m);

      ans=mod(ans+dp1[i+1],m);
      //cout<<"now ans is "<<ans<<endl;
      ans=mod(ans+dp2[i+1],m);
      //cout<<"now ans is "<<ans<<endl;
      ans=mod(ans+dp3[i+1],m);
      //cout<<"now ans is "<<ans<<endl;
      ans=mod(ans+temp,m);  
    //  cout<<"now ans is "<<ans<<endl;
    }
   
   cout<<ans<<endl;
   return 0;
}