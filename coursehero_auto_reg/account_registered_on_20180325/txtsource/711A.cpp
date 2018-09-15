#include<bits/stdc++.h>
using namespace std;

int  main()
{
	int n;
	char arr[1010][5];
	cin>>n;
	bool flag=false;

	for(int i=0;i<n;i++)
	{
        for(int j=0;j<5;j++)
        	cin>>arr[i][j];

        if(arr[i][0]=='O' and arr[i][1]=='O' and flag==false)
        {
        	flag=true;
        	arr[i][0]=arr[i][1]='+';
        }
        else if(arr[i][3]=='O' and arr[i][4]=='O' and flag==false)
        {
        	flag=true;
        	arr[i][3]=arr[i][4]='+';
        }
	}

	if(flag)
	{
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<5;j++)
				cout<<arr[i][j];
			cout<<endl;
		}
	}
	else
		cout<<"NO";

	return 0;
}