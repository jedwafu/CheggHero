#include<bits/stdc++.h>
using namespace std;

bool is_integer(float k)
{
  return std::floor(k) == k;
}

int main()
{
	int a,b,c,d;
	long long ans=0;
	cin>>a>>b>>c>>d;
	if(a+b>c and a+c>b and b+c>a)
	ans++;
	
	for(int l=1;l<=d;l++)
	{
	int k1=(c+l)+(b-a);
	int k2=(c+l)+(a-b);
	
	if(k1%2==0)
	k1=k1/2-1;
	else
	k1=k1/2;
	
	if(k2%2==0)
	k2=k2/2-1;
	else
	k2=k2/2;
	
	long long area=0;
	int val=(c+l)-(a+b);
    if(val%2==0)
    val=val/2;
    else
    val=val/2+1;
    
    ans+= (k1+1)*(k2+1)-((val*val +val +2)/2);
    }
    
    cout<<ans<<endl;
}
