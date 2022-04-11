/*  よろしくお願いします
    LEARNING DP:    Grid 1
        + GRID HxW
        + MOVING RIGHT or DOWN to an ADJACENT EMPTY square
        + THE NUMBER OF PATH to move from (1,1) to (H,W) mod 1e9+7
    CONSTRAINT:
        +2 <= H, W <= 1000
    RECURSIVE:

    IF WE KNOW:

    PRE DP:

    TIME COMPLEXITY:
        O(N*M)
*/
#include <bits/stdc++.h>
using namespace std;

#define DB(_x)      cout << #_x << " is " << (_x) << "\n";
#define FOR(_a,_b)  for (_a = 0; _a < _b; ++_a)
#define fs          first
#define sc          second
#define pb          push_back
#define IOFILE

using LL = long long;
using LD = long double;
using VI = vector<int>;
using PI = pair<int,int>;

int i, j, n ,m, ans, mod = 1e9+7;
vector<VI> a, dp;

int DFS(int u, int v){
    if (dp[u][v] != -1) return dp[u][v];
    if (u == n-1 && v == m-1) return 1;
    int cnt = 0;
    if (v+1 < m && a[u][v+1]){
        cnt += DFS(u,v+1);
        cnt %= mod;
    }
    if (u+1 < n && a[u+1][v]){
        cnt += DFS(u+1,v);
        cnt %= mod;
    }
    return dp[u][v] = cnt;
}

void Excalibur(){
    while (cin >> n >> m){
        a = vector<VI>(n, VI(m));
        dp = vector<VI> (n, VI(m,-1));
        FOR(i, n) FOR (j, m){
            char x; cin >> x;
            a[i][j] = (x == '.');
        }
        cout << DFS(0,0) << "\n";
    }
}

int main(){
ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#ifdef  IOFILE
    freopen("INPUT.in", "r", stdin);
    freopen("OUTPUT.out", "w", stdout);
#endif

Excalibur();
return 0;}
