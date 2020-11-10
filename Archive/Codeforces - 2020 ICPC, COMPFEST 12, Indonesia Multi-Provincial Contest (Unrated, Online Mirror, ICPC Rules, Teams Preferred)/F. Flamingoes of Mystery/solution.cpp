#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vi l;
  for (int i = 1; i < n; i++) {
    cout << "? " << i << " " << i + 1 << endl;
    int res;
    cin >> res;
    l.push_back(res);
  }
  cout << "? " <<  1 << " " << 3 << endl;
  int res;
  cin >> res;
  vi ans;
  ans.push_back(res - l[1]);
  for (int i = 0; i < sz(l); i++) {
    ans.push_back(l[i] - ans[sz(ans) - 1]);
  }
  cout << "! ";
  for (int i : ans) {
    cout << i << " ";
  }
  cout << endl;
}