/*
    LEARNING DP:    Knapsack 1
        + CHOSE some of the N items have VALUES
        + THE CAPACITY of the knapsack is W.
        + MAXIMUM VALUES.
    CONSTRAINT:
        + 1 <= N <= 100
        + 1 <= WEIGHT <= 100,000
        + 1 <= VALUE <= 10^9 * N
    QUESTION:
        WHICH WEIGHT? and WHICH ITEMS?
    IF WE KNOW:
        so if we know if it is exist a WEIGHT x = VALUES at x
        we will loop all N items and find the answer for
        WEIGHT at x + Wi = max(VALUES at x + Vi, VALUES at x + Wi)

        NOTICE: we have to go from heighest WEIGHT to lowest WEIGHT i think
        this is a trick in DP
    PRE DP:
        ALL WEIGHT are -1e11;
        WEIGHT at 0 = 0;
    TIME COMPLEXITY:
        O(N*W)
*/
#include <bits/stdc++.h>
using namespace std;

#define DB(_x)      cout << #_x << " is " << (_x) << "\n";
#define FOR(_a,_b)  for (_a = 0; _a < _b; ++_a)
#define fs          first
#define sc          second
//#define IOFILE

using LL = long long;
using LD = long double;
using VI = vector<int>;
using PI = pair<int,int>;

void Excalibur(){
    int n, w, i, j;
    LL limit = -1e11;
    while (cin >> n >> w){
        vector<PI> a(n);
        for (auto &x: a) cin >> x.fs >> x.sc;
        vector<LL> dp(w+1,limit);
        dp[0] = 0;
        FOR (i, n){
            for (j=w; j>=0; --j){
                if (j-a[i].fs >= 0 && dp[j-a[i].fs] != limit){
                    dp[j] = max(dp[j], dp[j-a[i].fs] + a[i].sc);
                }
            }
        }

        LL ans = 0;
        for (auto x: dp) ans = max(x,ans);
        cout << ans << "\n";
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
