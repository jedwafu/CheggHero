#include<bits/stdc++.h>
using namespace std;

int arr[1010];
bool visited[1010];
int main()
{
	int n,s,e;
	cin>>n;

	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		visited[i]=false;
	}
	
	cin>>s>>e;
    bool ans=false;
	while(visited[s]==false)
	{
		visited[s]=true;
		if(s==e)
		{
			ans=true;
			break;
		}
		else
			s=arr[s];
	}

	if(ans)
		cout<<"Yes";
	else
		cout<<"No";

	return 0;

}