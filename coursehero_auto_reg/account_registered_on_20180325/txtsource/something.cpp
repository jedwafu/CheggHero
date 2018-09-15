#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int minim(int a,int b,int c)
{
	if(a<=b and a<=c)
		return 1;
     
    else if(b<=a and b<=c)
    	return 2;

    else if(c<=a and c<=b)
    	return 3;
    else
    	return 0;

}

int main()
{
    int x,y;
    cin>>x>>y;
    
    int side1,side2,side3;
    side1=side2=side3=y;
    int count=0;
    bool flag=true;
    while(flag)    
    {
    	int mini=minim(side1,side2,side3);
    	if(mini==1)
        {
          side1=min(x,side2+side3-1);
          count++;
        }	
        if(mini==2)
        {
        	side2=min(x,side1+side3-1);
        	count++;
        }
        if(mini==3)
        {
        	side3=min(x,side1+side2-1);
        	count++;
        }

        if(side1==side2 and side2==side3 and side3==x)
        	flag=false;
    }

   cout<<count<<endl;
    return 0;
        
    	
}