#include <bits/stdc++.h>

using namespace std;

int putaway(int A, int B, int T, int X[], int Y[], int W[], int S[]) {
  sort(X, X + A);
  sort(Y, Y + B);

  vector<int> a[A];
  vector<int> b_side;
  for (int i = 0; i < T; i++) {
    if (A == 0 || W[i] >= X[A - 1]) {
      b_side.push_back(S[i]);
    } else {
      int l = 0, r = A - 1;
      while (l < r) {
        int m = (l + r) / 2;
        if (X[m] > W[i]) {
          r = m;
        } else {
          l = m + 1;
        }
      }
      a[l].push_back(i);
    }
  }

  auto check = [&](int m) -> bool {
    vector<int> c = b_side;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = A - 1; i >= 0; i--) {
      for (int j : a[i]) {
        pq.push(S[j]);
      }
      while (1LL * ((int)pq.size()) > 1LL * m * (A - i)) {
        int tmp = pq.top();
        pq.pop();
        c.push_back(tmp);
      }
    }
    if (c.size() == 0) {
      return 1;
    }
    if (B == 0) {
      return 0;
    }
    vector<int> b[B];
    for (int w : c) {
      if (w >= Y[B - 1]) {
        return 0;
      }
      int l = 0, r = B - 1;
      while (l < r) {
        int m = (l + r) / 2;
        if (Y[m] > w) {
          r = m;
        } else {
          l = m + 1;
        }
      }
      b[l].push_back(w);
    }

    int r = 0;
    int rb = 0;
    for (int j = B - 1; j >= 0; j--) {
      r += (int)b[j].size();
      rb = max(rb, (r + (B - j - 1)) / (B - j));
    }
    return rb <= m;
  };
  int l = 0, r = 1000001;
  while (l < r) {
    int m = (l + r) / 2;
    if (check(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  if (l == 1000001) {
    return -1;
  }
  return l;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int A, B, T;
  cin >> A >> B >> T;
  int X[A], Y[B], W[T], S[T];
  for (int i = 0; i < A; i++) {
    cin >> X[i];
  }
  for (int i = 0; i < B; i++) {
    cin >> Y[i];
  }
  for (int i = 0; i < T; i++) {
    cin >> W[i];
  }
  for (int i = 0; i < T; i++) {
    cin >> S[i];
  }
  cout << putaway(A, B, T, X, Y, W, S) << '\n';
  return 0;
}
