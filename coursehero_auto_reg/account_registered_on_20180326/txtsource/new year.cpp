#include<bits/stdc++.h>
using namespace std;


typedef vector<int> vi;
#define pb push_back

int mat[301][301];
vi perm;
vi done;
vi help;
vi sorted;
int n;
queue<int> q;

void bfs(int source)
{
	done[source]=1;
	q.push(source);
	while(q.empty()==false)
	{
		int top=q.front();
		q.pop();
		help.pb(top);
		
		for(int i=1;i<=n;i++)
		{
			if(mat[top][i]==1 && done[i]==0)
			{
				done[i]=1;
				q.push(i);
			}
		}
	}
	
}

int main()
{
	int temp,i;
	char c;
	cin>>n;
	perm.pb(0);
	done.pb(0);
	for( i=1;i<=n;i++)
	{
		cin>>temp;
		perm.pb(temp);
		done.pb(0);
	}
	
	for( i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>c;
			if(c=='1')
		    mat[i][j]=1;
		    else
		    mat[i][j]=0;
		}
	}
	
	for(i=1;i<n;i++)
	{
		if(done[i]==0)
		{
		   bfs(i);
		   
		   
		   for(int j=0;j<help.size();j++)
		   sorted.pb(perm[help[j]]);
		   
		   
		   sort(help.begin(),help.end());
		   sort(sorted.begin(),sorted.end());
		   
		   for(int j=0;j<help.size();j++)
		   {
		   	 perm[help[j]]=sorted[j];
		   }
		   
		   help.clear();
		   sorted.clear();
		}
    }
    
    for(i=1;i<n;i++)
    cout<<perm[i]<<" ";
    cout<<perm[i];
    
    return 0;
}
