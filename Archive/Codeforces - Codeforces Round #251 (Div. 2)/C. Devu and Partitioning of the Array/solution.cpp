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
    int n, k, p;
    cin >> n >> k >> p;
    stack<int> e, o;
    rf(i, 1, n) {
        int x;
        cin >> x;
        if (x % 2 == 0)
            e.push(x);
        else
            o.push(x);
    }
    if (sz(o) < k - p || (sz(o) - (k - p)) % 2 != 0 || (sz(o) - (k - p)) / 2 + sz(e) < p)
        return cout << "NO\n", 0;
    cout << "YES\n";

    int tmp = k - p;
    while (tmp > 1) {
        tmp--;
        cout << 1 << " " << o.top() << "\n";
        o.pop();
    }
    tmp = p;
    while (tmp > 1) {
        if (!e.empty()) {
            cout << 1 << " " << e.top() << "\n";
            e.pop();
        } else if (sz(o) >= 2) {
            cout << 2 << " " << o.top() << " ";
            o.pop();
            cout << o.top() << "\n";
            o.pop();
        }
        tmp--;
    }

    if (p != 0 && p-k != 0) {
        cout << 1 << " " << o.top() << "\n";
        o.pop();
    }
    cout << sz(o) + sz(e) << " ";
    while (!o.empty()) {
        cout << o.top() << " ";
        o.pop();
    }

    while (!e.empty()) {
        cout << e.top() << " ";
        e.pop();
    }
    cout << "\n";
}