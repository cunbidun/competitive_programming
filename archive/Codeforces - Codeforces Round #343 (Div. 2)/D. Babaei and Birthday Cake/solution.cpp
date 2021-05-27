#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define F first
#define S second
#define rf(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
#define rb(i,b,a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) cout << (#x) << " = " << (x) << endl
#define test(t) int(testCnt) = 0; int(t); cin >> (t); while(t -- && ++testCnt)

const double eps = 0.0000001;
const double PI = 3.14159265358979323846264;
const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n;
ll a[MAXA], b[MAXA], f[MAXA], sT[MAXA * 4];

void update(int i, int l, int r, int p, ll v) {
    if(p < l || p > r || l > r) return;
    if(l == r) {
        if(l == p) sT[i] = v;
        return;
    }
    ll m = (l + r) >> 1;
    update(i * 2, l, m, p, v);
    update(i * 2 + 1, m + 1, r, p, v);
    sT[i] = max(sT[i * 2], sT[i * 2 + 1]);
}

ll getMax(int i, int l, int r, int tarL, int tarR) {
    if(tarL > r || tarR < l || l > r) return 0;
    if(tarL <= l && r <= tarR) return sT[i];
    ll m = (l + r) >> 1;
    return max(getMax(i * 2, l, m, tarL, tarR), getMax(i * 2 + 1, m + 1, r, tarL, tarR));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout << fixed << setprecision(10);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    cin >> n;
    rf(i, 1, n) {
        ll r, h;
        cin >> r >> h;
        a[i] = r * r * h;
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    int uni = unique(b + 1, b + n + 1) - b - 1;
    double ans = 0;
    f[0] = 0;
    rf(i, 1, n) {
        int p = lower_bound(b + 1, b + uni + 1, a[i]) - b;
        //cout << p << endl;
        f[i] = max(f[i], a[i] + getMax(1, 0, n, 0, p - 1 ));
        //cout << f[i] << endl;

        ans = max(ans, 1.0 * f[i]);
        update(1, 0, n, p, f[i]);
    }
    cout << 1.0 * ans * PI;
    return 0;
}