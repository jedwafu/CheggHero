#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
vector< pair<int, pair<int,int> > > v;
bool edge[101][101];
bool path[101][101];
bool done[101];
queue<int> q;
int n,k=0;
void bfs(int source)
{
	done[source]=true;
	q.push(source);
	while(q.empty()==false)
	{
		int top=q.front();
		q.pop();
		for(int i=1;i<=n;i++)
		{
			if(edge[top][i]==true && done[i]==false)
			{
				done[i]=true;
				path[source][i]=true;
				q.push(i);
			}
		}
	}
}


int main()
{
	int a,b,c;
	cin>>n;
	
	for(int i=1;i<=100;i++)
	for(int j=1;j<=100;j++)
	{
	  path[i][j]=false;
	  edge[i][j]=false;
	  
	}
	
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		if(a==1)
		{
			k++;
		    v.push_back(mp(c,mp(b,c)));
		
		    if(k>1)
		    {
			   for(int j=0;j<k-1;j++)
			   {
				  if((v[j].second.first>b && c>v[j].second.first) ||(v[j].second.second>b && c>v[j].second.second) )
				  {
				    path[j+1][k]=true;
				    edge[j+1][k]=true;
			      } 
				   if((v[j].second.first<b && b<v[j].second.second)||(v[j].second.first<c && c<v[j].second.second))
				  {
				  	path[k][j+1]=true;
				    edge[k][j+1]=true;
					}  
		       }
		
	        }
		}
		
	    else
	    {
	    	if(path[b][c]==true)
	    	{
	    		cout<<"YES\n";
			}
			else
			{
				for(int l=1;l<=n;l++)
				done[l]=false;
				
				bfs(b);
				if(path[b][c]==true)
				cout<<"YES\n";
				else
				cout<<"NO\n";
			}
		}
	    
	}
	return 0;
}
