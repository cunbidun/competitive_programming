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

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << '(' << a.first << ", " << a.second << ')'; }

template <class T> ostream &operator<<(ostream &os, const vector<T> &a) {
    os << '[';
    for (unsigned int i = 0; i < a.size(); i++)
        os << a[i] << (i < a.size() - 1 ? ", " : "");
    os << ']';
    return os;
}

const int N = 1e5 + 1;
const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<string> a, b;
    string mxA, mxB;
    string mid = "";
    rf(i, 1, n) {
        string s;
        cin >> s;
        string tmp = "";
        int p1 = 1000, p2 = -1;
        rf(i, 0, sz(s) - 1) {
            if (s[i] == '*') {
                p1 = i;
                break;
            }
            tmp += s[i];
        }
        a.pb(tmp);
        if (sz(tmp) > sz(mxA))
            mxA = tmp;
        tmp = "";
        rb(i, sz(s) - 1, 0) {
            if (s[i] == '*') {
                p2 = i;
                break;
            }
            tmp = s[i] + tmp;
        }
        b.pb(tmp);
        if (sz(tmp) > sz(mxB))
            mxB = tmp;

        rf(i, p1 + 1, p2 - 1) {
            if (s[i] != '*')
                mid += s[i];
        }
    }
    // cout << a << "\n";
    // cout << b << "\n";
    // cout << mxA <<"\n";
    // cout << mxB <<"\n";
    for (string s : a) {
        rf(i, 0, sz(s) - 1) {
            if (s[i] != mxA[i]) {
                cout << "*\n";
                return;
            }
        }
    }

    for (string s : b) {
        int cnt = 0;
        rb(i, sz(s) - 1, 0) {
            if (s[i] != mxB[sz(mxB) - 1 - cnt]) {
                cout << "*\n";
                return;
            }
            cnt++;
        }
    }
    cout << mxA << mid << mxB << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    rf(i, 1, t) {
        cout << "Case #" << i << ": ";
        solve();
    }
}