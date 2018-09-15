#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 1e5+10; 

void x2(int r,int c)
{
    cout<<r<<" "<<c<<" "<<r<<" "<<c+1<<endl;
  	cout<<r+1<<" "<<c<<" "<<r+1<<" "<<c+1<<endl;
  	cout<<r<<" "<<c<<" "<<r+1<<" "<<c<<endl;
  	cout<<r<<" "<<c+1<<" "<<r+1<<" "<<c+1<<endl;
}
void row(int r,int c)
{
   cout<<r<<" "<<c+1<<" "<<r<<" "<<c+2<<endl;
   cout<<r<<" "<<c+3<<" "<<r<<" "<<c+4<<endl;
   cout<<r<<" "<<c+2<<" "<<r<<" "<<c+3<<endl;
   cout<<r<<" "<<c+1<<" "<<r<<" "<<c+2<<endl;
   cout<<r<<" "<<c+2<<" "<<r<<" "<<c+3<<endl;
   cout<<r<<" "<<c+1<<" "<<r<<" "<<c+2<<endl;
   cout<<r<<" "<<c+3<<" "<<r<<" "<<c+4<<endl;
}
void column(int c,int r)
{
   cout<<r+1<<" "<<c<<" "<<r+2<<" "<<c<<endl;
   cout<<r+3<<" "<<c<<" "<<r+4<<" "<<c<<endl;
   cout<<r+2<<" "<<c<<" "<<r+3<<" "<<c<<endl;
   cout<<r+1<<" "<<c<<" "<<r+2<<" "<<c<<endl;
   cout<<r+2<<" "<<c<<" "<<r+3<<" "<<c<<endl;
   cout<<r+1<<" "<<c<<" "<<r+2<<" "<<c<<endl;
   cout<<r+3<<" "<<c<<" "<<r+4<<" "<<c<<endl;  
}

void reverse_col(int c,int r)
{
	cout<<r+4<<" "<<c<<" "<<r+5<<" "<<c<<endl;
	cout<<r+3<<" "<<c<<" "<<r+4<<" "<<c<<endl;
	cout<<r+4<<" "<<c<<" "<<r+5<<" "<<c<<endl;
	cout<<r+3<<" "<<c<<" "<<r+4<<" "<<c<<endl;
	cout<<r+5<<" "<<c<<" "<<r+6<<" "<<c<<endl;
	column(c,r);
	column(c,r+4);
}

void reverse_row(int r,int c)
{
	cout<<r<<" "<<c+4<<" "<<r<<" "<<c+5<<endl;
	cout<<r<<" "<<c+3<<" "<<r<<" "<<c+4<<endl;
	cout<<r<<" "<<c+4<<" "<<r<<" "<<c+5<<endl;
	cout<<r<<" "<<c+3<<" "<<r<<" "<<c+4<<endl;
	cout<<r<<" "<<c+5<<" "<<r<<" "<<c+6<<endl;
	row(r,c);
	row(r,c+4);
}

void big_col(int c,int r)
{
	   if(r==4)
	   {
	   	reverse_col(c,r);
	   	return;
	   }

	   column(c,r+0);
       column(c,r+4);
       cout<<r+4<<" "<<c<<" "<<r+5<<" "<<c<<endl;
       column(c,r+0);
       column(c,r+4);
}

void big_row(int r,int c)
{
	   if(c==4)
	   {
	   	reverse_row(r,c);
	   	return;
	   }
	   row(r,c+0);
       row(r,c+4);
       cout<<r<<" "<<c+4<<" "<<r<<" "<<c+5<<endl;
       row(r,c+0);
       row(r,c+4);
}

