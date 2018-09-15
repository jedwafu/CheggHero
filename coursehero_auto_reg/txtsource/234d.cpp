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

int mark[110],mini[110],maxi[110];
int n,m,k;
int fr[110];

int main(){
   	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    fill(mark,0);
    cin>>m>>k;
    int v,d;
    FOR(i,1,k)
    {
        cin>>v;
        mark[v]=1;   
    }

    cin>>n;
    string s;
    FOR(i,1,n){
        cin>>s;   
        cin>>d;
        int c=0,val=0;
        mini[i]=maxi[i]=0;
        fill(fr,1);
        FOR(j,1,d)
        {
            cin>>v;
            
            if(v!=0 && mark[v]) 
            	val++;
            else if(v==0) 
            	c++;
            
            fr[v]=0;
        }
        mini[i]=maxi[i]=val;
        int c1=0,c2=0;
        FOR(v,1,m) 
        if(fr[v])
        if(mark[v]) 
        	c2++;
        else 
        	c1++;

        if(c>c1) 
        mini[i]+=c-c1;
        maxi[i]+=min(c,c2);
    }

    FOR(i,1,n)
    {
        bool check=1;
        FOR(j,1,n) 
        if(j!=i && mini[i]<maxi[j]) 
        	check=0;
        if(check)
        {
            cout<<0<<endl;
            continue;
        }

        check=0;
        FOR(j,1,n) 
        if(j!=i && maxi[i]<mini[j]) 
        	check=1;
        if(check){
            cout<<1<<endl;
            continue;   
        }
        cout<<2<<endl;
    }
    
    return 0;
}