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

int n;
ii a[N];

bool cmp(ii A, ii B) { return A.second < B.second; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    rf(i, 1, n) {
        int x, y;
        cin >> x >> y;
        a[i].first = x - y;
        a[i].second = x + y;
    }
    sort(a + 1, a + 1 + n, cmp);
    int ans =0;
    int cur = -INF; 
    rf(i,1,n){
          if (a[i].first >= cur){
            ans ++;
            cur = a[i].second;
        }
    }
    cout << ans << "\n";
}