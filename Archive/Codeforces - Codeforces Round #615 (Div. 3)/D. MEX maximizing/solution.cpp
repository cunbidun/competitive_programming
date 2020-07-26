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

const int N = 4e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 2e9;

int n;
int x;
int a[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    int cur = 0;
    int ans = 0;
    while (n--) {
        int q;
        cin >> q;
        a[q % x]++;
        while (a[cur] != 0) {
            a[cur]--;
            cur = (cur + 1) % x;
            ans++;
        }
        cout << ans << "\n";
    }
}