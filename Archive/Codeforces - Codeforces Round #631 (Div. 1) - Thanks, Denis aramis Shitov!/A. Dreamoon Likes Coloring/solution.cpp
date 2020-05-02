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

int p[N], l[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int mx = 0;
    rf(i, 1, k) {
        p[i] = i;
        cin >> l[i];
        mx = max(mx, p[i] + l[i] - 1);
    }
    if (mx > n)
        return cout << -1 << "\n", 0;

    int needed = n;

    rb(i, k, 1) {
        if (p[i] + l[i] - 1 >= needed)
            break;
        p[i] = needed - l[i] + 1;
        needed = p[i] - 1;
    }
    if (p[1] != 1)
        return cout << -1 << "\n", 0;

    rf(i, 1, k) cout << p[i] << " ";
    cout << '\n';
}