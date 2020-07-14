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
int cnt[N];
int cur[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n + 1);
    rf(i, 1, n) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    rf(i, 2, N - 1) if (cnt[i - 1] < cnt[i]) return cout << -1 << "\n", 0;
    cout << cnt[1] << "\n";
    rf(i, 1, n) {
        cout << cur[a[i]] + 1 << " ";
        cur[a[i]]++;
    }
    cout << "\n";
}