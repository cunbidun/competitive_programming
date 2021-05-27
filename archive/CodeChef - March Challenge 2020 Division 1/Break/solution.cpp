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

const int N = 1e5 + 5;
const int INF = 2e9;
int n;
vi a, b;
int solve1() {
    sort(all(a));
    sort(all(b));
    set<int> used;
    if (a[0] >= b[0])
        return 0;
    int pa = 1, pb = 1;
    used.insert(a[0]);
    used.insert(b[0]);
    while (pa < n) {
        if (used.find(a[pa]) != used.end())
            if (a[pa] >= b[pa])
                return 0;
            else {
                used.insert(a[pa++]);
                used.insert(b[pb++]);
            }
        else
            return 0;
    }
    return 1;
}

int solve2() {
    if (n == 1)
        return solve1();
    if (n == 2) {
        if (solve1())
            return 1;
        if (a[0] < b[1] && a[1] > b[0])
            return 1;
        return 0;
    }
    vi l;
    int mna = INF;
    int mnb = INF;
    int mxa = 0;
    int mxb = 0;
    rf(i, 0, n - 1) l.pb(a[i]), mxa = max(mxa, a[i]), mna = min(mna, a[i]);
    rf(i, 0, n - 1) l.pb(b[i]), mxb = max(mxb, b[i]), mnb = min(mnb, b[i]);
    if (mxa == mna && mna >= mxb)
        return 0;
    if (mna >= mxb) {
        l.erase(find(all(l), mna));
        l.erase(find(all(l), mxa));
    }
    sort(all(l));

    int len = sz(l) / 2;
    rf(i, 0, len - 1) 
        if (l[i] == l[i + len])
            return 0;
    return 1;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, s;
    cin >> t >> s;
    while (t--) {
        cin >> n;
        rf(i, 1, n) {
            int x;
            cin >> x;
            a.pb(x);
        }
        rf(i, 1, n) {
            int x;
            cin >> x;
            b.pb(x);
        }

        if (s == 1)
            if (solve1())
                cout << "YES\n";
            else
                cout << "NO\n";
        else if (solve2())
            cout << "YES\n";
        else
            cout << "NO\n";
        a.clear();
        b.clear();
    }
}