#include<bits/stdc++.h>
using namespace std;

int dp[100010];
int main()
{
	string s;
	cin>>s;

    int len=s.length();
    
    dp[0]=0;
    for(int i=1;i<len;i++)
    dp[i]=(s[i]==s[i-1])? dp[i-1]+1:dp[i-1];
	
	int m;
	cin>>m;
    
	for(int i=0;i<m;i++)
	{
		int l,r;
		cin>>l>>r;

		cout<<dp[r-1]-dp[l-1]<<endl;
	}
	return 0;
}