/*  よろしくお願いします
    LEARNING DP:    Longest Path
        + SIMPLE GRAPH
        + DIRECTED EDGES
        + NO CYCLE
    CONSTRAINT:
        +2 <= N <= 1e5
        +1 <= M <= 1e5
    QUESTION:
        + can we START at RANDOM Vertex
        + what should we memorize after done a DFS or BFS
    IF WE KNOW:
        A PATH that already done by using DFS
        we can just add it to the current one.
    PRE DP:
        ALL PATH equal 0
    TIME COMPLEXITY:
        O(|N| + |M|)
*/
#include <bits/stdc++.h>
using namespace std;

#define DB(_x)      cout << #_x << " is " << (_x) << "\n";
#define FOR(_a,_b)  for (_a = 0; _a < _b; ++_a)
#define fs          first
#define sc          second
#define pb          push_back
//#define IOFILE

using LL = long long;
using LD = long double;
using VI = vector<int>;
using PI = pair<int,int>;

int DFS(VI &dp, vector<VI> &a, int u){
    if (dp[u]) return dp[u];
    int res = 0;
    for (auto v: a[u]){
        if(dp[v]){
            res = max(res, dp[v]);
        } else {
            res = max(res,DFS(dp,a,v));
        }
    }
    return dp[u] = res + 1;
}

void Excalibur(){
    int i=0, j=0, n ,m, ans;

    while (cin >> n >> m){

        vector<VI> a(n);
        FOR(i, m){
            int x, y; cin >> x >> y; --x; --y; a[x].pb(y);
        }

        VI dp(n,0);
        ans = 0;
        FOR(i, n){
            ans = max(ans,DFS(dp, a, i));
//            DB(dp[i]);
        }
        cout << ans - 1 << "\n";
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
