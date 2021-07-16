#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    int N, K;
    cin >> N >> K;
    auto kxor = [&](int a, int b) -> int {
      vector<int> va, vb;
      while (a) {
        va.push_back(a % K);
        a /= K;
      }
      while (b) {
        vb.push_back(b % K);
        b /= K;
      }
      int val = 0;
      for (int i = (int)max(va.size(), vb.size()) - 1; i >= 0; i--) {
        int c = 0;
        if (i < (int)va.size()) {
          c += va[i];
        }
        if (i < (int)vb.size()) {
          c += vb[i];
        }
        c %= K;
        val *= K;
        val += c;
      }
      return val;
    };
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
      vector<int> v;
      int tmp = i;
      while (tmp) {
        v.push_back(tmp % K);
        tmp /= K;
      }
      for (int j = (int)v.size() - 1; j >= 0; j--) {
        p[i] *= K;
        p[i] += ((v[j] != 0) ? K - v[j] : 0);
      }
    }

    auto ask = [](int y) -> int {
      cout << y << endl;
      int r;
      cin >> r;
      return r;
    };

    if (ask(0)) {
      continue;
    }
    int f = 0;
    vector<int> ch(N);
    for (int i = 1; i < N - 1; i++) {
      int cur = i;
      int last = p[i - 1];
      if (i % 2 == 1) {
        cur = p[i];
        last = i - 1;
      }
      if (!ask(kxor(cur, last))) {
      } else {
        f = 1;
        break;
      }
    }
    if (f) {
      continue;
    }
    int cur = N - 1;
    int last = p[N - 2];
    if ((N - 1) % 2 == 1) {
      cur = p[N - 1];
      last = N - 2;
    }
    ask(kxor(cur, last));
  }
}
