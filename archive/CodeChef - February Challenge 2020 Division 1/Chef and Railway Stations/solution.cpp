#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int N = 1e5 + 1;
const int INF = 2e9;

vi lp;
vi pr;
void sieve() {
    lp.assign(N, 0);
    for (int i = 2; i < N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

vi l[N + 5];
void cal(int i) {
    for (int j = 1; i * j * j <= N; j++) {
        l[i].pb(i * j * j);
    }
}

int check(int x) {
    while (x != 1) {
        if (lp[x] == lp[x / lp[x]])
            return 0;
        x /= lp[x];
    }
    return 1;
}

int get(int x) {
    int res = 1;
    while (x != 1) {
        int cur = lp[x];
        int cnt = 0;
        while (cur == lp[x]) {
            cnt++;
            x /= lp[x];
        }
        if (cnt % 2 == 1)
            res *= cur;
    }
    return res;
}
int root2(ll i) {
    int x = sqrt(i);
    if (1LL * x * x < i)
        x++;
    if (1LL * x * x > i)
        x--;
    return x;
}
void solve() {
    int n, m;
    cin >> n >> m;
    set<int> xP, xN, yP, yN;
    bool h0 = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x > 0)
            xP.insert(x);
        else if (x < 0)
            xN.insert(-x);
        else
            h0 = 1;
    }
    for (int i = 1; i <= m; i++) {
        int y;
        cin >> y;
        if (y > 0)
            yP.insert(y);
        else if (y < 0)
            yN.insert(-y);
        else
            h0 = 1;
    }
    ll ans = ((h0) ? (1LL * (sz(yP) + sz(yN)) * (sz(xN) + sz(xP))) : 0);

    for (int i : xN) {
        int p = get(i);
        for (int j : l[p])
            if (xP.find(j) != xP.end()) {
                if (yP.find(root2(1LL * i * j)) != yP.end())
                    ans++;
                if (yN.find(root2(1LL * i * j)) != yN.end())
                    ans++;
            }
    }

    for (int i : yN) {
        int p = get(i);
        for (int j : l[p])
            if (yP.find(j) != yP.end()) {
                if (xP.find(root2(1LL * i * j)) != xP.end())
                    ans++;
                if (xN.find(root2(1LL * i * j)) != xN.end())
                    ans++;
            }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    rf(i, 1, 1e5) if (check(i)) cal(i);
    int t;
    cin >> t;
    while (t--)
        solve();
}