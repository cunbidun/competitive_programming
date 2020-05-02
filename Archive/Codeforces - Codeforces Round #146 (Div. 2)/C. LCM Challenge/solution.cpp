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
    ll n;
    cin >> n;
    if (n < 3)
        return cout << n << "\n", 0;
    cin >> n;
    if (n % 2 == 1)
        return cout << n * (n - 1) * (n - 2) << "\n", 0;
    ll ans = 0;
    ll num = n * (n - 1);
    rf(i, 1, n) { ans = max(ans, num * i / __gcd(num, 1LL * i)); }
    n--;
    cout << max(ans, n * (n - 1) * (n - 2)) << '\n';
}