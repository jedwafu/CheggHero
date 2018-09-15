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
    long long int freq[1000010];
    map<long long,long long> freq2;
    set<long long int>cfreq;
    stack<long long int> s;
     
    int main()
    {
    	int n,m;
    	scanf("%d %d",&n,&m);
    	
    	freq2.clear();
    	
    	for(int i=0;i<n;i++)
    	scanf("%lld",&arr[i]);
    	
    	for(int i=0;i<n;i++)
    	{
    		while(s.empty()==false and arr[s.top()]<arr[i])
    		{
    			long long temp=s.top();
    			s.pop();
    			freq[temp]=i-temp;
    		}
    		
    		s.push(i);
    	}
    	
    	while(s.empty()==false)
    	{
    		long long temp=s.top();
    		freq[temp]=n-temp;
    		s.pop();
    	}
    	
    	
    	for(int i=n-1;i>=0;i--)
    	{
    		while(s.empty()==false and arr[s.top()]<=arr[i])
    		{
    			long long temp=s.top();
    			s.pop();
    			freq[temp]*=temp-i;
    		}
    		s.push(i);
    	}
    	
    	while(s.empty()==false)
    	{
    		long long temp=s.top();
    		freq[temp]*=temp+1;
    		s.pop();
    	}
    	
    	for(int i=0;i<n;i++)
    	{
    		freq2[arr[i]]+=freq[i];
    	}
    	
    	long long temp=0;
    	
    	tr(freq2,it)
    	{
    		temp+=it->second;
    		freq2[it->first]=temp;
    		cfreq.insert(it->first);
    	}
    	
    	for(int i=1;i<m;i++)
    	{
    		char c,x,t;
    		long long int k,ans=0;
    		//t=getchar();
    		//scanf("%c %lld %c",&c,&k,&x);
    		c='<';
    		k=i;
    		x='D';
    		
    		if(k>*(--cfreq.end()))
    		ans=freq2[*(--cfreq.end())];
    		
    		else
    		{
    		
    		typeof(cfreq.begin()) it = cfreq.lower_bound(k);
    			
    		if(c=='<' and it!=cfreq.begin())
    		{
    			it--;
    			ans=freq2[*it]%2;
    		}
    		
    		else if(c=='>')
    		{
    			typeof(it) it2=cfreq.end();
    			it2--;
    			
    		    if(*it!=k and it==cfreq.begin())
    		    ans=freq2[*it2];
    		    
    		    else
    		   {
    			 
    			if(*it!=k)	
    			it--;
    			
    			ans=(freq2[*it2]-freq2[*it]);
    		   }
    		}
    		
    		else if(c=='=')
    		{
    			if(*it==k and it!=cfreq.begin())
    			ans=freq2[k]-freq2[*(--it)];
    			
    			else if(*it==k)
    			ans=freq2[k];
    			
    			else
    			ans=0;
    		}
    	    }
    	    cout<<i<<" ";
    		if(ans %2)
    		{
    			if(x=='D')
    			printf("D");
    			else
    			printf("C");
    		}
    		else
    		{
    			if(x=='C')
    			printf("D");
    			else
    			printf("C");
    		}
    		cout<<endl;
     	}
    	
    	return 0;
    }
     
