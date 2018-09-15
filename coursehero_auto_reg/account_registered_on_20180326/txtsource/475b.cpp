#include<bits/stdc++.h>
using namespace std;
int n,m;
char c;
int hor[21];
int ver[21];
int junc[21][21];
int done[21][21];
queue<pair <int,int> > q;

void bfs(int sourcex,int sourcey)
{
	done[sourcex][sourcey]=1;
	q.push(make_pair(sourcex,sourcey));
	//cout<<"pushed "<<sourcex<<" "<<sourcey<<endl;
	while(q.empty()==false)
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		if(done[x+hor[y]][y]==0 && (x+hor[y]>0 && x+hor[y]<=m) &&(y>0 && y<=n))
		{
			done[x+hor[y]][y]=1;
			q.push(make_pair(x+hor[y],y));
			//cout<<"pushed "<<x+hor[y]<<" "<<y<<endl;
		}
		if(done[x][y+ver[x]]==0 && (x>0 && x<=m) && (y+ver[x]>0 && y+ver[x]<=n))
		{
			done[x][y+ver[x]]=1;
			q.push(make_pair(x,y+ver[x]));
			//cout<<"pushed "<<x<<" "<<y+ver[x]<<endl;
		}
		
	}
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		if(c=='>')
		hor[i]=1;
		else
		hor[i]=-1;
	}
	
	
	for(int i=1;i<=m;i++)
	{
		cin>>c;
		if(c=='^')
		ver[i]=-1;
		else
		ver[i]=1;
	}

	for(int k=1;k<=m;k++)
	{
		for(int l=1;l<=n;l++)
		{
			for(int i=1;i<=m;i++)
	        {
		          for(int j=1;j<=n;j++)
		          done[i][j]=0;
	        }
	        
			bfs(k,l);
			for(int i=1;i<=m;i++)
	        {
		          for(int j=1;j<=n;j++)
		          if(done[i][j]==0)
		          {
		          	//cout<<k<<l<<endl;
		          	//cout<<i<<j<<endl;
		          	cout<<"NO";
		          	return 0;
				  }
	        }
		}
		
	}
	cout<<"YES";
	return 0;
}
