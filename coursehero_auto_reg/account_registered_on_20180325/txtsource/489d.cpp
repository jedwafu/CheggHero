#include<bits/stdc++.h>
using namespace std;

bool mat[3001][3001];
vector<int> v[3010];
int main()
{
	int n,m,a,b,result=0;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	mat[i][j]=false;
	
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		mat[a][b]=true;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			
			if(i!=j)
			{
				int r=0;
				for(int k=0;k<v[i].size();k++)
				{
					if(mat[v[i][k]][j]==true)
					r++;
				}
				result+=(r*(r-1))/2;
			}
		}
	}
	
	cout<<result;
}
