#include<bits/stdc++.h>
using namespace std;

// taken from http://stackoverflow.com/questions/14093417/find-the-inverse-of-a-number-modulo-a-prime
void EE(long long int a, long long int b, long long int& x, long long int& y)
{
    if(a%b == 0)
    {
        x=0;
        y=1;
        return;
    }
    EE(b,a%b,x,y);
    long long int temp = x;
    x = y;
    y = temp - y*(a/b);
}
int inverse(long long int a, long long int m)
{
    long long int x,y;
    EE(a,m,x,y);
    if(x<0) x += m;
    return x;
}

long long int arr[200010];
long long int freq[100010];
long long int modinv[100010];

int main()
{
	long long int n,p;
	cin>>n>>p;

    for(int i=0;i<p;i++)
    {	
    	freq[i]=0;
    	modinv[i]=p;
    }

	for(int i=0;i<n;i++)
	{
        cin>>arr[i];
        arr[i]=arr[i]%p;

        if(arr[i]<0)
        	arr[i]+=p;

        freq[arr[i]]++;
	}
     
    for(int i=0;i<n;i++)
    {
    	if(modinv[arr[i]]==p and arr[i]!=0)
    	{
    		modinv[arr[i]]=inverse(arr[i],p);
    		modinv[modinv[arr[i]]]=arr[i];
    	}
    		
    }
    
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        ans++;

       else if(arr[i]==1 or arr[i]==(p-1))
        continue;

        else if(freq[arr[i]]>freq[modinv[arr[i]]])
        ans++;

        else if(freq[arr[i]]==freq[modinv[arr[i]]] and arr[i] < modinv[arr[i]])
        ans++;

    }

    cout<<ans;
    return 0;


}