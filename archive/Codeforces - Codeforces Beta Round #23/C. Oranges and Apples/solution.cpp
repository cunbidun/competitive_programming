#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n;
tuple<int, int, int> a[(int)2e5 + 1];
ll sum[2];

bool cmp(tuple<int, int, int> A, tuple<int, int, int> B) {
  return get<0>(A) > get<0>(B);
}

int solve() {
  sum[0] = 0;
  sum[1] = 0;
  cin >> n;
  for (int i = 1; i <= 2 * n - 1; i++) {
    int apple, orange;
    cin >> apple >> orange;
    a[i] = {apple, orange, i};
  }
  sort(a + 1, a + 2 * n, cmp);
  for (int i = 2; i <= 2 * n - 1; i++) {
    sum[i % 2] += get<1>(a[i]);
  }
  cout << "YES\n";
  cout << get<2>(a[1]) << " ";
  for (int i = 2; i <= 2 * n - 1; i += 2) {
    cout << get<2>(a[i + (sum[1] > sum[0])]) << " ";
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