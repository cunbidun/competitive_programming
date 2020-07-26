#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

#define ll long long
#define pb push_back    
#define watch(x) cout << (#x) << " = " << (x) << endl

const int INF = 1e9 + 7;
const int MAXA = 5e4 + 10;
const int MOD = 1e9 + 7;
const int BL = 1500;

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, t;
int cnt[MAXA];
string S;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);

    cin >> t;
    
    while(t -- ){
        cin >> S;
        n = S.length();
        S = "@" + S;
        memset(cnt,0,sizeof(cnt));
        bool ok = 0;
        for(int i = 1; i <= n; i ++) {
            cnt[S[i] - 'a'] ++;
            if(i > 1 && S[i] != S[i-1]) ok = 1;
        }
        if(!ok) {
            cout << -1 << endl;
            continue;
        }
        for(int i = 0; i < 26; i ++) {
            while(cnt[i]) {
                cout << (char)('a' + i);
                cnt[i]--;
            }
        }
        cout << endl;
    }

    return 0;
}