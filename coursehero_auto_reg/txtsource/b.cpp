#include<bits/stdc++.h>
using namespace std;

#define take(n) scanf("%d",&n)
#define loop(i,a,b) for(long long int i=a;i<b;i++)
#define eps 0.000001

long long int arr[200010];
int main()
{
	long long int n,w,temp;
	cin>>n>>w;
	long long int l=2*n;
	loop(i,0,l)
	{
		cin>>arr[i];
	}
	
	sort(arr,arr+l);
	 double d1=(double)arr[0];
	 double d2=(double)arr[n]/2.0;
	 double check=min(d1,d2);
	//long double x= (long double)(w)/(long double)(3*(long double)n);
	//x=min(x,(long double)check
	
	printf("%.6f",min(3*check*n,  double(w)));
	return 0;
}
