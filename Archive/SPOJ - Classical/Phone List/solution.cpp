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

int trie[N][10];
bool e[N];
int id = 1;

bool cmp(string a, string b) { return sz(a) < sz(b); }

bool add(string s) {
    int cur = 1;
    rf(i, 0, sz(s) - 1) {
        if (trie[cur][s[i] - '0'] == 0)
            trie[cur][s[i] - '0'] = ++id;
        cur = trie[cur][s[i] - '0'];
        if (e[cur])
            return 0;
    }
    e[cur] = 1;
    return 1;
}

void solve() {
    int n;
    cin >> n;
    vector<string> a;
    while (n--) {
        string s;
        cin >> s;
        a.pb(s);
    }
    sort(all(a), cmp);
    for (string s : a) 
        if (!add(s)) {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        id = 1;
        memset(e, 0, sizeof(e));
        memset(trie, 0, sizeof(trie));
        solve();
    }
}
