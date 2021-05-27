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

vi l;
map<int, int> mp;
void compress() {
    sort(all(l));
    l.resize(distance(l.begin(), unique(all(l))));
    for (int i : l) {
        mp[i] = sz(mp) + 1;
    }
}

int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
void solve() {
    int n;
    cin >> n;
    vi a(n + 1);
    rf(i, 1, n) cin >> a[i];
    set<int> ans;
    vi res;
    rf(i, 1, n) {
        int d= 0;
        rf(j, 0, 10) if (a[i] % p[j] == 0) {
            ans.insert(j + 1);
            l.pb(j + 1);
            res.pb(j + 1);
            d  =1;
            break;
        }
        if(d == 0) cout << a[i] << "\n";
    }
    cout << sz(ans) << "\n";
    compress();

    for (int i : res)
        cout << mp[i] << " ";
    cout << "\n";
    mp.clear();
    l.clear();
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}