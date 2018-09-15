#include<bits/stdc++.h>
using namespace std;

#define in(n) scanf("%d",&n)

int main()
{
	int t,r,i;
	int pos[2][3];
	int dis1,dis2,flag;
	
    in(t);
    while(t--)
    {
    	in(r);
    	r=r*r;
    	flag=0;
    	
    	for(i=0;i<3;i++)
    	{
    		in(pos[0][i]);
    		in(pos[1][i]);
		}
		
		for(i=0;i<3;i++)
		{
			dis1=(pos[1][i]-pos[1][(i+1)%3])*(pos[1][i]-pos[1][(i+1)%3])+(pos[0][i]-pos[0][(i+1)%3])*(pos[0][i]-pos[0][(i+1)%3]);
			dis2=(pos[1][i]-pos[1][(i+2)%3])*(pos[1][i]-pos[1][(i+2)%3])+(pos[0][i]-pos[0][(i+2)%3])*(pos[0][i]-pos[0][(i+2)%3]);
			
			if(dis1<=r && dis2<=r )
			{
			flag=1;
			break;
		    }
		}
		
		if(flag)
		cout<<"yes\n";
		else
		cout<<"no\n";
	}
	return 0;
}

