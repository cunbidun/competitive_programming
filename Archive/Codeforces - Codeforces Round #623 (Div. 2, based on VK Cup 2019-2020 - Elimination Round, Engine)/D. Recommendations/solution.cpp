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
 
const int N = 2e5 + 1;
const int INF = 2e9;
 
int n;
vi x(N);
vi y(N);
vii(a);
bool cmp(ii a, ii b) { return b.second < a.second; }
set<int> s, out;
 
int find(int i) {
    if(out.find(i)==out.end()) return i;
    auto it = s.lower_bound(i);
    if (it == s.end())
        return i;
    return *it;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    rf(i, 0, n-1) cin >> x[i];
    rf(i, 0, n-1) cin >> y[i];
    rf(i, 0, n-1) {
        a.pb({x[i], y[i]});
        s.insert(a[i].first);
        s.insert(a[i].first+1);
    }
 
    int mn = INF;
    sort(all(a), cmp);
    ll ans = 0;
    rf(i, 0, n-1) {
        int pos = find(a[i].first);
        ans += 1LL * (pos - a[i].first) * a[i].second;
        out.insert(pos);
        s.erase(pos);
        // cout << pos << "\n";
        int next = find(pos + 1);
        s.insert(next);
    }
    // assert(sz(out) == n);
    cout << ans << "\n";
}