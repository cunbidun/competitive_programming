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

const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<ll, ll> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n;
ll T, t[MAXA], mxT, cur, l[MAXA], f[MAXA], m1[MAXA], m2[MAXA], ans[MAXA], x[MAXA];
ii sT[45 * MAXA];
vi adj[MAXA];

void update(int id, int l, int r, ll pos, ll val) {
    if(pos > r || pos < l || l > r) return;
    if(l == r) {
        if(l == pos) {
          //  cout << l <<endl;
            sT[id].F += 1LL * val * pos;
            sT[id].S += 1LL * val;
        }
        return;
    }
    int m = (l + r) >> 1;
    update(id * 2, l, m, pos, val);
    update(id * 2 + 1, m + 1, r, pos, val);
    sT[id].F = sT[id * 2].F + sT[id * 2 + 1].F;
    sT[id].S = sT[id * 2].S + sT[id * 2 + 1].S;
}

ll getSum(int id, int l, int r, ll val) {
    if(l > r || val <= 0) return 1LL * 0;
    if(sT[id].F <= val) return sT[id].S;
    if(l == r) {
        if (!sT[id].S) return 1LL * 0;
        ll temp = sT[id].F / sT[id].S;
        return (ll)(val / temp);
    }
    int m = (l + r) >> 1;
    return getSum(id * 2, l, m, val) + getSum(id * 2 + 1, m + 1, r, max(val - sT[id * 2].F, 1LL * 0));
}

void dfsCal(int u) {
    update(1, 1, mxT, t[u], x[u]);
    //cout << u << " " << cur <<endl;
    f[u] = getSum(1, 1, mxT, T - cur);
    rf(i, 0, (int)adj[u].size() - 1) {
        int v = adj[u][i];
        cur += l[v] * 1LL * 2;
        dfsCal(v);
        cur -= l[v] * 1LL * 2;
    }
    update(1, 1, mxT, t[u], -x[u]);
}

void sol(int u) {
    if((int)adj[u].size() == 0) {ans[u] = f[u]; return;}
    if((int)adj[u].size() == 1 && u != 1) {ans[u] = f[u]; return;}
    rf(i, 0, (int)adj[u].size() - 1) {
        int v = adj[u][i];
        sol(v);
        if(ans[v] >= m1[u]) m2[u] = m1[u], m1[u] = ans[v];
        else if(ans[v] > m2[u]) m2[u] = ans[v];
    }
    ans[u] = max(f[u], m2[u]);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    cin >> n >> T;
    rf(i, 1, n) cin >> x[i];
    rf(i, 1, n) cin >> t[i], mxT = max(mxT, t[i]);
    rf(i, 2, n) {
        int par;
        cin >> par >> l[i];
        adj[par].pb(i);
    }
    cur = 0;
    dfsCal(1);
    sol(1);
    cout << max(m1[1], ans[1]);
    return 0;
}