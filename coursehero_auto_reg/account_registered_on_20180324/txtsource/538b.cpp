#include<bits/stdc++.h>
using namespace std;

int arr[10];
int main()
{
	int n;
	cin>>n;

	int dup=n;
	int count=0;

	while(dup>0)
		dup=dup/10,count=count+1;

    int maxi=0;
    for(int i=count-1;i>=0;i--)
    {
    	arr[i]=n%10;
    	n=n/10;
        maxi=max(maxi,arr[i]);
    }
   
    cout<<maxi<<endl;
    
    vector<int> v;
    for(int i=0;i<maxi;i++)
    {
    	v.clear();
    	for(int j=0;j<count;j++)
    	{
    		if(arr[j]>0)
    			v.push_back(1);
    		else if(!v.empty())
    			v.push_back(0);

    		arr[j]--;
    	}

    	for(int j=0;j<v.size();j++)
    	cout<<v[j];

    	cout<<" "; 
    }

    return 0;

}