#include<bits/stdc++.h>
using namespace std;

int x[55];
int v[55];
int main()
{
	int c,n,k,t,i;
	long long int b;
	cin>>c;
	int d=c;
	while(c--)
	{

		cin>>n>>k>>b>>t;
		for(i=0;i<n;i++)
		{
			cin>>x[i];
		}
		
		for(i=0;i<n;i++)
		cin>>v[i];
	   
	   int slow = 0, fast = 0, swaps = 0;
		for ( i = n - 1; i >= 0; i--) {
                if (fast == k) break;
                if (x [i] + t * v [i] < b) slow++;
                else {
                    fast++;
                    swaps += slow;
                }
            }
            
            cout<<"Case #"<<d-c<<": ";
            if(fast>=k)
            cout<<swaps<<endl;
            else
            cout<<"IMPOSSIBLE"<<endl;
		
	}
	return 0;
}
