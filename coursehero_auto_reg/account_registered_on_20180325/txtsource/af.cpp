    #include <iostream>
    #include <cstdio>
    #include <cmath>
    #include <vector>
    #include <algorithm>
    #include <utility>
    #include <map>
    #include <queue>
    #include <stack>
    #include <set>
    #include <string>
    #include <cstring>
    #define rf freopen("in.in", "r", stdin)
    #define wf freopen("out.out", "w", stdout)
    #define rep(i, s, n) for(int i=int(s); i<=int(n); ++i)
    using namespace std;
    const int mx = 1e5+10, mod = 1e9+7;
     
    struct node
    {
    int af, mf, s, sum;
    } st[4*mx];
     
    static int a[mx];
    int n, q, qs, qe, v, ch;
     
    void build(int x, int y, int r)
    {
    if(x==y)
    {
    st[r].sum = a[x],
    st[r].af=0, st[r].mf=1, st[r].s=-1;
    return;
    }
     
    int m=(x+y)>>1;
    build(x, m, 2*r); 
	build(m+1, y, 2*r+1);
     
    st[r].sum = (st[2*r].sum+st[2*r+1].sum)%mod,
    st[r].af=0, st[r].mf=1, st[r].s=-1;
    }
    
	 
    void push(int p, int c, int x, int y)
    {
    if(st[p].s != -1)
    {
    st[c].af=st[p].af, st[c].mf=st[p].mf, st[c].s=st[p].s;
    st[c].sum = (1ll*(y-x+1)*st[c].s)%mod;
    st[c].sum = (1ll*st[c].sum*st[c].mf)%mod;
    st[c].sum = (st[c].sum+(1ll*(y-x+1)*st[p].af)%mod)%mod;
    }
    else
    {
    st[c].sum = (1ll*st[c].sum*st[p].mf)%mod;
    st[c].sum = (st[c].sum+(1ll*(y-x+1)*st[p].af)%mod)%mod;
     
    st[c].af = (1ll*st[c].af*st[p].mf)%mod;
    st[c].af = (st[c].af+st[p].af)%mod;
    st[c].mf = (1ll*st[c].mf*st[p].mf)%mod;
    }
    }
     
    void update(int x, int y, int r)
    {
    if(y<qs or qe<x)
    return;
     
    if(qs<=x and y<=qe)
    {
    if(ch == 3)
    {
    st[r].af=0, st[r].mf=1, st[r].s=v;
    st[r].sum = (1ll*(y-x+1)*st[r].s)%mod;
    }
    else if(ch == 2)
    {
    st[r].sum = (1ll*st[r].sum*v)%mod;
    st[r].af = (1ll*st[r].af*v)%mod;
    st[r].mf = (1ll*st[r].mf*v)%mod;
    }
    else
    {
    st[r].sum = (st[r].sum + (1ll*(y-x+1)*v)%mod)%mod;
    st[r].af = (st[r].af + v)%mod;
     
    }
    return;
    }
     
    int m = (x+y)>>1;
     
    push(r, 2*r, x, m); push(r, 2*r+1, m+1, y);
    st[r].af=0, st[r].mf=1, st[r].s=-1;
     
    update(x, m, 2*r), update(m+1, y, 2*r+1);
    st[r].sum = (st[2*r].sum+st[2*r+1].sum)%mod;
    }
     
    int query(int x, int y, int r)
    {
    if(y<qs or qe<x)
    return 0;
     
    if(qs<=x and y<=qe)
    return st[r].sum;
     
    int m = (x+y)>>1;
     
    push(r, 2*r, x, m); 
	push(r, 2*r+1, m+1, y);
    st[r].af=0, st[r].mf=1, st[r].s=-1;
    st[r].sum = (st[2*r].sum+st[2*r+1].sum)%mod;
     
    return (query(x, m, 2*r)+query(m+1, y, 2*r+1))%mod;
    }
     
    int main()
    {
    //rf;// wf;
     
    scanf("%d %d", &n, &q);
    rep(i, 1, n)
    scanf("%d", &a[i]);
    build(1, n, 1);
     
    while(q--)
    {
    scanf("%d %d %d", &ch, &qs, &qe);
    if(ch == 1 or ch == 2 or ch == 3)
    {
    scanf("%d", &v);
    update(1, n, 1);
    }
    else
    printf("%d\n", query(1, n, 1));
    }
    return 0;
    }
