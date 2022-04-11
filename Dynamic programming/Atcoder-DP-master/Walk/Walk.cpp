/*  よろしくお願いします
    LEARNING DP:    Walk
        I LEARN THIS FROM SCHOOL
    CONSTRAINT:

    WHAT WHE SHOULD CARE ABOUT:

    IF WE KNOW:

    PRE DP:

    TIME COMPLEXITY:
        O(N^3*LOG(K))
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
    LL n, k;
    LL b[51][51], a[51][51], ans;
// END: GLOBAL VARIABLES

void MUL(LL a[][51], LL b[][51]){
    LL c[51][51];
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            c[i][j] = 0;
            for (int k=0; k<n; ++k){
                c[i][j] += a[i][k] * b[k][j] % mod;
                if (c[i][j] > mod) c[i][j] %= mod;
            }
        }
    }
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            a[i][j] = c[i][j];
        }
    }
}

void BE(){
    while (k){
        if (k&1) MUL(b,a);
        MUL(a,a);
        k >>= 1;
    }
}

void Excalibur(){
    while (cin >> n >> k){
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j){
                cin >> a[i][j];
                b[i][j] = i == j;
            }

        BE();

        ans = 0;
        for (int i=0; i<n; ++i){
            for (int j=0; j<n; ++j){
                ans += b[i][j];
                if (ans >= mod) ans %= mod;
            }
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
