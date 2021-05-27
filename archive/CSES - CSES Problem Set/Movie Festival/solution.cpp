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

const int N = 2e5 + 1;
const int INF = 2e9;

bool cmp(ii A, ii B) { return A.second < B.second; }

int n, f[N], cur = 0, ans = 0;
ii a[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    rf(i, 1, n) { cin >> a[i].first >> a[i].second; }
    sort(a + 1, a + n + 1, cmp);
    rf(i, 1, n) {
        if (a[i].first >= cur){
            ans ++;
            cur = a[i].second;
        }
    }
    cout << ans << '\n';
}