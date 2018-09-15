#include<bits/stdc++.h>
using namespace std;


struct node
{
	int parent;
	vector<int> next;
	int distance;
	int coins;
};

void dfs( node *point,int l)
{
	int j;
	for(j=0;j<point[l].next.size();j++)
    {
    	point[point[l].next[j]].distance=point[l].distance+1;
    	dfs(point,point[l].next[j]);
	}
	
}

struct node point[100001];
int main()
{
	int n,m,i,j,a,b,y,k;
	cin>>n>>m;
	
	
	point[1].parent=0;
	point[1].distance=0;
	point[1].coins=0;
	
	
	for(i=0;i<n-1;i++)
	{
		cin>>a>>b;
		point[b].parent=a;
		point[b].coins=0;
		point[a].coins=0;
		point[a].next.push_back(b);
	}
	
    dfs(point,1);
	
    for(i=0;i<m;i++)
    {
    	cin>>a>>b;
    	
    	if(a==1 && b!=0)
    	{
    		cin>>y;
    		
    		for(j=2;j<=n;j++)
    		{
    			if(point[j].distance==b)
    			{
    				point[j].coins+=y;
    				k=j;
    			    while(k>1)
    			    {
    			    	point[point[k].parent].coins+=y;
    			    	k=point[k].parent;
					}
				}
			}
		}
		
		if(a==1 && b==0)
		{
			cin>>y;
			point[1].coins+=y;
		}
		
		if(a==2)
		{
			cout<<point[b].coins<<endl;
		}
	}
    	
	return 0;
	
}
