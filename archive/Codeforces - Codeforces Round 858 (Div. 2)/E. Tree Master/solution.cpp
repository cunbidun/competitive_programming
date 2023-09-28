/**
 *  author: cunbidun
 *  created: Saturday, 2023-06-03 22:06:19 CDT
 **/
#include <array>
#include <assert.h>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

using ll = long long;

const int base = 1e8 + 7;
struct hash_map {
  int head[base];
  vector<int> next;
  vector<ll> key;
  vector<ll> val;
  hash_map() { memset(head, -1, sizeof(head)); }
  int hash(ll k) { return k % base; }
  ll &operator[](ll k) {
    int h = hash(k);
    for (int i = head[h]; ~i; i = next[i]) {
      if (key[i] == k) {
        return val[i];
      }
    }
    next.push_back(head[h]);
    key.push_back(k);
    val.push_back(0);
    head[h] = next.size() - 1;
    return val.back();
  }
  ll has_key(ll k) {
    int h = hash(k);
    for (int i = head[h]; ~i; i = next[i]) {
      if (key[i] == k) {
        return true;
      }
    }
    return false;
  }
};

const int MX = 1e5 + 2;
int a[MX], p[MX], cnt[MX], d[MX];
vector<int> tree[MX];

hash_map mp;

long long find(int u, int v) {
  if (u == -1) {
    return 0;
  }
  if (u > v) {
    swap(u, v);
  }
  long long id = (1LL * u << 32) | v;
  if (mp.has_key(id)) {
    return mp[id];
  }
  auto ans = find(p[u], p[v]) + 1LL * a[u] * a[v];
  if (cnt[d[u]] <= 320) {
    mp[id] = ans;
  }
  return ans;
}

void dfs(int x, int l) {
  ++cnt[l];
  d[x] = l;
  for (int to : tree[x]) {
    dfs(to, l + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < N; i++) {
    cin >> p[i];
    p[i]--;
    tree[p[i]].push_back(i);
  }
  dfs(0, 0);
  p[0] = -1;
  while (Q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    cout << find(u, v) << '\n';
  }
}
