/*
    LEARNING DP:    FROG 2
        + Frog need to reach stone N
        + Can jump to Stone i + 1 or i + 2 when the Frog is on Stone i
        + Cost |hi - hj|
        => Imagine if the frog were at stone i + 1 or i + 2
        What is the minium cost to reach on Stone i.

        + DIFFERENT FROM FROG 1:
            + i + 1, i + 2, i + k
            => Image if the frog were at stone i + 1 or i + 2 ... i + k
            Or what if we've already known the minium cost at i - 1, i - 2 .. i - k.
            we now can calculate the solution for stone i
    PRE DP:
        +FIRST STATE: i = 0 => cost = 0
    TIME COMPLEXITY:
        + O(n * k)
*/
#include <bits/stdc++.h>
using namespace std;

#define DB(_x)      cout << #_x << " is " << (_x) << "\n";
#define FOR(_a,_b)  for (_a = 0; _a < _b; ++_a)
//#define IOFILE

using LL = long long;
using LD = long double;
using VI = vector<int>;
using PI = pair<int,int>;

void Excalibur(){
    int n, k;
    while (cin >> n >> k){
        VI a(n);
        for (auto &x: a) cin >> x;

        VI dp(n, 1e9);
        int i, j;
        dp[0] = 0;
        FOR (i,n){
            FOR (j, k+1){
                if (i-j >= 0) dp[i] = min(dp[i], dp[i-j] + abs(a[i] - a[i-j]));
            }
        }

        cout << dp[n-1] << "\n";
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
