#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 3e5 + 5;

int n, a[N], b[N], temp[N];

ll merge(int l, int m, int r) {
  int i = l, j = m, k = l;
  ll inv = 0;
  while ((i <= m - 1) && (j <= r)) {
    if (b[i] <= b[j]) {
      temp[k++] = b[i++];
    } else {
      temp[k++] = b[j++];
      inv += (m - i);
    }
  }
  while (i <= m - 1) {
    temp[k++] = b[i++];
  }
  while (j <= r) {
    temp[k++] = b[j++];
  }
  for (i = l; i <= r; i++) {
    b[i] = temp[i];
  }
  return inv;
}

ll merge_sort(int l, int r) {
  if (l >= r) {
    return 0;
  }
  int m = (r + l) / 2;
  return merge_sort(l, m) + merge_sort(m + 1, r) + merge(l, m + 1, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  ll cur = merge_sort(1, n);
  ll x = 0;
  for (int i = 30; i >= 0; i--) {
    for (int j = 1; j <= n; j++) {
      b[j] = (a[j] ^ x ^ (1 << i));
    }
    ll tmp = merge_sort(1, n);
    if (tmp < cur) {
      cur = tmp;
      x ^= (1 << i);
    }
  }
  cout << cur << " " << x << "\n";
}