// Code for FFT taken from MIT ACM notebook.


#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<ll> VI;
typedef pair<int,int> ii;


 
#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const int mod = 359999;
const ll MOD =1e9+7;
const int N = 360010; 
 
ll arr[1010];
int sp[N];
int mb[N];
ll present[N];
int cnt[700][700];
ll d[N];
int num[700][700];
vector<ii> later;
int seven1[700];
int seven2[700];
int coeff[700][700];
VI res[1500];
VI final[1500];
double PI = acos(0) * 2;

class Complex
{
public:
  double a, b;
  Complex() {a = 0.0; b = 0.0;}
  Complex(double na, double nb) {a = na; b = nb;}
  const Complex operator+(const Complex &c) const
    {return Complex(a + c.a, b + c.b);}
  const Complex operator-(const Complex &c) const
    {return Complex(a - c.a, b - c.b);}
  const Complex operator*(const Complex &c) const
    {return Complex(a*c.a - b*c.b, a*c.b + b*c.a);}
  double magnitude() {return sqrt(a*a+b*b);}
  void print() {printf("(%.3f %.3f)\n", a, b);}
};

class FFT
{
public:
  vector<Complex> data;
  vector<Complex> roots;
  VI rev;
  int s, n;

  void setSize(int ns)
  {
    s = ns;
    n = (1 << s);
    int i, j;
    rev = VI(n);
    data = vector<Complex> (n);
    roots = vector<Complex> (n+1);
    for (i = 0; i < n; i++)
      for (j = 0; j < s; j++)
        if ((i & (1 << j)) != 0)
          rev[i] += (1 << (s-j-1));
    roots[0] = Complex(1, 0);
    Complex mult = Complex(cos(2*PI/n), sin(2*PI/n));
    for (i = 1; i <= n; i++)
      roots[i] = roots[i-1] * mult;
  }

  void bitReverse(vector<Complex> &array)
  {
    vector<Complex> temp(n);
    int i;
    for (i = 0; i < n; i++)
      temp[i] = array[rev[i]];
    for (i = 0; i < n; i++)
      array[i] = temp[i];
  }

  void transform(bool inverse = false)
  {
    bitReverse(data);
    int i, j, k;
    for (i = 1; i <= s; i++) {
      int m = (1 << i), md2 = m / 2;
      int start = 0, increment = (1 << (s-i));
      if (inverse) {
        start = n;
        increment *= -1;
      }
      Complex t, u;
      for (k = 0; k < n; k += m) {
        int index = start;
        for (j = k; j < md2+k; j++) {
          t = roots[index] * data[j+md2];
          index += increment;
          data[j+md2] = data[j] - t;
          data[j] = data[j] + t;
        }
      }
    }
    if (inverse)
      for (i = 0; i < n; i++) {
        data[i].a /= n;
        data[i].b /= n;
      }
  }

  static VI convolution(VI &a, VI &b)
  {
    int alen = a.size(), blen = b.size();
    int resn = alen + blen - 1; // size of the resulting array
    int s = 0, i;
    while ((1 << s) < resn) s++;  // n = 2^s
    int n = 1 << s; // round up the the nearest power of two

    FFT pga, pgb;
    pga.setSize(s); // fill and transform first array
    for (i = 0; i < alen; i++) pga.data[i] = Complex(a[i], 0);
    for (i = alen; i < n; i++)  pga.data[i] = Complex(0, 0);
    pga.transform();

    pgb.setSize(s); // fill and transform second array
    for (i = 0; i < blen; i++)  pgb.data[i] = Complex(b[i], 0);
    for (i = blen; i < n; i++)  pgb.data[i] = Complex(0, 0);
    pgb.transform();

    for (i = 0; i < n; i++) pga.data[i] = pga.data[i] * pgb.data[i];
    pga.transform(true);  // inverse transform
    VI result = VI (resn);  // round to nearest integer
    for (i = 0; i < resn; i++)  result[i] = (int) (pga.data[i].a + 0.5);

   // int actualSize = resn - 1;  // find proper size of array
  //  while (result[actualSize] == 0)
  //    actualSize--;
   // if (actualSize < 0) actualSize = 0;
   // result.resize(actualSize+1);
    return result;
  }
};


 
void sieve()
{
  int root=sqrt(N);
  for(int i=2;i<=N;i+=2)
    sp[i]=2;
 
  for(int i=3;i<=N;i+=2)
  {
    if(!sp[i])
      sp[i]=i;
 
    if(i<=root)
    {
      for(int j=i*i;j<=N;j+=2*i)
        if(!sp[j])
          sp[j]=i;
    }
  }
}
 
