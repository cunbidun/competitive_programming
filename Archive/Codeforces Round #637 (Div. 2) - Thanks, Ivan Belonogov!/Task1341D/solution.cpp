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

const int N = 2e3 + 1;
const int INF = 2e9;

string num[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string a[N];
int ans[N];
int f[N][N];
int n;

int check(string s, int e) {
    int res = 0;
    rf(i, 0, 6) {
        if (s[i] == '1' && num[e][i] == '0')
            return INF;
        if (s[i] == '0' && num[e][i] == '1')
            res++;
    }
    return res;
}

bool solve(int i, int k) {
    if (f[i][k] != -1)
        return f[i][k];
    if (i == n) {
        rb(j, 9, 0) 
            if (check(a[i], j) == k) {
                ans[i] = j;
                return f[i][k] = 1;
            }
        return f[i][k] = 0;
    }
    rb(j, 9, 0) 
        if (check(a[i], j) <= k && solve(i + 1, k - check(a[i], j))) {
            ans[i] = j;
            return f[i][k] = 1;
        }
    return f[i][k] = 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> n >> k;

    rf(i, 1, n) rf(j, 0, k) f[i][j] = -1;

    rf(i, 1, n) cin >> a[i];
    if (solve(1, k)) {
        rf(i, 1, n) cout << ans[i];
        cout << "\n";
    } else {
        cout << -1 << '\n';
    }
}