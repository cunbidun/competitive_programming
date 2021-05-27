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

int a[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    rf(i, 1, n) cin >> a[i];

    rf(i, 1, n - 2) {
        if (a[i] == a[i + 2])
            continue;
        if (a[i] < a[i + 1] && a[i] < a[i + 2])
            return cout << i << " " << i + 1, 0;
        if (a[i] > a[i + 1] && a[i] > a[i + 2])
            return cout << i << " " << i + 1, 0;
        return cout << i + 1 << " " << i + 2, 0;
    }
    if (n > 3 && a[1] != a[2])
        cout << 2 << " " << 3 << "\n";
    else
        cout << -1 << "\n";
}