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

int mat[101][101];
int par[101];
int indeg[101];
int main()
{
	int n,start=0,sum1=0,sum2=0;
	cin>>n;
	loop(i,1,n)
	loop(j,1,n)
	mat[i][j]=0,par[j]=0,indeg[j]=0;
	
	loop(i,1,n)
	{
		int a,b,c;
		cin>>a>>b>>c;
		mat[a][b]=c;
		indeg[a]++;
		
	}
	
	loop(i,1,n)
	if(indeg[i]>0)
	{
		start=i;
		break;
	}
	
	int flag=1;
    while(flag)
    {
    	flag=0;
       loop(i,1,n)
	   {
	   	if(mat[start][i]>0) 
	   	{
		   sum1+=mat[start][i];
		   mat[start][i]=0;
	   	   start=i;
	   	   flag=1;
	   	   break;
		}
		
	   }
	   
	   if(flag==0)
	   {
	       loop(i,1,n)
		   {
		   	if(mat[i][start]>0)
		   	{
		   		sum2+=mat[i][start];
		   		mat[i][start]=0;
		   		start=i;
		   		flag=1;
		   		break;
			   }
		   }	
	   }
	}
	
	if(sum1<sum2)
	cout<<sum1;
	else
	cout<<sum2;
	return 0;
}
