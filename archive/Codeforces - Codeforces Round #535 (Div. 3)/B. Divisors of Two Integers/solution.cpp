#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define endl "\n"
#define F first
#define S second
#define rf(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
#define rb(i,b,a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) cout << (#x) << " = " << (x) << endl
#define test(t) int(testCnt) = 0; int(t); cin >> (t); while(t -- && ++testCnt)

const int INF = 2e9 + 7;
const int MAXA = 123 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;
const double PI = 3.14159265358979323846264;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

ll a[MAXA];
int n;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    cin >> n;
    rf(i,1,n) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ll mx = -1;
    rf(i,1,n) {
        if(a[n] % a[i] != 0) {
            mx = max(mx, a[i]);
        }
    }
    if(mx == -1) {
        rf(i,1,n) {
            if(a[i] == a[i - 1]) {
                mx = max(mx, a[i]);
            }
        }
    }
    cout << a[n] << " " << mx << endl;
    return 0;
}