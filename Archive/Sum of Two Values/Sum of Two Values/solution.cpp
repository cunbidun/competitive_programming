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

int n, x, a[N];
map<int, int> pos;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    rf(i, 1, n) { cin >> a[i]; }
    rf(i, 1, n) {
        if (pos.find(x - a[i]) != pos.end()) {
            cout << i << " " << pos[x - a[i]] << "\n";
            return 0;
        }
        pos[a[i]] = i;
    }
    cout << "IMPOSSIBLE\n";
}
