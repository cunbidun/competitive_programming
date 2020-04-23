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
    string s;
    cin >> s;
    vi ans;
    int p1 = 0, p2 = sz(s) - 1;
    while (p1 < p2) {
        while (p1 < sz(s) && s[p1] != '(')
            p1++;
        while (p2 >= 0 && s[p2] != ')')
            p2--;
        if (p1 < p2) {
            ans.pb(p1 + 1);
            ans.pb(p2 + 1);
            s[p1] = 'X';
            s[p2] = 'X';
        }
    }
    rf(i, 0, sz(s) - 1) if (s[i] == '(') {
        rf(j,i+1,sz(s)-1) assert(s[i]!=')'); 
    }
    sort(all(ans));

    // if (sz(ans) == sz(s)) {
    //     if (sz(ans) - 2 == 0)
    //         return cout << 0 << "\n", 0;
    //     cout << 1 << "\n";
    //     cout << sz(ans) - 2 << "\n";
    //     for (int i = 1; i < sz(ans) - 1; i++)
    //         cout << ans[i] << " ";
    //     cout << "\n";
    //     return 0;
    // }
    if (sz(ans) == 0)
        return cout << 0 << "\n", 0;
    cout << 1 << "\n";
    cout << sz(ans) << "\n";
    for (int i : ans)
        cout << i << " ";
    cout << "\n";
    return 0;
}