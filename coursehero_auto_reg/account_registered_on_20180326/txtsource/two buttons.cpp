#include<bits/stdc++.h>
using namespace std;

vector<int> ver;
bool discovered[10001];
vector<int> dis(10001);
queue<int> q;

void bfs(int n,int m)
{
	dis[n]=0;
	discovered[n]=true;
	q.push(n);
	while(q.empty()==false)
	{
		int top=q.front();
		q.pop();
		
        if(discovered[top*2]==false && top*2<=10000)
        {
        	discovered[top*2]=true;
        	dis[top*2]=dis[top]+1;
        	if(top*2==m)
        	return;
        	else
        	q.push(top*2);
		}
		
		if(discovered[top-1]==false && top-1>0)
		{
			discovered[top-1]=true;
			dis[top-1]=dis[top]+1;
			if(top-1==m)
			return;
			else
			q.push(top-1);
		}
		
	}
	
	
}



int main()
{
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		ver.push_back(i);
		dis[i]=10005;
		discovered[i]=false;
	}
	if(m<n)
	{
		cout<<n-m;
		return 0;
	}
	
	bfs(n,m);
	cout<<dis[m];
	
	return 0;
}
