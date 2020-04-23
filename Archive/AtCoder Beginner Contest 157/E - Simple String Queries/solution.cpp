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

const int N = 5e5 + 1;
const int INF = 2e9;

struct ft {
    vi bit;
    int n;

    ft() {
        this->n = N - 1;
        bit.assign(N - 1, 0);
    }

    void update(int p, int val) {
        while (p <= n) {
            bit[p] += val;
            p += p & -p;
        }
    }

    int get(int p) {
        int res = 0;
        while (p >= 1) {
            res += bit[p];
            p -= p & -p;
        }
        return res;
    }

    int get(int l, int r) { return get(r) - get(l - 1); }
};

char a[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ft bit[26];
    int n;
    cin >> n;
    rf(i, 1, n) {
        cin >> a[i];
        bit[a[i] - 'a'].update(i, 1);
    }
    int q;
    cin >> q;
    while (q--) {
        int c;
        cin >> c;
        if (c == 1) {
            int p;
            char t;
            cin >> p >> t;
            bit[a[p] - 'a'].update(p, -1);
            a[p] = t;
            bit[a[p] - 'a'].update(p, 1);
        } else {
            int ans = 0;
            int l, r;
            cin >> l >> r;
            rf(i, 0, 25) {
                if (bit[i].get(l, r) > 0)
                    ans++;
            }
            cout << ans << "\n";
        }
    }
}