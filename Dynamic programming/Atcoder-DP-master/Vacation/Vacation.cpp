/*
    LEARNING DP:    Vacation
        + Three types of activity
        + Chose one
        + No same activity on two or more consecutive days.
        + Maximum happiness

        => So the question are WHICH ACTIVITY? and WHICH DAY?
    IF WE KNOW: consider we are on the i-th day
        if we choose the first activity,
            so on the PREVIOUS DAY, obviously we chose the second or the third BECAUSE the condition.

        => If we know the answer on the PREVIOUS day, we can calculate the current day.
    PRE DP:
        day 1: act 1 = a1, act 2 = a2, act 3 = a3.
    TIME COMPLEXITY:
        O(N*3)

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
    int n, i, j;
    while (cin >> n){
        vector<VI> a(n,VI(3));
        FOR(i,n) FOR (j,3) cin >> a[i][j];

        vector<VI> dp(n, VI(3,0));
        dp[0][0] = a[0][0];
        dp[0][1] = a[0][1];
        dp[0][2] = a[0][2];
        FOR (i,n){
            if (i == 0) continue;
            FOR (j,3){
                dp[i][j] = max(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + a[i][j];
            }
        }

        cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << "\n";
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
