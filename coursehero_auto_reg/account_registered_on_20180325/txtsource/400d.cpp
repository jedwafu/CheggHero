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

int c[501], g[501][501], used[100000];
int n, m, k;

vi x[N], r[N];

int func(int x) {
    int l = 0;
    int r = k;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (c[m] < x) l = m;
        else r = m;
    }
    if (c[l] < x) return l + 1;
    else return r + 1;
}

void dfs(int v, int q) {
    used[v] = q;
    for (int i = 0; i < sz(r[v]); i++) {
        int temp = r[v][i];
        if (used[temp] == 0 && x[v][i] == 0) dfs(temp, q);
    }
}

int main () {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> c[i];
        if (i != 1) c[i] += c[i - 1];
    }
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            g[i][j] = -1;
        }
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        r[a].pb(b);
        x[a].pb(c);
        r[b].pb(a);
        x[b].pb(c);
        a = func(a);
        b = func(b);
        if (g[a][b] == -1 || c < g[a][b]) g[a][b] = c;
        if (g[b][a] == -1 || c < g[b][a]) g[b][a] = c;
    }
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) dfs(i, i);
    }
    for (int i = 1; i <= n; ++i) {
        int x = func(i);
        g[x][x] = 0;
        if (used[c[x]] != used[i]) 
        {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes"<<endl;
    for (int l = 1; l <= k; ++l) {
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (g[i][l] != -1 && g[l][j] != -1 && (g[i][j] == -1 || g[i][j] > g[i][l] + g[l][j])) g[i][j] = g[i][l] + g[l][j];
            }
        }
    }
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            cout << g[i][j] << " ";
        }
        cout <<endl;
    }
}