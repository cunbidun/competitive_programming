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

const int N = 3e4 + 1;

int g[N];
int f[N][500];
int n, d;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d;
    rf(i, 1, n) {
        int x;
        cin >> x;
        if (x < d)
            continue;
        g[x]++;
    }
    int ans = g[d] + 1;
    f[d][245] = g[d] + 1;
    rf(i, d + 1, N - 1) rf(j, 0, 490) {
        int l = d + (j - 245);
        if (l < 1)
            continue;

        if (i >= l) {
            f[i][j] = max(f[i - l][j], f[i][j]);
            if (j > 0)
                f[i][j] = max(f[i - l][j - 1], f[i][j]);
            f[i][j] = max(f[i - l][j + 1], f[i][j]);
        }
        
        if (f[i][j])
            f[i][j] += g[i];
        ans = max(ans, f[i][j]);
    }
    cout << ans - 1 << "\n";
}

// 3
// 12
// 27