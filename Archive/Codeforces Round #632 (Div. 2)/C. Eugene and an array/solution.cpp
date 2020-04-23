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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n + 1);
    rf(i, 1, n) cin >> a[i];
    map<ll, int> mp;
    mp[0] = 0;
    ll sum = 0;
    ll ans = 0;
    int p = 1;
    rf(i, 1, n) {
        sum += a[i];
        if (mp.find(sum) != mp.end())
            p = max(((*mp.find(sum)).second + 2),p);
        if (a[i] == 0)
            p = i + 1;
        ans += i - p + 1;
        mp[sum] = i;
    }
    cout << ans << "\n";
}