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

ll INF = 1e16;
ll c[N], v[N], m[N];
int n, q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    rf(i, 1, n) cin >> v[i];
    rf(i, 1, n) cin >> c[i];

    while (q--) {
        rf(i, 1, n) m[i] = -INF;
        ll max1 = -INF, max2 = -INF;
        ll a, b;
        cin >> a >> b;
        ll res = 0;
        rf(i, 1, n) {
            ll tmp = v[i] * b;
            ll cur = max1;
            if (m[c[i]] == max1)
                cur = max2;
            if (cur > 0)
                tmp += cur;
            if (m[c[i]] != -INF)
                tmp = max(tmp, m[c[i]] + v[i] * a);

            if (tmp >= max1) {
                if (max1 == m[c[i]])
                    max1 = tmp;
                else {
                    max2 = max1;
                    max1 = tmp;
                }
            } else {
                if (max1 != m[c[i]])
                    max2 = max(max2, tmp);
            }

            m[c[i]] = max(m[c[i]], tmp);

            res = max(res, tmp);
            // cout << i << " " << tmp << " " << max1 << " " << max2 <<  "\n";
        }
        cout << res << "\n";
    }
}