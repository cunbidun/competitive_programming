#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> ii;

const int N = 1e5 + 1;
const int INF = 2e9;

int n, d;
ll a, b;
ii arr[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d >> a >> b;
    rf(i, 1, n) {
        int x, y;
        cin >> x >> y;
        arr[i] = {x * a + y * b, i};
    }
    sort(arr + 1, arr + 1 + n);
    int tot = 0;
    vi ans;
    rf(i, 1, n) {
        if (tot + arr[i].first > d)
            break;
        tot += arr[i].first;
        ans.pb(arr[i].second);
    }
    cout << sz(ans) << "\n";
    for (int i : ans)
        cout << i << ' ';
    cout << "\n";
}