#include<bits/stdc++.h>
using namespace std;
#define INF 1e16

int parents[100010];
int friends[100010];
vector<pair <int,int> > ticket[100010];
long long int dp[1010][1010];

long long int prices(int city,int tickets)
{
     //cout << city << " " << tickets << "\n";
     if(city == 1)
        return 0;
     
     //dp[make_pair(city,tickets)]++; //random bullshit
     //dp[make_pair(city,tickets)]--; //random bullshit

     if(dp[city][tickets] != -1)
     return dp[city][tickets];

      
     long long int mini=INF;
     
     if(tickets>0)
     mini=prices(parents[city],tickets-1);

     for(int i=0;i<ticket[city].size();i++)
     {
          mini=min(mini,prices(parents[city],ticket[city][i].first-1)+ticket[city][i].second);
     } 

     dp[city][tickets]=mini;
     return dp[city][tickets];
}

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<n-1;i++)
    {
      cin>>a>>b;
      parents[a]=b;
    }
    
    for(int i=1;i<=n;i++)
    for(int j=0;j<=n;j++)
        dp[i][j] = -1;

    long long int c;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        ticket[a].push_back(make_pair(b,c));
    }

    int q;
    cin>>q;

    for(int i=0;i<q;i++)
    cin>>friends[i];
    
    for(int i=0;i<q;i++)
    {
        int city=friends[i];
        cout<<prices(city,0)<<endl;
    }
   
    return 0;

}