/**
 *  author: cunbidun
 *  created: Friday, 2023-05-19 00:13:09 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  string S;
  cin >> S;
  vector<set<int>> a(N);
  vector<int> cnt_a(N), cnt_b(N);
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    a[x].insert(y);
    a[y].insert(x);
  }
  for (int i = 0; i < N; i++) {
    for (int j : a[i]) {
      if (S[j] == 'A') {
        cnt_a[i]++;
      } else {
        cnt_b[i]++;
      }
    }
  }
  queue<int> q;
  for (int i = 0; i < N; i++) {
    if (cnt_a[i] == 0 || cnt_b[i] == 0) {
      q.push(i);
    }
  }
  vector<int> visited(N);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (visited[u]) {
      continue;
    }
    visited[u] = 1;
    for (int v : a[u]) {
      if (!visited[v]) {
        if (S[u] == 'A') {
          cnt_a[v]--;
        } else {
          cnt_b[v]--;
        }
        if (cnt_a[v] == 0 || cnt_b[v] == 0) {
          q.push(v);
        }
      }
    }
  }
  int f = 0;
  for (int i : visited) {
    if (!i) {
      f = 1;
      break;
    }
  }
  if (f) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