void mobius()
{
  FOR(i,2,N)
  {
    if(sp[i/sp[i]]==sp[i])
      mb[i]=0;
    else
    mb[i]=(-1)*mb[i/sp[i]]; 
    
  }
}
 
void calc(int n)
{
  d[1]=n*n;
  FOR(i,2,N)
  {
    d[i]=0;
    for(int j=0;j*i<=N;j++)
      d[i]+=present[i*j];
  }
}
 
ll choose(ll n,ll k)
{ 
  ll temp=0;
  ll zero=present[0];
  if(k==3)
  temp=(n*(n-1)*(n-2)-(zero*(zero-1)*(zero-2)))%MOD;
    if(k==2)
    temp=((n*(n-1)-(zero*(zero-1)))*3)%MOD;
    
    return temp;
}
 
int main(){
  fast;
  int t;
  cin>>t;
  fill(sp,0);
  sieve();
  mb[1]=1;
  mobius();

  int temp=1;
  FOR(i,0,597)
  {
    seven1[temp]=i;
    temp=(temp*7)%599;
    //if(i<10)
    //cout<<temp<<endl;
  }

  temp=1;
  FOR(i,0,599)
  {
    seven2[temp]=i;
    temp=(temp*7)%601;
  }

  FOR(i,1,359998)
  {
    int r1=i%599;
    int r2=i%601;
    if(r1 and r2)
      num[seven1[r1]][seven2[r2]]=i;
  }

  

  while(t--)
  {
  int n;
  fill(cnt,0);
  fill(present,0);
  later.clear();
  cin>>n;

  FOR(i,0,n-1)
  {
    cin>>arr[i];
    int r1=arr[i]%599;
    int r2=arr[i]%601;
    //cout<<r1<<" "<<r2<<endl;
    //cout<<seven1[r1]<<" "<<seven2[r2]<<endl;
    if(r1 and r2)
      cnt[seven1[r1]][seven2[r2]]++;

    else later.pb(mp(r1,r2));
  }

  
  FOR(i,0,597)
  FOR(j,0,599)
  coeff[i][j]=cnt[i][j];
  
  
  VI a;
  FOR(i,0,597)
  {
    a.clear();
    FOR(j,0,599)
    a.pb(coeff[i][j]);

    res[i]=FFT::convolution(a,a);
   // cout<<sz(res)<<endl;
  }

  FOR(i,0,1198)
  {
    a.clear();
    FOR(j,0,597)
    a.pb(res[j][i]);

    final[i]=FFT::convolution(a,a); 

    //cout<<i<<endl;
  }

  FOR(i,0,1198)
  FOR(j,0,1196)
  {
    if(final[i][j])
      cout<<i<<" "<<j<<" "<<final[i][j]<<endl;
  }
  /*VI b = FFT::convolution(coeff, coeff);
  FOR(i,0,sz(b)-1)
  {
   // cout<<b[i]<<" ";
    if(b[i])
      {
        cout<<i<<endl;
        int temp=i%rem;
        cout<<num[(((temp)/600))][(temp)%600]<<" "<<b[i]<<endl;
      }
  }*/

  /*calc(n); 
  ll sum=0;
  FOR(i,1,N)
  {
    sum=(sum+(mb[i]*choose(d[i],3)))%MOD;
    sum=(sum+(mb[i]*choose(d[i],2)))%MOD;
  }
 
  sum=(sum+present[1])%MOD;
  
  if(sum<0)
    sum+=MOD;
  
  cout<<sum<<endl;
 */
  }
  
  return 0;
} 