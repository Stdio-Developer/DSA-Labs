/*  よろしくお願いします
    LEARNING DP:    LCS
        + SUBSEQUENCE
        + LONGEST
    CONSTRAINT:
        +1 <= |S|, |T| <= 3000
    QUESTION:
        +WHICH INDEX i
        +WHICH INDEX j
        +TRACKING:
            +we go on the way where dp increasing
            because there is a way we add more charecter
    IF WE KNOW:
        THE LENGTH OF THE PREVIOUS SUBSEQUENCE we chose:
        we can try to add more character to get longer.
    PRE DP:
        ALL equal 0;
    TIME COMPLEXITY:
        O(|S|*|T|)
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

void Excalibur(){
    string s, t, ans;
    int i, j, n ,m;

    while (cin >> s >> t){
        vector<VI> dp(3001,VI(3001,0));
        n = s.size(); m = t.size();
        FOR (i, n+1){
            FOR (j, m+1){
                if (i == 0 || j == 0) continue;
                dp[i][j] = max(dp[i-1][j-1] + (s[i-1] == t[j-1]), dp[i][j]);
                dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i][j-1]});
            }
        }
        i = n; j = m; ans = "";
        while (i > 0 && j > 0){
            if (s[i-1] == t[j-1]){
                ans = s[i-1] + ans;
                --i;
                --j;
            } else if (dp[i-1][j] > dp[i][j-1]) --i;
            else --j;
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
