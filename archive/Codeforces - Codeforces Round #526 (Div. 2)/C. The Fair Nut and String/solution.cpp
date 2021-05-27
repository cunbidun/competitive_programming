#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

#define ll long long
#define pb push_back    
#define watch(x) cout << (#x) << " = " << (x) << endl

const int INF = 1e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;
const int BL = 1500;

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, a[MAXA];
string S;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin >> S;
    n = S.length();
    S = '*' + S;
    int cur = 1;
    for(int i = 1; i <= n; i++) {
        if(S[i] == 'a') a[cur] ++;
        if(S[i] == 'b') cur++;
    }
    ll ans = 1;
    for(int i = 1; i <= cur; i++) {
        ans = (ans * (a[i] + 1)) % MOD;
    }
    cout << (ans + MOD - 1) % MOD;
    return 0;
}