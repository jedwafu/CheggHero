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

string str;


void app(int n,string s)
{
    FOR(i,0,n-1)
    FOR(j,0,sz(s)-1)
    str.pb(s[j]);
}

int main()
{
    fast;
    int a1,a2,a3,a4;
    cin>>a1>>a2>>a3>>a4;

    if(abs(a3-a4)>1) 
    cout<<"-1"<<endl;

    else if(a1<max(a3,a4)||a2<max(a3,a4)) 
    cout<<"-1"<<endl;

    else if(a3==a4+1)
    {
        app(a1-a3,"4");
        app(a3,"47");
        app(a2-a3,"7");
    }

    else if(a3==a4)
    {
        if(a1==a3 && a2==a3)
            cout<<"-1"<<endl;

        else if(a1!=a3)
        {
            app(a1-a3-1,"4");
            app(a3,"47");
            app(a2-a3,"7");
            app(1,"4");
        }
        else
        {
            app(1,"7");
            app(a3,"47");
            app(a2-a3-1,"7");
        }
    }
    else if(a3+1==a4)
    {
        app(1,"74");
        app(a1-a4,"4");
        app(a4-2,"74");
        app(a2-a4,"7");
        app(1,"74");
    }

    cout <<str<<endl;

    return 0;
}