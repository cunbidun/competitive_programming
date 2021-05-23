#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  int B = 800;
  vector<int> a;
  for (int i = N; i >= 1; i--) {
    a.push_back(i);
  }
  vector<int> ch(N + 1);
  for (int i = 0; i < M; i++) {
    int x;
    cin >> x;
    ch[x] = 1;
    a.push_back(x);
  }
  vector<vector<int>> p(N + 1, vector<int>());
  for (int i = 0; i < (int)a.size(); i++) {
    p[a[i]].push_back(i);
  }
  struct q {
    int l, r, v;
  };
  vector<q> query;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j < (int)p[i].size(); j++) {
      query.push_back({p[i][j - 1], p[i][j], i});
    }
    query.push_back({p[i].back(), (int)a.size() - 1, i});
  }
  sort(query.begin(), query.end(), [&](q f, q s) {
    if (f.l / B != s.l / B) {
      return f.l < s.l;
    }
    return f.r < s.r;
  });
  vector<int> cnt(N + 1), mx(N + 1);
  int num = 0;
  auto add = [&](int i) {
    cnt[i]++;
    if (cnt[i] == 1) {
      num++;
    }
  };
  auto remove = [&](int i) {
    cnt[i]--;
    if (cnt[i] == 0) {
      num--;
    }
  };

  int l = 0, r = -1;
  for (int i = 0; i < (int)query.size(); i++) {
    while (r < query[i].r) {
      add(a[++r]);
    }
    while (r > query[i].r) {
      remove(a[r--]);
    }
    while (l < query[i].l) {
      remove(a[l++]);
    }
    while (l > query[i].l) {
      add(a[--l]);
    }
    mx[query[i].v] = max(mx[query[i].v], num);
  }

  for (int i = 1; i <= N; i++) {
    cout << ((ch[i]) ? 1 : i) << ' ' << mx[i] << '\n';
  }
}
