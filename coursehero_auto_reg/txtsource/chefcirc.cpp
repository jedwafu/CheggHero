#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
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
const ll mod = 1e9+7;
const int N = 1e5+10; 

//Functions for geometry taken from the standform ACM notebook
int m,n;

struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

vector<PT> points;
vector<pair<double,bool> > intersect;

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }

PT RotateCCW90(PT p)   { return PT(-p.y,p.x); }
PT RotateCW90(PT p)    { return PT(p.y,-p.x); }
PT RotateCCW(PT p, double t) { 
  return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t)); 
}

vector<PT> CircleCircleIntersection(PT a, PT b, double r, double R) {
  vector<PT> ret;
  double d = sqrt(dist2(a, b));
  if (d > r+R || d+min(r, R) < max(r, R)) return ret;
  double x = (d*d-R*R+r*r)/(2*d);
  double y = sqrt(r*r-x*x);
  PT v = (b-a)/d;
  ret.push_back(a+v*x + RotateCCW90(v)*y);
  if (y > 0)
    ret.push_back(a+v*x - RotateCCW90(v)*y);
  return ret;
}

vector<double> arr;
bool check(double radius)
{
    int maxi=0;
	FOR(i,0,n-1)
	{
		intersect.clear();
		int cur=1;
		FOR(j,0,n-1)
		{
			if(j==i)
				continue;

			vector<PT> temp= CircleCircleIntersection(points[i],points[j],radius,radius);
			// cout<<points[i].x<<" "<<points[i].y<<" "<<points[j].x<<" "<<points[j].y<<" "<<endl;

			if(sz(temp)==2)
			{
				double x2=(temp[0].x-points[i].x);
				double y2=(temp[0].y-points[i].y);
				double x1=radius;
				double y1=0;
				double angle0=atan2(x1*y2-y1*x2,x1*x2+y1*y2);
				if(angle0<0)
					angle0+=(double)360;
				 x2=(temp[1].x-points[i].x);
				 y2=(temp[1].y-points[i].y);
				double angle1=atan2(x1*y2-y1*x2,x1*x2+y1*y2);
				if(angle1<0)
					angle1+=(double)360;

				//cout<<angle0<<" "<<angle1<<" ";
				if(angle0>angle1)
					swap(angle0,angle1);
				
				     x2=(points[j].x-points[i].x);
				     y2=(points[j].y-points[i].y);
				    double anglec=atan2(x1*y2-y1*x2,x1*x2+y1*y2);
				    if(anglec<0)
				    	anglec+=(double)360;
				  //  cout<<anglec<<endl;
				    if(anglec>=angle0 and anglec<=angle1)
				    {
				    	intersect.pb(mp(angle0,0));
				    	intersect.pb(mp(angle1,1));
				    }
				    else
				    {
				    	cur++;
				    	intersect.pb(mp(angle0,1));
				    }
				
			}
			if(sz(temp)==1)
			{
				double x2=(temp[0].x-points[i].x);
				double y2=(temp[0].y-points[i].y);
				double x1=radius;
				double y1=0;
				double angle0=atan2(x1*y2-y1*x2,x1*x2+y1*y2);
				if(angle0<0)
					angle0+=(double)360;
				intersect.pb(mp(angle0,0));
				intersect.pb(mp(angle0,1));
			}			
		}
		sort(intersect.begin(),intersect.end());
        
        FOR(j,0,sz(intersect)-1)
        {
        	//cout<<cur<<endl;
        	if(j>0 and intersect[j-1].S==1)
        		cur--;

        	if(intersect[j].S==0)
        		cur++;

        	maxi=max(cur,maxi);
        }
	}
	if(maxi>=m)
	return true;
	else return false; 
}

int main(){
  fast;
  scanf("%d %d",&n,&m);
  if(m==1)
  {
  	cout<<(double)0<<endl;
  	return 0;
  }

  FOR(i,1,n)
  {
     double a,b;
     scanf("%lf %lf",&a,&b);
     points.pb(PT(a,b));
  }
  //cout<<setprecision(12);
  int l=1;
  int r=1500;
  while(r-l>1)
  {
  	int mid=(l+r)/2;
  	if(check((double)mid))
  	r=mid;
  	else
  	l=mid;
  }
  //cout<<check(1.24)<<endl;
  if(check(l))
  {
  	double epsilon=0.01;
  	double rad=(double)(l-1);
    while(rad<=(double)(l)+0.0001)
    {
      arr.pb(rad);
      rad+=epsilon;
    }
  	
  	int lt=0,rt=sz(arr)-1;
  	while(rt-lt>1)
  	{
  		int mid=(lt+rt)/2;
  		if(check(arr[mid]))
  			rt=mid;
  		else 
  			lt=mid;
  	}

  	if(check(arr[lt]))
  		printf("%lf",arr[lt]);
  	else 
  		printf("%lf",arr[rt]);
 
  	return 0;
  }

  if(check(r))
  {
  	double epsilon=0.01;
  	double rad=(double)(r-1);
    while(rad<=(double)(r)+0.0001)
    {
      arr.pb(rad);
      rad+=epsilon;
    }
  	
  	int lt=0,rt=sz(arr)-1;
  	while(rt-lt>1)
  	{
  		int mid=(lt+rt)/2;
  		if(check(arr[mid]))
  			rt=mid;
  		else 
  			lt=mid;
  	}

  	if(check(arr[lt]))
  		printf("%lf",arr[lt]);
  	else 
  		printf("%lf",arr[rt]);
 
  	return 0;
  }
 
  return 0;
}