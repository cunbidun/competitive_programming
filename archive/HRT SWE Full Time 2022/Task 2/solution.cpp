#include <bits/stdc++.h>

using namespace std;

int INF = 1000000000;
int cal(vector<int> &cnt, int tar, int cur) {
  if (tar == cur) {
    return 0;
  }
  int need = abs(cur - tar);
  int res = 0;
  if (tar < cur) { // subtract
    for (int i = 6; i > 1; i--) {
      int sub = min(need, cnt[i] * (i - 1));
      need -= sub;
      res += (sub + (i - 1) - 1) / (i - 1);
      if (need == 0) {
        break;
      }
    }
  } else { // add
    for (int i = 1; i < 6; i++) {
      int add = min(need, cnt[i] * (6 - i));
      need -= add;
      res += (add + (6 - i) - 1) / (6 - i);
      if (need == 0) {
        break;
      }
    }
  }
  if (need != 0) {
    return INF;
  }
  return res;
};

int solution(vector<int> &A, vector<int> &B) {
  vector<int> c_a(7);
  vector<int> c_b(7);
  int s_a = 0, s_b = 0;
  for (int i : A) {
    c_a[i]++;
    s_a += i;
  }
  for (int i : B) {
    c_b[i]++;
    s_b += i;
  }

  int ans = INF;
  for (int i = 1; i <= 6 * (int)min(A.size(), B.size()); i++) {
    ans = min(ans, cal(c_a, i, s_a) + cal(c_b, i, s_b));
  }
  if (ans == INF) {
    return -1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<int> a(N), b(M);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> b[i];
  }
  cout << solution(a, b) << '\n';
}
