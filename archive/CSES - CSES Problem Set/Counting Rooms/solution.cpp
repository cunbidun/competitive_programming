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

int n, m, vis[N][N];
void dfs(int i, int j) {
    if (vis[i][j])
        return;
    vis[i][j] = 1;
    if (i < n)
        dfs(i + 1, j);
    if (i > 1)
        dfs(i - 1, j);
    if (j < m)
        dfs(i, j + 1);
    if (j > 1)
        dfs(i, j - 1);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    rf(i, 1, n) rf(j, 1, m) {
        char x;
        cin >> x;
        if (x == '#')
            vis[i][j] = 1;
    }
    int ans = 0;
    rf(i, 1, n) rf(j, 1, m) if (!vis[i][j]) {
        ans++;
        dfs(i, j);
    }
    cout << ans << '\n';
}