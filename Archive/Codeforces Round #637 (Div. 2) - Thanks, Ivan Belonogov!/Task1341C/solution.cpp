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

int n;
int a[N];
int b[N];
int p[N];
int solve() {
    cin >> n;
    rf(i, 1, n) {
        cin >> a[i];
        p[a[i]] = i;
    }
    bool free = 1;
    int l = n;
    int nx = n - 1;
    rf(i, 1, n) {
        b[p[i]] = i;
        int tmp = i;
        int cur = p[i];
        while (cur < l) {
            b[++cur] = ++i;
        }
        l = p[tmp] - 1;
    }
    rf(i, 1, n) {
        if (a[i] != b[i])
            return cout << "No\n", 0;
    }
    cout << "Yes\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}