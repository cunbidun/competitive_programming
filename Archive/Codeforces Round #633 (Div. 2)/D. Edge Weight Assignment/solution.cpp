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

int n, p;
vi a[N];
int lvl[N];
int ch(int u, int l) {
    for (int v : a[u])
        if (v != l) {
            lvl[v] = lvl[u] + 1;
            ch(v, u);
        }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    rf(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    rf(i, 1, n) if (sz(a[i]) == 1) {
        p = i;
        break;
    }
    ch(p, p);
    int mn = 1;
    rf(i, 1, n) {
        if (sz(a[i]) == 1 && lvl[i] % 2 == 1) {
            mn = 3;
            break;
        }
    }
    set<int> used;
    int mx = n - 1;
    rf(i, 1, n) if (sz(a[i]) == 1) {
        if (used.find(a[i][0]) != used.end())
            mx--;
        else
            used.insert(a[i][0]);
    }
    cout << mn << " " << mx << "\n";
}