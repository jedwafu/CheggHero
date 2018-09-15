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
 
int n,q;
ll p;
int arr[N];
ll tn1[4*N];
ll tn2[4*N];
ll tn3[4*N];
ll tn4[4*N];
int n1[1000010];
int n2[1000010];
int n3[1000010];
int n4[1000010];
 
ll MOD = (1LL << 20) - 1LL;
inline ll Mul(ll x, ll y) {
  if(p<=1e9)
    return x*y;

  ll x2 = (x & MOD);
  ll x1 = (x >> 20);
 
  ll y2 = (y & MOD);
  ll y1 = (y >> 20);
 
  ll ans = x1*y1;
  (ans *= MOD + 1) %= p;
  (ans *= MOD + 1) %= p;
 
  return (ans += (x2*y2 + (x1*y2 + x2*y1)*(MOD+1))) %= p;
}
 
 
 
 
void tfunc(int i,ll a,ll b)
{
    tn1[i]=(Mul(tn1[a],tn1[b])+Mul(tn2[a],tn2[b])+Mul(tn3[a],tn3[b])+Mul(tn4[a],tn4[b]));
    tn2[i]=abs(Mul(tn1[a],tn2[b])-Mul(tn2[a],tn1[b])+Mul(tn3[a],tn4[b])-Mul(tn4[a],tn3[b]));
    tn3[i]=abs(Mul(tn1[a],tn3[b])-Mul(tn2[a],tn4[b])-Mul(tn3[a],tn1[b])+Mul(tn4[a],tn2[b]));
    tn4[i]=abs(Mul(tn1[a],tn4[b])+Mul(tn2[a],tn3[b])-Mul(tn3[a],tn2[b])-Mul(tn4[a],tn1[b])); 
    
    if(p<=(int)1e9)
   { tn1[i]%=p;
    
    
    tn2[i]%=p;
   
    
    tn3[i]%=p;
    
    
    tn4[i]%=p; 
   }
}
 
void build(int cur,int l,int r)
{
  if(l == r)
  {
 
    tn1[cur]=n1[arr[l]];
    tn2[cur]=n2[arr[l]];
    tn3[cur]=n3[arr[l]];
    tn4[cur]=n4[arr[l]];
    return;
  }
 
  int c1 = cur<<1,c2 = c1|1,mid = l+r>>1;
  build(c1,l,mid);
  build(c2,mid+1,r);
  
  tfunc(cur,c1,c2);
  }
 
void update(int cur,int l,int r,int index,int val)
{
  if(l==r)
  {
    
 
    tn1[cur]=n1[val];
    tn2[cur]=n2[val];
    tn3[cur]=n3[val];
    tn4[cur]=n4[val]; 
    return;
  }
 
  int c1 = cur<<1,c2 = c1|1,mid = l+r>>1;
  if(index<=mid)
  update(c1,l,mid,index,val);
  else
  update(c2,mid+1,r,index,val);
 
 
  tfunc(cur,c1,c2);
 
}
 
vector<ll> query(int cur,int l,int r,int x,int y){
  
  vector<ll> ans(4);
  ans[0]=ans[1]=ans[2]=0;
  ans[3]=1;
  if(l > y || r < x)return ans;
  if(x <= l && r <= y){
   
    ans[0]=tn1[cur];
    ans[1]=tn2[cur];
    ans[2]=tn3[cur];
    ans[3]=tn4[cur];
    return ans;
  }
 
  int c1 = cur<<1,c2 = c1|1,mid = l+r>>1;
  vector<ll> ans1=query(c1,l,mid,x,y);
  vector<ll> ans2=query(c2,mid+1,r,x,y);
 
    ans[0]=(Mul(ans1[0],ans2[0])+Mul(ans1[1],ans2[1])+Mul(ans1[2],ans2[2])+Mul(ans1[3],ans2[3]));
    ans[1]=abs(Mul(ans1[0],ans2[1])-Mul(ans1[1],ans2[0])+Mul(ans1[2],ans2[3])-Mul(ans1[3],ans2[2]));
    ans[2]=abs(Mul(ans1[0],ans2[2])-Mul(ans1[1],ans2[3])-Mul(ans1[2],ans2[0])+Mul(ans1[3],ans2[1]));
    ans[3]=abs(Mul(ans1[0],ans2[3])+Mul(ans1[1],ans2[2])-Mul(ans1[2],ans2[1])-Mul(ans1[3],ans2[0])); 
 
    
    if(p<=(int)1e9)
  {  ans[0]%=p;
   
    
    ans[1]%=p;
   
    
    ans[2]%=p;
  
    ans[3]%=p;
  }
 
return ans;
}
 
void func(int i,int a,int b)
{
    n1[i]=((n1[a]*n1[b])+(n2[a]*n2[b])+(n3[a]*n3[b])+(n4[a]*n4[b]));
    n2[i]=abs((n1[a]*n2[b])-(n2[a]*n1[b])+(n3[a]*n4[b])-(n4[a]*n3[b]));
    n3[i]=abs((n1[a]*n3[b])-(n2[a]*n4[b])-(n3[a]*n1[b])+(n4[a]*n2[b]));
    n4[i]=abs((n1[a]*n4[b])+(n2[a]*n3[b])-(n3[a]*n2[b])-(n4[a]*n1[b])); 
}

int main()
{
    fast;
    int t;
    scanf("%d",&t);
 
    FOR(i,0,1000)
    {
      int lim=sqrt(1000000-i*i);
      FOR(j,0,lim)
      {
      n1[(i*i)+(j*j)]=n2[(i*i)+(j*j)]=0;
      n3[(i*i)+(j*j)]=i;
      n4[(i*i)+(j*j)]=j;
      }
    }
 
    FOR(i,3,1000000)
        {
            int root=sqrt(i);
            if(!n3[i] and !n4[i])
            {
                if(i%2==0)
                func(i,2,i/2);
                else
                for(int j=3;j<=root;j+=2)
                {
                    if(i%j==0)
                    {
                        func(i,j,i/j);
                        break;
                    }
                }
 
                if(!n1[i] and !n2[i] and !n3[i] and !n4[i])
                {
                    n1[i]=1;
                    FOR(j,1,root)
                    {
                        int k=(i-1)-(j*j);
                        if(!n1[k] and !n2[k])
                        {
                           // n1[i]=n1[k];
                            n2[i]=j;
                            n3[i]=n3[k];
                            n4[i]=n4[k];
                            break;
                        }
                    }
                }
            }
        }
 
   while(t--)
    {
        scanf("%d %d %lld",&n,&q,&p);
        FOR(i,0,n-1)
        scanf("%d",&arr[i]);
        build(1,0,n-1);
        FOR(i,1,q)
        {
            int type,a,b;
            scanf("%d %d %d",&type,&a,&b);
            if(type==1)
                update(1,0,n-1,a-1,b);
            if(type==2)
                {
                  vector<ll> ans=query(1,0,n-1,a-1,b-1);
                  printf("%lld %lld %lld %lld\n",ans[0],ans[1],ans[2],ans[3]);
                }
        }
 
    }
    return 0;
} 