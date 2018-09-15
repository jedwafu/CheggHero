#include <iostream>
#include<string>
using namespace std;

#define loop(i,a,b) for(int i=int(a);i<=int(b);++i)

int main()
{
	int t;
	cin>>t;
	loop(i,1,t)
	{
		int smax;
		string s;
		cin>>smax;
		cin>>s;
		int sum=s[0]-'0',ans=0;
		
		if(s[0]==0)
		ans++,sum++;
		
		loop(j,1,s.length()-1)
		{
			if(sum<j)
			{
			  ans+=j-sum;
			  sum+=j-sum;
		    }
		    
		    sum+=s[j]-'0';
		}
		
		cout<<"Case #"<<i<<": "<<ans<<endl;

	}
	return 0;
}
