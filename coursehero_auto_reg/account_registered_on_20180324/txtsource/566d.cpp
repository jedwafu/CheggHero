#include <bits/stdc++.h>
using namespace std;

#define INF 10000000

typedef long long ll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef map<string, int> msi;

#define all(x) x.begin(), x.end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define spresent(c,x) ((c).find(x) != (c).end())  // for set,map
#define present(c,x) (find(all(c),x) != (c).end())  // for vector
#define F first
#define S second
#define loop(i,a,b) for(int i=int(a);i<=int(b);++i)
#define nloop(i,a,b) for(int i= int(a);i>=int(b);--i)

vi belongs_to(200010); 
int next[200010];
void initialize_set(int _size) 
{ 
  belongs_to.resize(_size); 
  loop(i, 0, _size - 1) 
  belongs_to[i] = i,next[i]=i+1; 
}

int find_set(int i) 
{
return (belongs_to[i] == i) ? i : (belongs_to[i] = find_set(belongs_to[i])); 
}

void union_set(int i, int j) 
{
belongs_to[find_set(i)] = find_set(j); 
}

void union_set2(int i,int j)
{
	if(i>j) swap(i,j);
	for(int l=i+1;l<=j;)
	{
		union_set(l-1,l);
		int temp=next[l];
		next[l]=max(next[l],j);
		l=temp;
	}
}
bool same_set(int i, int j) { return find_set(i) == find_set(j); }


int main()
{
	int n,q;
	cin>>n>>q;
	
	initialize_set(n);
	
	loop(i,1,q)
	{
		int type,a,b;
		cin>>type>>a>>b;
		
		if(type==1)
		{
			union_set(a,b);
		}
		
		if(type==2)
		{
		    union_set2(a,b);
		}
		
		if(type==3)
		{
			if(same_set(a,b))
			cout<<"YES"<<endl;
			else
			cout<<"NO"<<endl;
		}
	}
	
	return 0;
	
}
