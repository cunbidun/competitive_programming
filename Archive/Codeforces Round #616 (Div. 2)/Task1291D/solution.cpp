#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define watch(x) out << (#x) << " = " << (x) << endl
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int N = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;

    s = '*' + s;

    int cnt[sz(s)][26];
    rf(i, 1, sz(s)-1) {
        rf(j, 0, 25) cnt[i][j] = cnt[i - 1][j];
        cnt[i][s[i] - 'a']++;
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (s[l] != s[r] || l == r) {
            cout << "Yes\n";
            continue;
        }
        int num = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[r][i] - cnt[l - 1][i] > 0)
                num++;
        }
        if (num >= 3) 
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}