#include<bits/stdc++.h>
using namespace std;

int n,m;
int edges[2][100010];
int done[100010];
bool bus()
{
	int count=0,count2=0;
	if(m!=n-1)
	return false;
	
	for(int i=1;i<=n;i++)
	{
		if(done[i]==2)
		count++;
		else if(done[i]==1)
		count2++;
	}
	if(count==n-2 && count2==2)
	return true;
	else
	return false;
}

bool ring()
{
	int count=0;
	if(m!=n)
	return false;
	for(int i=1;i<=n;i++)
	{
		if(done[i]==2)
		count++;
	}
	if(count==n)
	return true;
	else
	return false;
}

bool star()
{
	int count=0;
	if(m!=n-1)
	return false;
	for(int i=1;i<=n;i++)
	{
	    if(done[i]==m)
		count++;
	}
	if(count==1)
	return true;
	else
	return false;
	
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<=n;i++)
	{
		done[i]=0;
	}
	
	for(int i=1;i<=m;i++)
	{
		cin>>edges[0][i]>>edges[1][i];
        done[edges[0][i]]++;
        done[edges[1][i]]++;
	}
	
	if(bus()==true)
	{
		cout<<"bus topology";
		return 0;
	}
	
	if(ring()==true)
	{
		cout<<"ring topology";
		return 0;
	}
	
	if(star()==true)
	{
		cout<<"star topology";
		return 0;
	}
	else
	cout<<"unknown topology";
	return 0;
}
