#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

void solve() {
  int n;
  cin >> n;
  int d,cnt =0;
  while(n ){
    d= n%10;
    n/=10;
    cnt ++;
  }
  cout << 10*(d-1)+ cnt*(cnt+1)/2 << "\n";
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