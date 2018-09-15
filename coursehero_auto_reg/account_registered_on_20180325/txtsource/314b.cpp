#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <complex>
#include <sstream>
using namespace std;
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define SIZE(c) ((int)((c).size()))
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
#define ALL(v) (v).begin(), (v).end()
 
#define pb push_back
#define mp make_pair
#define st first
#define nd second

int N,M;
char S[1000],T[1000];
PII R[1000];


int main() {
    cin>>N>>M;
    cin>>S>>T;
    
    int SL = strlen(S), TL = strlen(T);
    REP(i,TL) {
        PII cur(0,i);
        REP(j,SL) {
            if (S[j] == T[cur.nd]) {
                ++cur.nd;
                if (cur.nd == TL) {
                    ++cur.st;
                    cur.nd = 0;
                }            
            }            
        }
        R[i] = cur;
    } 

    int result = 0;
    int cur = 0;
    REP(i,N) {
        result += R[cur].st;
        cur = R[cur].nd;    
    }
    printf("%d\n",result / M);
}    