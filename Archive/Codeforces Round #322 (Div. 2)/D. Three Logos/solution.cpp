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

const int N = 1e2 + 1;
const int INF = 2e9;
int a, b, c, d, e, f;
int n = 0;
char res[N][N];
void solve(int x, int y, int z, int t, int u, int v) {
    rf(i, 1, n) rf(j, 1, n) res[i][j] = '.';
    int p = 1, q = 1;
    rf(i, 1, x) rf(j, 1, y) {
        if (p + i - 1 > n || q + j - 1 > n)
            return;
        res[p + i - 1][q + j - 1] = 'A';
    }

    // if (x == 1 && y == 5 && z == 2 && t == 5 && u == 2 && v == 5) {
    //     rf(i, 1, n) {
    //         rf(j, 1, n) cout << res[i][j] << "";
    //         cout << "\n";
    //     }
    //     cout << "\n";
    // }

    int d = 0;
    rf(i, 1, n) {
        rf(j, 1, n) if (res[i][j] == '.') {
            p = i;
            q = j;
            d = 1;
            break;
        }
        if (d)
            break;
    }
    if (!d)
        return;

    if (x == 1 && y == 5 && z == 2 && t == 5 && u == 2 && v == 5) {
        cout << p << " " << q << "\n";
    }
    rf(i, 1, z) rf(j, 1, t) {
        if (p + i - 1 > n || q + j - 1 > n)
            return;
        res[p + i - 1][q + j - 1] = 'B';
    }


    d = 0;
    rf(i, 1, n) {
        rf(j, 1, n) if (res[i][j] == '.') {
            p = i;
            q = j;
            d = 1;
            break;
        }
        if (d)
            break;
    }
    if (!d)
        return;

    rf(i, 1, u) rf(j, 1, v) {
        if (p + i - 1 > n || q + j - 1 > n)
            return;
        res[p + i - 1][q + j - 1] = 'C';
    }

    rf(i, 1, n) rf(j, 1, n) if (res[i][j] == '.') return;
    cout << n << "\n";
    rf(i, 1, n) {
        rf(j, 1, n) cout << res[i][j] << "";
        cout << "\n";
    }
    exit(0);
}

void prep(int x, int y, int z, int t, int u, int v) {
    solve(x, y, z, t, u, v);
    solve(x, y, z, t, v, u);
    solve(x, y, t, z, u, v);
    solve(x, y, t, z, v, u);
    solve(y, x, z, t, u, v);
    solve(y, x, z, t, v, u);
    solve(y, x, t, z, u, v);
    solve(y, x, t, z, v, u);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c >> d >> e >> f;
    n = max(n, a);
    n = max(n, b);
    n = max(n, c);
    n = max(n, d);
    n = max(n, e);
    n = max(n, f);
    prep(a, b, c, d, e, f);
    prep(a, b, e, f, c, d);
    prep(c, d, a, b, e, f);
    prep(c, d, e, f, a, b);
    prep(e, f, a, b, c, d);
    prep(e, f, c, d, a, b);
    cout << "-1"
         << "\n";
}