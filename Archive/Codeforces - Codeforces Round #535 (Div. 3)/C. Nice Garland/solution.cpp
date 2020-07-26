#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define endl "\n"
#define F first
#define rf(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
#define rb(i,b,a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) cout << (#x) << " = " << (x) << endl
#define test(t) int(testCnt) = 0; int(t); cin >> (t); while(t -- && ++testCnt)

const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;
const double PI = 3.14159265358979323846264;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    cin >> n;
    cin >> s;
    int ans = INF;
    string cur;
    int cnt = 0, pos = 0;
    cur = "GRB", cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != cur[i % 3])
            cnt ++;
    }
    if(ans > cnt) {
        ans = cnt;
        pos = 1;
    }

    cur = "GBR", cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != cur[i % 3])
            cnt ++;
    }
    if(ans > cnt) {
        ans = cnt;
        pos = 2;
    }

    cur = "BGR", cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != cur[i % 3])
            cnt ++;
    }
    if(ans > cnt) {
        ans = cnt;
        pos = 3;
    }

    cur = "BRG", cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != cur[i % 3])
            cnt ++;
    }
    if(ans > cnt) {
        ans = cnt;
        pos = 4;
    }

    cur = "RBG", cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != cur[i % 3])
            cnt ++;
    }
    if(ans > cnt) {
        ans = cnt;
        pos = 5;
    }

    cur = "RGB", cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != cur[i % 3]) {
            cnt ++;
        }
    }
    if(ans > cnt) {
        ans = cnt;
        pos = 6;
    }
    cout << ans << endl;
    if(pos == 1) {
        cur = "GRB";
        rf(i,0,n  - 1) {
            cout << cur[i % 3];
        }
    }
    if(pos == 2) {
        cur = "GBR";
        rf(i,0,n  - 1) {
            cout << cur[i % 3];
        }
    }
    if(pos == 3) {
        cur = "BGR";
        rf(i,0,n  - 1) {
            cout << cur[i % 3];
        }
    }
    if(pos == 4) {
        cur = "BRG";
        rf(i,0,n  - 1) {
            cout << cur[i % 3];
        }
    }
    if(pos == 5) {
        cur = "RBG";
        rf(i,0,n  - 1) {
            cout << cur[i % 3];
        }
    }
    if(pos == 6) {
        cur = "RGB";
        rf(i,0,n  - 1) {
            cout << cur[i % 3];
        }
    }
    return 0;
}