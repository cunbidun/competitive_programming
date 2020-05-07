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

int n, m, a[N];
map<int, int> cnt;
set<int> current;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    rf(i, 1, n) {
        cin >> a[i];
        cnt[a[i]]++;
        current.insert(a[i]);
    }
    rf(i, 1, m) {
        int x;
        cin >> x;
        if (sz(current) == 0 || current.upper_bound(x) == current.begin()) {
            cout << -1 << "\n";
            continue;
        }
        auto it = current.upper_bound(x);
        it--;
        int val = *it;
        cout << val << "\n";
        cnt[val]--;
        if (!cnt[val])
            current.erase(val);
    }
}