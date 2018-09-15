#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll arr[1010][1010];
int main()
{
	int n,m,s,t;
	ll L;
	
	for(int i=0;i<1010;i++)
		for(int j=0;j<1010;j++)
			arr[i][j]=-1;

	cin>>n>>m>>L>>s>>t;
    for(int i=0;i<m;i++)
    {
    	int u,v;
    	ll w;
    	cin>>u>>v>>w;
    	arr[u][v]=arr[v][u]=w;
    }

    int count=0;
    

	return 0;
}