#include<bits/stdc++.h>
using namespace std;

char arr[110][110];
int n;
bool edges[26][26];
int starts[26];
int finish[26];
int done[26];
int times=0;
queue<int> q;
bool dfs(int source)
{
	done[source]=1;
	starts[source]=times;
	times++;
	for(int j=0;j<26;j++)
	{
		if(edges[source][j]==true && done[j]!=2)
		{
			if(done[j]==1)
			return false;
			
			
			bool val=dfs(j);
			if(val==false)
			return false;
			
		}
	}
	finish[source]=times;
	times++;
	done[source]=2;
	q.push(source);
	return true;
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",arr[i]);
	}
	
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
		   edges[i][j]=false;
		   done[i]=0;
 	    } 
	}
	
	for(int i=0;i<n-1;i++)
	{
		int len1=strlen(arr[i]);
		int len2=strlen(arr[i+1]);
		if(len1>len2)
		{
			int j;
			for( j=0;j<len2;j++)
			{
				if(arr[i][j]!=arr[i+1][j])
				{
					edges[arr[i+1][j]-'a'][arr[i][j]-'a']=true;
					j=0;
					break;
				}
		    }
				if(j==len2)
				{
				cout<<"Impossible";
				return 0;
			    }	
			
		}
		
		else
		{
			for(int j=0;j<len1;j++)
			{
				if(arr[i][j]!=arr[i+1][j])
				{
					edges[arr[i+1][j]-'a'][arr[i][j]-'a']=true;
					break;
				}
			}
		}
		
	}
	
	for(int i=0;i<26;i++)
	{
		bool val;
		if (done[i]==false)
		 val=dfs(i);
		
		if(val==false)
		{
			cout<<"Impossible";
			return 0;
		}
	}
		
		
			while(q.empty()==false)
			{
				char top=q.front()+'a';
			    q.pop();
			    cout<<top;
			}
		
	return 0;	
}

