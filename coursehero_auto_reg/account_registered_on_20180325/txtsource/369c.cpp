#include<bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for(int i=a;i<=b;i++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
vector< pair<int,int> > ver[100010];
bool done[100010];
int n;
set<int> s;

bool func(int source)
{
	done[source]=true;
	int count=0;
	for(int i=0;i<ver[source].size();i++)
	{
		if(done[ver[source][i].first]==false)
		{
			bool val=func(ver[source][i].first);
			
			if(val==false && ver[source][i].second==2)
			{
			  s.insert(ver[source][i].first);
			  count++;
		    }
		    
		    if(val==true)
		    count=1;
     	}
	}
	if(count>0)
	return true;
	else
	return false;
}

int main()
{
	cin>>n;
	int a,b,c;
	fr(i,0,n-2)
	{
		done[i+1]=false;
		cin>>a>>b>>c;
		ver[a].push_back(make_pair(b,c));
		ver[b].push_back(make_pair(a,c));
	}
	
	done[n]=false;
	
	bool ans=func(1);
	
	cout<<s.size()<<endl;
	tr(s,it)
	{
		cout<<*it<<" ";
	}
	return 0;
}
