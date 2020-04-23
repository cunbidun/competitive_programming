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

const int N = 1e3 + 1;
const int INF = 2e9;

vi lp;
vi pr;
void sieve() {
    lp.assign(N, 0);
    for (int i = 2; i < N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    sieve();
    s = '*' + s;
    int free = 1;
    vi cnt(26);
    vector<bool> f(N);
    f[1] = 1;
    rf(i, 1, sz(s) - 1) {
        if (lp[i] == i && i * 2 > sz(s) - 1) {
            f[i] = 1;
            free++;
        }
        cnt[s[i] - 'a']++;
    }
    rf(i, 0, 25) {
        if (cnt[i] >= (sz(s) - 1 - free)) {
            cout << "YES\n";
            cnt[i] -= (sz(s) - 1 - free);
            string tmp = "";
            rf(j, 0, 25) while (cnt[j]--) tmp += (char)(j + 'a');
            int p = 0;
            rf(j, 1, sz(s) - 1) {
                if (!f[j]) {
                    cout << (char)(i + 'a');
                } else
                    cout << tmp[p++];
            }
            return 0;
        }
    }
    cout << "NO\n";
}