#include <bits/stdc++.h>
using namespace std;

#define INF 10000000

typedef long long ll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef map<string, int> msi;

#define all(x) x.begin(), x.end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define spresent(c,x) ((c).find(x) != (c).end())  // for set,map
#define present(c,x) (find(all(c),x) != (c).end())  // for vector
#define F first
#define S second
#define loop(i,a,b) for(int i=int(a);i<=int(b);++i)
#define nloop(i,a,b) for(int i= int(a);i>=int(b);--i)

long long int arr[1000010];
map<long long ,long long> freq;
set<long long int> cfreq;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&arr[i]);
		freq[arr[i]]++;
	}
	
	for(int i=0;i<n-1;i++)
	{
		long long maxi=max(arr[i],arr[i+1]);
		freq[maxi]++;
		
	    for(int j=i+2;j<n;j++)
	    {
	    	maxi=max(arr[j],maxi);
	    	freq[maxi]++;
		}
	}
	
	long long temp=0;
	
	tr(freq,it)
	{
		temp+=it->second;
		freq[it->first]=temp;
		cfreq.insert(it->first);
	}
	
	for(int i=0;i<m;i++)
	{
		char c,x;
		long long int k,ans=0;
		cin>>c>>k>>x;
		
		if(k>*(--cfreq.end()))
		ans=freq[*(--cfreq.end())];
		
		else
		{
		
		typeof(cfreq.begin()) it = cfreq.lower_bound(k);
			
		if(c=='<' and it!=cfreq.begin())
		{
			it--;
			ans=freq[*it]%2;
		}
		
		if(c=='>')
		{
			typeof(it) it2=cfreq.end();
			it2--;
			
		    if(*it!=k and it==cfreq.begin())
		    ans=freq[*it2];
		    
		    else
		   {
			 
			if(*it!=k)	
			it--;
			
			ans=(freq[*it2]-freq[*it]);
		   }
		}
		
		if(c=='=')
		{
			if(*it==k and it!=cfreq.begin())
			ans=freq[k]-freq[*(--it)];
			else if(*it==k)
			ans=freq[k];
			
			else
			ans=0;
		}
	    }
	    
		if(ans %2)
		{
			cout<<ans<<endl;
			if(x=='D')
			cout<<"D";
			else
			cout<<"C";
		}
		else
		{
			cout<<ans<<endl;
			if(x=='C')
			cout<<"D";
			else
			cout<<"C";
		}
 	}
	
	return 0;
	
}
