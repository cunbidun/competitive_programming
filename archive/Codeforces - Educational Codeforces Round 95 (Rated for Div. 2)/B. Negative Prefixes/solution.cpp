#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, a[150],b[105];
void solve() {
  cin >> n;
  for(int i = 1;i <= n;i++){
    cin >> a[i];
  }
  vi l;
  for(int i = 1;i <= n;i++){
    cin >> b[i];
    if(b[i] == 0) {
      l.push_back(a[i]);
    }
  }
  sort(all(l));
  reverse(all(l));
  int p = 0;
  for(int i =1 ;i <= n;i++) {
    if(b[i] == 1) {
      cout << a[i] << " ";
    }
    else {
      cout << l[p ++] << " ";
    }
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
