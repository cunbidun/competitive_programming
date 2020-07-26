#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int N = 1e6 + 1;

char s[N];
vector<pair<int, char>> ans;
int n, m, k;

void print() {
    cout << sz(ans) << "\n";
    for (auto p : ans)
        cout << p.first << " " << p.second << "\n";
}

void move(int l, char c) {
    if (l == 0)
        return;
    if (k <= l) {
        ans.pb({k, c});
        print();
        exit(0);
    }
    k -= l;
    ans.pb({l, c});
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    if (k > 4 * m * n - 2 * n - 2 * m) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    move(n - 1, 'D');
    rf(i, 1, n - 1) {
        move(m - 1, 'R');
        move(m - 1, 'L');
        move(1, 'U');
    }
    rf(i, 1, m - 1) {
        move(1, 'R');
        move(n - 1, 'D');
        move(n - 1, 'U');
    }
    move(m - 1, 'L');
}