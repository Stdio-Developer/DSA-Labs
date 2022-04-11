/*  よろしくお願いします
    LEARNING DP:    Digit Sum

    CONSTRAINT:

    WHAT WHE SHOULD CARE ABOUT:

    IF WE KNOW:
        digit dp
    PRE DP:

    TIME COMPLEXITY:

*/
#include <bits/stdc++.h>
using namespace std;

#define DB(_x)      cout << #_x << " is " << (_x) << "\n";
#define fs          first
#define sc          second
#define pb          push_back
//#define IOFILE

using LL = long long;
using LD = long double;
using VI = vector<int>;
using PI = pair<int,int>;
const int mod = 1e9 + 7;

// BEG: GLOBAL VARIABLES
    string s;
    int d;
    int dp[10001][101][2];
// END: GLOBAL VARIABLES

LL DFS(int idx, int su, int flag){
    if (idx == (int)s.size()) return su == 0;
    if (dp[idx][su][flag] != -1) return dp[idx][su][flag];
    LL cnt = 0, en;
    if (flag == 1) en = s[idx] - '0';
    else en = 9;
    for (int i=0; i<=en; ++i){
        int flagflag = flag;
        if (i < en) flagflag = 0;
        cnt += DFS(idx+1,(su+i)%d,flagflag);
        if (cnt >= mod) cnt %= mod;
    }
    return dp[idx][su][flag] = cnt;
}

void Excalibur(){
    while (cin >> s >> d){
        memset(dp,-1,sizeof(dp));
        cout << (DFS(0,0,1) - 1 + mod) % mod<< "\n";
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
