#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  int Q;
  cin >> Q;
  vector<array<int, 3>> q(Q);
  for (int i = 0; i < Q; i++) {
    cin >> q[i][0] >> q[i][1];
    q[i][0]--;
    q[i][1]--;
    q[i][2] = i;
  }
  sort(q.begin(), q.end(), [](const auto &x, const auto &y) {
    if (x[0] / 800 != y[0] / 800) {
      return x[0] / 800 < y[0] / 800;
    }
    return x[1] < y[1];
  });
  vector<int> cnt(N + 1);
  int l = 0, r = 0;
  int res = 0;
  vector<int> ans(Q);
  auto add = [&](int x) {
    cnt[a[x]]++;
    if (cnt[a[x]] % 2 == 0) {
      res++;
    }
  };
  auto remove = [&](int x) {
    if (cnt[a[x]] % 2 == 0) {
      res--;
    }
    cnt[a[x]]--;
  };
  add(0);
  for (int i = 0; i < Q; i++) {
    while (r < q[i][1]) {
      add(++r);
    }
    while (l > q[i][0]) {
      add(--l);
    }
    while (l < q[i][0]) {
      remove(l++);
    }
    while (r > q[i][1]) {
      remove(r--);
    }

    // cout << "Query " << i << ": " << q[i][0] << " " << q[i][1] << " " << res << " " << cnt[2] << endl;
    ans[q[i][2]] = res;
  }
  for (int i = 0; i < Q; i++) {
    cout << ans[i] << '\n';
  }
}
