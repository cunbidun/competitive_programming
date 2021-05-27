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

const int N = 1e3 + 1;
const int INF = 2e9;

int n, m, r[N], c[N];
char a[N][N];

void dfs(int x, int y) {
    // cout << x << " " << y << '\n';
    if(a[x][y] == '.') return;
    a[x][y] ='.';
    if (x > 1)
        dfs(x - 1, y);
    if (y > 1)
        dfs(x, y - 1);
    if (x < n)
        dfs(x + 1, y);
    if (y < m)
        dfs(x, y + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    rf(i, 1, n) rf(j, 1, m) cin >> a[i][j];
    rf(i, 1, n) rf(j, 1, m) if (a[i][j] == '#' && a[i][j] != a[i][j - 1])
        r[i]++;
    rf(i, 1, m) rf(j, 1, n) if (a[j][i] == '#' && a[j][i] != a[j - 1][i])
        c[i]++;
    rf(i, 1, m) if (c[i] >= 2) return cout << -1 << '\n', 0;
    rf(i, 1, n) if (r[i] >= 2) return cout << -1 << '\n', 0;
    set<int> row, col;
    rf(i, 1, n) row.insert(i);
    rf(i, 1, m) col.insert(i);
    rf(i, 1, n) rf(j, 1, m) if (a[i][j] == '#') {
        row.erase(i);
        col.erase(j);
    }
    for (int n1 : row)
        for (int n2 : col)
            a[n1][n2] = '?';
    row.clear();
    col.clear();
    rf(i, 1, n) rf(j, 1, m) if (a[i][j] != '.') {
        row.insert(i);
        col.insert(j);
    }
    if (sz(row) != n || sz(col) != m)
        return cout << -1 << '\n', 0;
    
    int ans = 0;
    
    rf(i, 1, n) rf(j, 1, m) if (a[i][j] == '#') {
        ans++;
        dfs(i, j);
    }
    
    cout << ans;
}