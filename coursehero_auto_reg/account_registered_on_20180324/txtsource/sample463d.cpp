    #include <iostream>
    #include <cstdio>
     
    using namespace std;
    const int NMAX = 1004;
    const int KMAX = 6;
    int a[KMAX][NMAX], pos[KMAX][NMAX] , dp[NMAX];
    int main(){
    
    int n, k,sol = 0;
    cin >> n >> k;
    for(int i = 1;i <= k; ++i)
    for(int j = 1;j <= n; ++j)
    {
    cin >> a[i][j];
    pos[i][a[i][j]] = j;
    }
    for(int j = 1;j <= n; ++j)
    {
    int maxx = 0;
    for(int p = 1;p < j; ++p){
    int i;
    for(i = 2;i <= k && pos[i][a[1][p]] < pos[i][a[1][j]];++i);
    if(i==k+1 && dp[p] > maxx)
    maxx = dp[p];
    }
    
    dp[j] = maxx+1;
    sol = max(sol,dp[j]);
    }
    cout<<sol<<"\n";
    return 0;
    }
