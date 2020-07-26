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

const int N = 1e5 + 1;
const int INF = 2e9;

int n;
int a[N], ans[N];
set<int> s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  rf(i, 1, n) {
    ans[i] = -1;
    cin >> a[i];
  }
  ans[1] = a[1] - 1;
  s.insert(ans[1]);
  s.insert(a[n]);
  rf(i, 2, n) if (a[i] != a[i - 1]) {
    ans[i] = a[i - 1];
    s.insert(ans[i]);
  }
  int cur = 0;
  rf(i, 1, n) if (ans[i] == -1) {
    while (s.find(cur) != s.end()) {
      cur++;
    }
    ans[i] = cur;
    s.insert(ans[i]);
  }
  s.clear();
  cur = 0;
  rf(i, 1, n) {
    s.insert(ans[i]);
    while (s.find(cur) != s.end()) {
      cur++;
    }
    if (cur != a[i]) return cout << "-1\n", 0;
  }
  rf(i, 1, n) cout << ans[i] << " ";
  cout << "\n";
}