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

const int N = 1e2 + 5;

char a[N][N];
int f[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h, w;
    cin >> h >> w;
    rf(i, 1, h) rf(j, 1, w) cin >> a[i][j];
    f[0][1] = 0;
    f[1][0] = 0;
    rf(i, 1, h) f[i][1] = f[i - 1][1] + (a[i][1] == '#' && a[i - 1][1] != '#');
    rf(i, 1, w) f[1][i] = f[1][i - 1] + (a[1][i] == '#' && a[1][i - 1] != '#');
    rf(i, 2, h) rf(j, 2, w) {
        int res1 = f[i - 1][j];
        int res2 = f[i][j - 1];
        if (a[i][j] == '#') {
            if (a[i - 1][j] != '#')
                res1++;
            if (a[i][j - 1] != '#')
                res2++;
        }
        f[i][j] = min(res1, res2);
    }
    cout << f[h][w] << "\n";
}