#include<iostream>
using namespace std;

int arr[1000000]={0};

int gcd(int a ,int b)
{
	if(b==0)
	return a;
	
	else
	return gcd(b,a%b);
}
int main()
{
	int m,h1,a1,x1,y1,h2,a2,x2,y2,t1=1,t2=1,i;
	cin>>m;
	cin>>h1>>a1;
	cin>>x1>>y1;
	cin>>h2>>a2;
	cin>>x2>>y2;
	
	 h1=(x1*h1+y1)%m;
	
	while(1)
	{
		if(arr[h1]==1)
		{cout<<-1;
		return 0;
	    }
	    
		if(h1==a1)
		break;

		else
		{t1++;
		arr[h1]=1;
	    }
		
		h1=(x1*h1+y1)%m;
	}
	
	for(i=0;i<m;i++)
	arr[i]=0;
	
	 h2=(x2*h2+y2)%m;
	while(1)
	{
		if(arr[h2]==1)
		{cout<<-1;
		return 0;
	    }
	    
		if(h2==a2)
		break;

		else
		{t2++;
		arr[h2]=1;
	    }
		
		h2=(x2*h2+y2)%m;
	}
	
	if(t1==t2)
	cout<<t1;
	
	else 
	{
		int d=gcd(t1,t2);
		d=(t1*t2)/d;
		cout<<d;
	}
	return 0;
}
