    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
     
    using namespace std;
    using namespace __gnu_pbds;
     
    #define INF 1000000007
    #define MAX 1000000
    typedef long long ll;
    typedef unsigned long long ull;
    typedef vector<int> vi;
    typedef vector<vector<int> > vvi;
    typedef pair<int,int> ii;
    typedef vector<pair<int,int> > vii;
    typedef vector<vector<pair<int,int> > > vvii;
     
     
    #define all(x) x.begin(), x.end()
    #define tr(x,it) for(auto it = x.begin();it!=x.end();++it)
    #define sz(a) int((a).size())
    #define pb push_back
    #define mp make_pair
    #define fpresent(c,x) ((c).find(x) != (c).end()) // set,map
    #define present(c,x) (find(all(c),x) != (c).end()) //vector
    #define F first
    #define S second
    #define FOR(i,a,b) for(int i=a;i<=b;++i)
    #define NFOR(i,a,b) for(int i=a;i>=b;--i)
    ll in[MAX],treee[MAX],lazy[3][MAX];
    ll add(ll a,ll b){
    ll temp=a+b;
    while(temp>=INF)temp-=INF;
    return temp;
    }
    ll mul(ll a,ll b){
    ll temp=(a*b)%INF;
    return temp;
     
    }
    void func(ll node,ll a,ll b){
    if(lazy[2][node]!=0){
    treee[node]=mul((b-a+1),lazy[2][node]);
    if(a!=b){
    lazy[2][2*node]=lazy[2][node];
    lazy[2][2*node+1]=lazy[2][node];
    lazy[0][2*node+1]=0;
    lazy[0][2*node]=0;
    lazy[1][2*node+1]=1;
    lazy[1][2*node]=1;
    }
    lazy[2][node]=0;
    }
    if(lazy[1][node]!=1||lazy[0][node]!=0){
    treee[node]=mul(lazy[1][node],treee[node]);
    treee[node]=add(((b-a+1)*lazy[0][node])%INF,treee[node]);
    if(a!=b){
    lazy[1][2*node]=mul(lazy[1][2*node],lazy[1][node]);
    lazy[1][2*node+1]=mul(lazy[1][2*node+1],lazy[1][node]);
    lazy[0][2*node]=mul(lazy[0][2*node],lazy[1][node]);
    lazy[0][2*node+1]=mul(lazy[0][2*node+1],lazy[1][node]);
    lazy[0][2*node]=add(lazy[0][2*node],lazy[0][node]);
    lazy[0][2*node+1]=add(lazy[0][2*node+1],lazy[0][node]);
    }
    lazy[1][node]=1;
    lazy[0][node]=0;
    }
    }	
    void build(ll node,ll i,ll j){
    if(i>j)return;
    if(i==j){
    treee[node]=in[i];
    return;
    }
     
    build(2*node,i,(i+j)/2);
    build(2*node+1,(i+j)/2+1,j);
     
    ll temp=treee[2*node]+treee[2*node+1];while(temp>=INF)temp-=INF;
    treee[node]=temp;
    }	
    void update1(ll node,ll a,ll b,ll i,ll j,ll value){
    func(node,a,b);
    if(a>b||a>j||b<i)return;
    if(a>=i&&b<=j){
    treee[node]=add(treee[node],((b-a+1)*value)%INF);
    if(a!=b){
     
    lazy[0][2*node]=add(lazy[0][2*node],value);
    lazy[0][2*node+1]=add(lazy[0][2*node+1],value);
    }
    return;
    }
    update1(node*2,a,(a+b)/2,i,j,value);
    update1(node*2+1,(a+b)/2+1,b,i,j,value);
    treee[node]=add(treee[2*node],treee[2*node+1]);
     
    }
     
    void update2(ll node,ll a,ll b,ll i,ll j,ll value){
    func(node,a,b);
    if(a>b||a>j||b<i)return;
    if(a>=i&&b<=j){
    treee[node]=mul(treee[node],value);
    if(a!=b){
     
    lazy[1][2*node]=mul(lazy[1][2*node],value);
    lazy[1][2*node+1]=mul(lazy[1][2*node+1],value);
    lazy[0][2*node]=mul(lazy[0][2*node],value);
    lazy[0][2*node+1]=mul(lazy[0][2*node+1],value);
     
    }
    return;
    }
    update2(node*2,a,(a+b)/2,i,j,value);
    update2(node*2+1,(a+b)/2+1,b,i,j,value);
    treee[node]=add(treee[2*node],treee[2*node+1]);
    }
    void update3(ll node,ll a,ll b,ll i,ll j,ll value){
    func(node,a,b);
    if(a>b||a>j||b<i)return;
    if(a>=i&&b<=j){
     
    treee[node]=mul((b-a+1),value);
    if(a!=b){
    lazy[2][2*node]=value;
    lazy[2][2*node+1]=value;
    lazy[0][2*node+1]=0;
    lazy[0][2*node]=0;
    lazy[1][2*node+1]=1;
    lazy[1][2*node]=1;
    }
    return;
    }
    update3(node*2,a,(a+b)/2,i,j,value);
    update3(node*2+1,(a+b)/2+1,b,i,j,value);
    treee[node]=add(treee[2*node],treee[2*node+1]);
    }
    ll query(ll node,ll a,ll b,ll i,ll j){
    func(node,a,b);
    if(a>b||a>j||b<i)return 0;
    if(a>=i&&b<=j)return treee[node];
    ll q1=query(node*2,a,(a+b)/2,i,j);
    ll q2=query(node*2+1,(a+b)/2+1,b,i,j);
    ll temp=q1+q2;while(temp>=INF)temp-=INF;
    return temp;
    }
    int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,q,a,b,c,val,ans;
    cin>>n>>q;
    FOR(i,1,n)cin>>in[i];
    memset(treee,0,sizeof(treee));
    build(1,1,n);
    FOR(i,0,MAX-1){lazy[0][i]=0;lazy[1][i]=1;lazy[2][i]=0;}
    while(q--){
    cin>>c;
    if(c==1){
    cin>>a>>b>>val;
    update1(1,1,n,a,b,val);continue;
    }
    if(c==2){
    cin>>a>>b>>val;
    update2(1,1,n,a,b,val);continue;
    }
    if(c==3){
    cin>>a>>b>>val;
    update3(1,1,n,a,b,val);continue;
    }
    if(c==4){
    cin>>a>>b;
    ans=query(1,1,n,a,b);
    cout<<ans<<"\n";continue;
    }
     
    }
    return 0;
    } 
