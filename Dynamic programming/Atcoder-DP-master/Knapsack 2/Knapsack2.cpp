/*
    LEARNING DP:    Knapsack 2
        + CHOSE some of the N items have VALUES
        + THE CAPACITY of the knapsack is W.
        + MAXIMUM VALUES.
    CONSTRAINT:
        + 1 <= N <= 100
        + 1 <= WEIGHT <= 1000,000,000 // DIF
        + 1 <= VALUE <= 10^3 * N // DIF
    QUESTION:
        WHICH WEIGHT? and WHICH ITEMS?
    IF WE KNOW:
        if we know the knapsack 1, so now the WEIGHT become the VALUE
    PRE DP:

    TIME COMPLEXITY:
        O(N*MAX(VALUE)*N)
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
    LL limit = 1e5+1;
    LL limitW = 1e12;
    while (cin >> n >> w){
        vector<PI> a(n);
        for (auto &x: a) cin >> x.fs >> x.sc;
        vector<LL> dp(limit,limitW);
        dp[0] = 0;
        FOR (i, n){
            for (j=limit-1; j>=0; --j){
                if (j-a[i].sc >= 0 && dp[j-a[i].sc] != limitW){
                    if (dp[j-a[i].sc] + a[i].fs <= w){
                        dp[j] = min(dp[j],dp[j-a[i].sc] + a[i].fs);
                    }
                }
            }
        }

        LL ans = 0;
        for (int i=0; i<limit; ++i){
            if (dp[i] <= w) ans = max(ans,1LL*i);
        }
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
