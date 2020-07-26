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

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << '(' << a.first << ", " << a.second << ')'; }

template <class T> ostream &operator<<(ostream &os, const vector<T> &a) {
    os << '[';
    for (unsigned int i = 0; i < a.size(); i++)
        os << a[i] << (i < a.size() - 1 ? ", " : "");
    os << ']';
    return os;
}

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int N = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 2e9;

int a, b, c, n, t;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> n;
        int s = a + b + c + n;
        if (s % 3 != 0 || a > s / 3 || b > s / 3 || c > s / 3 || s / 3 - a + s / 3 - b + s / 3 - c != n) {
            cout << "NO"
                 << "\n";
            continue;
        }
        cout << "YES"
             << "\n";
    }
}