int main(){
  fast;
  int n;
  cin>>n;
  if(n==2)
  {
  	cout<<4<<endl;
  	x2(1,1);
  }
  if(n==4)
  {
  	 cout<<56<<endl;
     column(4,0);
     column(3,0);
     column(2,0);
     column(1,0);
     row(1,0);
     row(2,0);
     row(3,0);
     row(4,0);
  }

  if(n==5)
  {
  	cout<<160<<endl;
  	column(5,0);
  	cout<<4<<" "<<5<<" "<<5<<" "<<5<<endl;
  	cout<<3<<" "<<5<<" "<<4<<" "<<5<<endl;
  	column(5,0);
  	column(4,0);
  	cout<<4<<" "<<4<<" "<<5<<" "<<4<<endl;
  	cout<<3<<" "<<4<<" "<<4<<" "<<4<<endl;
  	column(4,0);
  	column(3,0);
  	cout<<4<<" "<<3<<" "<<5<<" "<<3<<endl;
  	cout<<3<<" "<<3<<" "<<4<<" "<<3<<endl;
  	column(3,0);
  	column(2,0);
  	cout<<4<<" "<<2<<" "<<5<<" "<<2<<endl;
  	cout<<3<<" "<<2<<" "<<4<<" "<<2<<endl;
  	column(2,0);
  	column(1,0);
  	cout<<4<<" "<<1<<" "<<5<<" "<<1<<endl;
  	cout<<3<<" "<<1<<" "<<4<<" "<<1<<endl;
  	column(1,0);

  	row(5,0);
  	cout<<5<<" "<<4<<" "<<5<<" "<<5<<endl;
  	cout<<5<<" "<<4<<" "<<5<<" "<<5<<endl;
  	row(5,0);
  	row(4,0);
  	cout<<4<<" "<<4<<" "<<4<<" "<<5<<endl;
  	cout<<4<<" "<<4<<" "<<4<<" "<<5<<endl;
  	row(4,0);
  	row(3,0);
  	cout<<3<<" "<<4<<" "<<3<<" "<<5<<endl;
  	cout<<3<<" "<<4<<" "<<3<<" "<<5<<endl;
  	row(3,0);
  	row(2,0);
  	cout<<2<<" "<<4<<" "<<2<<" "<<5<<endl;
  	cout<<2<<" "<<4<<" "<<2<<" "<<5<<endl;
  	row(2,0);
  	row(1,0);
  	cout<<1<<" "<<4<<" "<<1<<" "<<5<<endl;
  	cout<<1<<" "<<4<<" "<<1<<" "<<5<<endl;
  	row(1,0);
  }

  if(n==8)
  { 
  	   cout<<464<<endl;
       column(8,0);
       column(8,4);
       cout<<4<<" "<<8<<" "<<5<<" "<<8<<endl;
       column(8,0);
       column(8,4);
       column(7,0);
       column(7,4);
       cout<<4<<" "<<7<<" "<<5<<" "<<7<<endl;
       column(7,0);
       column(7,4);
       column(6,0);
       column(6,4);
       cout<<4<<" "<<6<<" "<<5<<" "<<6<<endl;
       column(6,0);
       column(6,4);
       column(5,0);
       column(5,4);
       cout<<4<<" "<<5<<" "<<5<<" "<<5<<endl;
       column(5,0);
       column(5,4);
       column(4,0);
       column(4,4);
       cout<<4<<" "<<4<<" "<<5<<" "<<4<<endl;
       column(4,0);
       column(4,4);
       column(3,0);
       column(3,4);
       cout<<4<<" "<<3<<" "<<5<<" "<<3<<endl;
       column(3,0);
       column(3,4);
       column(2,0);
       column(2,4);
       cout<<4<<" "<<2<<" "<<5<<" "<<2<<endl;
       column(2,0);
       column(2,4);
       column(1,0);
       column(1,4);
       cout<<4<<" "<<1<<" "<<5<<" "<<1<<endl;
       column(1,0);
       column(1,4);

       row(1,0);
       row(1,4);
       cout<<1<<" "<<4<<" "<<1<<" "<<5<<endl;
       row(1,0);
       row(1,4);
       row(2,0);
       row(2,4);
       cout<<2<<" "<<4<<" "<<2<<" "<<5<<endl;
       row(2,0);
       row(2,4);
       row(3,0);
       row(3,4);
       cout<<3<<" "<<4<<" "<<3<<" "<<5<<endl;
       row(3,0);
       row(3,4);
       row(4,0);
       row(4,4);
       cout<<4<<" "<<4<<" "<<4<<" "<<5<<endl;
       row(4,0);
       row(4,4);
       row(5,0);
       row(5,4);
       cout<<5<<" "<<4<<" "<<5<<" "<<5<<endl;
       row(5,0);
       row(5,4);
       row(6,0);
       row(6,4);
       cout<<6<<" "<<4<<" "<<6<<" "<<5<<endl;
       row(6,0);
       row(6,4);
       row(7,0);
       row(7,4);
       cout<<7<<" "<<4<<" "<<7<<" "<<5<<endl;
       row(7,0);
       row(7,4);
       row(8,0);
       row(8,4);
       cout<<8<<" "<<4<<" "<<8<<" "<<5<<endl;
       row(8,0);
       row(8,4);

  } 
  
  if(n==11)
  {
  	cout<<946<<endl;
  	column(11,7);
  	big_col(11,0);
  	column(11,7);
  	column(10,7);
  	big_col(10,0);
  	column(10,7);
  	column(9,7);
  	big_col(9,0);
  	column(9,7);
  	column(8,7);
  	big_col(8,0);
  	column(8,7);
  	column(7,7);
  	big_col(7,0);
  	column(7,7);
  	column(6,7);
  	big_col(6,0);
  	column(6,7);
  	column(5,7);
  	big_col(5,0);
  	column(5,7);
  	column(4,7);
  	big_col(4,0);
  	column(4,7);
  	column(3,7);
  	big_col(3,0);
  	column(3,7);
  	column(2,7);
  	big_col(2,0);
  	column(2,7);
  	column(1,7);
  	big_col(1,0);
  	column(1,7);

  	row(11,7);
  	big_row(11,0);
  	row(11,7);
  	row(10,7);
  	big_row(10,0);
  	row(10,7);
  	row(9,7);
  	big_row(9,0);
  	row(9,7);
  	row(8,7);
  	big_row(8,0);
  	row(8,7);
  	row(7,7);
  	big_row(7,0);
  	row(7,7);
  	row(6,7);
  	big_row(6,0);
  	row(6,7);
  	row(5,7);
  	big_row(5,0);
  	row(5,7);
  	row(4,7);
  	big_row(4,0);
  	row(4,7);
  	row(3,7);
  	big_row(3,0);
  	row(3,7);
  	row(2,7);
  	big_row(2,0);
  	row(2,7);
  	row(1,7);
  	big_row(1,0);
  	row(1,7);
  }

  if(n==13)
  {
  	cout<<1846<<endl;
     for(int i=1;i<=13;i++)
     {
     	column(i,9);
  	    big_col(i,2);
  	    column(i,9);
  	    column(i,0);
  	    column(i,3);
  	    column(i,6);
  	    column(i,9);
     }
     for(int i=1;i<=13;i++)
     {
     	row(i,9);
  	    big_row(i,2);
  	    row(i,9);
  	    row(i,0);
  	    row(i,3);
  	    row(i,6);
  	    row(i,9);
     }
  }

  if(n==16)
  {
  	  cout<<4320<<endl;
      big_col(16,0);
      big_col(16,8);
      reverse_col(16,4);
      big_col(16,0);
      big_col(16,8);
      big_col(15,0);
      big_col(15,8);
      reverse_col(15,4);
      big_col(15,0);
      big_col(15,8);
      big_col(14,0);
      big_col(14,8);
      reverse_col(14,4);
      big_col(14,0);
      big_col(14,8);
      big_col(13,0);
      big_col(13,8);
      reverse_col(13,4);
      big_col(13,0);
      big_col(13,8);
      big_col(12,0);
      big_col(12,8);
      reverse_col(12,4);
      big_col(12,0);
      big_col(12,8);
      big_col(11,0);
      big_col(11,8);
      reverse_col(11,4);
      big_col(11,0);
      big_col(11,8);
      big_col(10,0);
      big_col(10,8);
      reverse_col(10,4);
      big_col(10,0);
      big_col(10,8);
      big_col(9,0);
      big_col(9,8);
      big_col(9,4);
      big_col(9,0);
      big_col(9,8);
      big_col(8,0);
      big_col(8,8);
      big_col(8,4);
      big_col(8,0);
      big_col(8,8);
      big_col(7,0);
      big_col(7,8);
      big_col(7,4);
      big_col(7,0);
      big_col(7,8);
      big_col(6,0);
      big_col(6,8);
      big_col(6,4);
      big_col(6,0);
      big_col(6,8);
      big_col(5,0);
      big_col(5,8);
      big_col(5,4);
      big_col(5,0);
      big_col(5,8);
      big_col(4,0);
      big_col(4,8);
      big_col(4,4);
      big_col(4,0);
      big_col(4,8);
      big_col(3,0);
      big_col(3,8);
      big_col(3,4);
      big_col(3,0);
      big_col(3,8);
      big_col(2,0);
      big_col(2,8);
      big_col(2,4);
      big_col(2,0);
      big_col(2,8);
      big_col(1,0);
      big_col(1,8);
      big_col(1,4);
      big_col(1,0);
      big_col(1,8);

      big_row(16,0);
      big_row(16,8);
      big_row(16,4);
      big_row(16,0);
      big_row(16,8);
      big_row(15,0);
      big_row(15,8);
      big_row(15,4);
      big_row(15,0);
      big_row(15,8);
      big_row(14,0);
      big_row(14,8);
      big_row(14,4);
      big_row(14,0);
      big_row(14,8);
      big_row(13,0);
      big_row(13,8);
      big_row(13,4);
      big_row(13,0);
      big_row(13,8);
      big_row(12,0);
      big_row(12,8);
      big_row(12,4);
      big_row(12,0);
      big_row(12,8);
      big_row(11,0);
      big_row(11,8);
      big_row(11,4);
      big_row(11,0);
      big_row(11,8);
      big_row(10,0);
      big_row(10,8);
      big_row(10,4);
      big_row(10,0);
      big_row(10,8);
      big_row(9,0);
      big_row(9,8);
      big_row(9,4);
      big_row(9,0);
      big_row(9,8);
      big_row(8,0);
      big_row(8,8);
      big_row(8,4);
      big_row(8,0);
      big_row(8,8);
      big_row(7,0);
      big_row(7,8);
      big_row(7,4);
      big_row(7,0);
      big_row(7,8);
      big_row(6,0);
      big_row(6,8);
      big_row(6,4);
      big_row(6,0);
      big_row(6,8);
      big_row(5,0);
      big_row(5,8);
      big_row(5,4);
      big_row(5,0);
      big_row(5,8);
      big_row(4,0);
      big_row(4,8);
      big_row(4,4);
      big_row(4,0);
      big_row(4,8);
      big_row(3,0);
      big_row(3,8);
      big_row(3,4);
      big_row(3,0);
      big_row(3,8);
      big_row(2,0);
      big_row(2,8);
      big_row(2,4);
      big_row(2,0);
      big_row(2,8);
      big_row(1,0);
      big_row(1,8);
      big_row(1,4);
      big_row(1,0);
      big_row(1,8);
  }

  if(n==20)
  {
  	cout<<4280<<endl;
  	for(int i=1;i<=20;i++)
  	{
  		column(i,16);
  	    big_col(i,9);
  	    column(i,16);
  	    column(i,7);
  	    big_col(i,0);
  	    column(i,7);
  	    column(i,10);
  	    column(i,13);
  	    column(i,16);
  	}

  	for(int i=1;i<=20;i++)
  	{
  		row(i,16);
  	    big_row(i,9);
  	    row(i,16);
  	    row(i,7);
  	    big_row(i,0);
  	    row(i,7);
  	    row(i,10);
  	    row(i,13);
  	    row(i,16);
  	}
  }
  return 0;
}