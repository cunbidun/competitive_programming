#include <bits/stdc++.h>

using namespace std;

class BIT {
  vector<long long> bit; // 1‑based
public:
  explicit BIT(int n) : bit(n + 1, 0) {}
  // add v at index idx
  void add(int idx, long long v = 1) {
    for (; idx < (int)bit.size(); idx += idx & -idx)
      bit[idx] += v;
  }
  // prefix sum [1 … idx]
  long long sum(int idx) const {
    long long s = 0;
    for (; idx > 0; idx -= idx & -idx)
      s += bit[idx];
    return s;
  }
};

long long inversion_count(vector<int> a) {
  const int n = (int)a.size();

  // 1) coordinate‑compress the values to 1 … n
  vector<int> sorted = a;
  sort(sorted.begin(), sorted.end());
  sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
  for (int &x : a)
    x = int(lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin()) + 1;

  // 2) traverse from right to left, updating/querying BIT
  BIT fenw(sorted.size());
  long long inv = 0;
  for (int i = n - 1; i >= 0; --i) {
    inv += fenw.sum(a[i] - 1); // count elements < a[i] already seen
    fenw.add(a[i]);            // insert current element
  }
  return inv;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> odd;
    vector<int> even;
    for (int i = 0; i < N; i++) {
      cin >> a[i];
      if (i % 2 == 0) {
        even.push_back(a[i]);
      } else {
        odd.push_back(a[i]);
      }
    }
    int odd_inverse = inversion_count(odd);
    int even_inverse = inversion_count(even);
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    vector<int> ans;
    if (N % 2 == 0) {
      for (int i = 0; i < 2; i++) {
        if (even.size() > 0) {
          ans.push_back(even.back());
          even.pop_back();
        }
      }
      for (int i = 0; i < 2; i++) {
        if (odd.size() > 0) {
          ans.push_back(odd.back());
          odd.pop_back();
        }
      }
    } else {
      for (int i = 0; i < 2; i++) {
        if (odd.size() > 0) {
          ans.push_back(odd.back());
          odd.pop_back();
        }
      }
      for (int i = 0; i < 2; i++) {
        if (even.size() > 0) {
          ans.push_back(even.back());
          even.pop_back();
        }
      }
    }
    int idx = 0;
    while (idx < int(min(odd.size(), even.size()))) {
      cout << even[idx] << ' ';
      cout << odd[idx] << ' ';
      idx++;
    }
    if (idx < (int)even.size()) {
      cout << even[idx] << ' ';
      idx++;
    }
    if (idx < (int)odd.size()) {
      cout << odd[idx] << ' ';
      idx++;
    }

    if (abs(odd_inverse - even_inverse) % 2 != 0) {
      cout << ans[1] << ' ';
      cout << ans[2] << ' ';
      cout << ans[0] << ' ';
      cout << ans[3] << ' ';
    } else {
      cout << ans[1] << ' ';
      cout << ans[3] << ' ';
      cout << ans[0] << ' ';
      cout << ans[2] << ' ';
    }
    cout << '\n';
  }
}
