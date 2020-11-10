#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int BLOCK_SIZE = 800;

const int N = 1e5 + 5;
int n, q, ans[N], a[N], cnt = 1, trie[1 << 16][2], num[1 << 16];

void insert(int x) {
  int cur = 1;
  num[cur]++;
  for (int i = 15; i >= 0; i--) {
    int bit = (x >> i) & 1;
    if (trie[cur][bit] == 0) {
      int next = ++cnt;
      trie[cur][bit] = next; 
      cur = next;
    } else {
      cur = trie[cur][bit];
    }
    num[cur]++;
  }
}

void remove(int x) {
  int cur = 1;
  num[cur]--;
  for (int i = 15; i >= 0; i--) {
    int bit = (x >> i) & 1;
    cur = trie[cur][bit];
    num[cur]--;
  }
}

int get_max(int x) {
  int cur = 1;
  int res = 0;
  for (int i = 15; i >= 0; i--) {
    int bit = (x >> i) & 1;
    if (num[trie[cur][1 - bit]] != 0) {
      cur = trie[cur][1 - bit];
      res += (1 << i);
    } else {
      cur = trie[cur][bit];
    }
  }
  return res;
}

struct query {
  int id, v, l, r, b;
} query[N];

bool cmp(struct query A, struct query B) {
  if (A.b != B.b) {
    return A.b < B.b;
  } else {
    return A.r < B.r;
  }
}
void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= cnt; i++) {
    num[i] = 0;
    trie[i][0] = 0;
    trie[i][1] = 0;
  }
  cnt = 1;
  int L = 1, R = 0;
  for (int i = 1; i <= q; i++) {
    int v, l, r;
    cin >> v >> l >> r;
    query[i] = {i, v, l, r, l / BLOCK_SIZE};
  }
  sort(query + 1, query + q + 1, cmp);
  for (int i = 1; i <= q; i++) {
    while (R < query[i].r) {
      insert(a[++R]);
    }
    while (R > query[i].r) {
      remove(a[R--]);
    }
    while (L < query[i].l) {
      remove(a[L++]);
    }
    while (L > query[i].l) {
      insert(a[--L]);
    }
    ans[query[i].id] = get_max(query[i].v);
  }
  for (int i = 1; i <= q; i++) {
    cout << ans[i] << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}