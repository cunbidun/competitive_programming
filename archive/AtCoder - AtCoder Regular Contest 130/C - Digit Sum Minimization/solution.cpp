#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> a(10), b(10), a9(10), b9(10);
  string A, B;
  cin >> A >> B;
  for (int i = 0; i < (int)A.size(); i++) {
    a[A[i] - '0']++;
  }
  for (int i = 0; i < (int)B.size(); i++) {
    b[B[i] - '0']++;
  }
  for (int i = 1; i <= 9; i++) {
    int tmp = min(a[i], b[9 - i]);
    a9[i] = tmp;
    b9[9 - i] = tmp;
    a[i] -= tmp;
    b[9 - i] -= tmp;
  }
  vector<int> ans_a, ans_b;
  int cur = 0;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      while (i + j + cur >= 10 && a[i] > 0 && b[j] > 0) {
        cur = 1;
        a[i]--, b[j]--;
        ans_a.push_back(i);
        ans_b.push_back(j);
      }
    }
  }
  if (ans_a.empty()) {
    int pi = -1;
    int pj = -1;

    for (int i = 8; i > 0; i--) {
      if (a[i] > 0) {
        pi = i;
        break;
      }
    }
    for (int i = 9; i > 0; i--) {
      if (b9[i] > 0) {
        pj = i;
        break;
      }
    }
    if (pi != -1 && pj != -1 && pi + pj >= 10) {
      ans_a.push_back(pi);
      ans_b.push_back(pj);
      a[pi]--;
      b9[pj]--;
      a9[9 - pj]--;
      a[9 - pj]++;
    }
  }

  if (ans_a.empty()) {
    int pi = -1;
    int pj = -1;

    for (int i = 9; i > 0; i--) {
      if (a9[i] > 0) {
        pi = i;
        break;
      }
    }
    for (int i = 8; i > 0; i--) {
      if (b[i] > 0) {
        pj = i;
        break;
      }
    }
    if (pi != -1 && pj != -1 && pi + pj >= 10) {
      ans_a.push_back(pi);
      ans_b.push_back(pj);
      b[pj]--;
      a9[pi]--;
      b9[9 - pi]--;
      b[9 - pi]++;
    }
  }

  if (ans_a.empty()) {
    int pi = -1;
    int pj = -1;

    for (int i = 9; i > 0; i--) {
      if (a9[i] > 0) {
        pi = i;
        break;
      }
    }
    for (int i = 9; i > 0; i--) {
      if (b9[i] > 0) {
        pj = i;
        break;
      }
    }
    if (pi != -1 && pj != -1 && pi + pj >= 10) {
      ans_a.push_back(pi);
      ans_b.push_back(pj);
      b9[pj]--;
      a9[9 - pj]--;
      a[9 - pj]++;
      a9[pi]--;
      b9[9 - pi]--;
      b[9 - pi]++;
    }
  }

  if (ans_a.empty()) {
    if (a[9] > 0) {
      a[9]--;
      ans_a.push_back(9);
      for (int i = 9; i > 0; i--) {
        if (b9[i] > 0) {
          b9[i]--;
          a9[9 - i]--;
          a[9 - i]++;
          ans_b.push_back(i);
          break;
        }
      }
    }
  }

  if (ans_a.empty()) {
    if (b[9] > 0) {
      b[9]--;
      ans_b.push_back(9);
      for (int i = 9; i > 0; i--) {
        if (a9[i] > 0) {
          a9[i]--;
          b9[9 - i]--;
          b[9 - i]++;
          ans_a.push_back(i);
          break;
        }
      }
    }
  }

  for (int i = 1; i <= 9; i++) {
    for (int j = 0; j < a9[i]; j++) {
      ans_a.push_back(i);
      ans_b.push_back(9 - i);
    }
  }
  reverse(ans_a.begin(), ans_a.end());
  reverse(ans_b.begin(), ans_b.end());
  for (int i = 1; i <= 9; i++) {
    for (int j = 0; j < a[i]; j++) {
      cout << i;
    }
  }
  for (auto i : ans_a) {
    cout << i;
  }
  cout << '\n';

  for (int i = 1; i <= 9; i++) {
    for (int j = 0; j < b[i]; j++) {
      cout << i;
    }
  }
  for (auto i : ans_b) {
    cout << i;
  }
  cout << '\n';
}
