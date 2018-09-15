#include<bits/stdc++.h>
using namespace std;

int point[2][101];
int done[101];

queue<int> q;
int n;
void bfs(int source)
{
	done[source]=1;
	q.push(source);
	while(q.empty()==false)
	{
		int top=q.front();
		q.pop();
		for(int j=1;j<=n;j++)
		{
			if(j==top)
			continue;
			
			if((point[0][top]==point[0][j] || point[1][top]==point[1][j]) && done[j]==0)
			{
				done[j]=1;
				q.push(j);
			}
		}
	}
}

int main()
{
	int count=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	   cin>>point[0][i]>>point[1][i];
	   done[i]=0;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(done[i]==0)
		{
			bfs(i);
			count++;
		}
	}
	
	cout<<count-1;
	return 0;
}
