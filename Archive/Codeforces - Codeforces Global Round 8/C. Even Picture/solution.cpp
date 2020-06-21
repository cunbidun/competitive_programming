#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 1;
const int INF = 2e9;

vector<ii> ans;
int n;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    ans.push_back({i, i});
    ans.push_back({i, i + 1});
    ans.push_back({i, i - 1});
  }
  ans.push_back({0, 0});
  ans.push_back({0, 1});
  ans.push_back({n + 1, n});
  ans.push_back({n + 1, n + 1});
  cout << sz(ans) << "\n";
  for (ii i : ans) {
    cout << i.first << " " << i.second << "\n";
  }
}