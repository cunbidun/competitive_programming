#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 3e5 + 1;
const int MAX_BIT = 19;

int n, m, sum = 0;
int a[N], trie[1 << (MAX_BIT + 1)][2], child[1 << (MAX_BIT + 1)];
int cnt = 0;

void add(int x) {
  int cur = 0;
  for (int i = MAX_BIT; i >= 0; i--) {
    int b = ((x >> i) & 1);
    if (trie[cur][b] == -1) {
      trie[cur][b] = ++cnt;
    }
    cur = trie[cur][b];
  }
}

int cal(int u) {
  if (u == -1) {
    return 0;
  }
  return child[u] = 1 + cal(trie[u][1]) + cal(trie[u][0]);
}

int query() {
  int cur = 0;
  int ans = 0;
  for (int i = MAX_BIT; i >= 0; i--) {
    int b = ((sum >> i) & 1);
    int nxt = b;
    if (child[trie[cur][b]] == (1 << (i + 1)) - 1) {
      nxt = 1 - b;
    }
    ans += (abs(b - nxt)) << i;
    cur = trie[cur][nxt];
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 0; i < (1 << 20); i++) {
    trie[i][0] = -1;
    trie[i][1] = -1;
  }
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    add(a[i]);
  }
  cal(0);
  while (m--) {
    int x;
    cin >> x;
    sum ^= x;
    cout << query() << "\n";
  }
}