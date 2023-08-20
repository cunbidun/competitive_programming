#ifndef _GENLIB_H_
#define _GENLIB_H_

#include <array>
#include <assert.h>
#include <iostream>

#include "testlib.h"
using namespace std;

inline string gen_string(int n, bool lower, bool upper, bool number, string custom, bool p = true) {
  string s = "";
  if (custom == "") {
    if (lower) {
      custom += "a-z";
    }
    if (upper) {
      custom += "A-Z";
    }
    if (number) {
      custom += "0-9";
    }
  }
  s = rnd.next("[" + custom + "]{" + to_string(n) + "}");
  if (p) {
    cout << s;
  }
  return s;
}

template <class T> vector<T> gen_array(int n, T min_val, T max_val, bool p = true) {
  vector<T> array;
  for (int i = 0; i < n; i++) {
    array.push_back(rnd.next(min_val, max_val));
  }
  if (p) {
    for (int i = 0; i < n; i++) {
      if (i != 0) {
        cout << " ";
      }
      cout << array[i];
    }
  }
  return array;
}

inline vector<vector<int>> gen_directed_graph(int n, int m, int st = 1, bool p = true) {
  vector<vector<int>> g(n);
  set<pair<int, int>> s;
  for (int i = 0; i < m; i++) {
    int u = rnd.next(0, n - 1);
    int v = rnd.next(0, n - 1);
    if (u == v || s.find({u, v}) != s.end()) {
      i--;
    } else {
      g[u].push_back(v);
      s.insert({u, v});
    }
  }
  if (p) {
    for (int i = 0; i < n; i++) {
      for (int j : g[i]) {
        cout << i + st << " " << j + st << "\n";
      }
    }
  }
  return g;
}

inline vector<vector<int>> gen_graph(int n, int m, int st = 1, bool p = true) {
  vector<vector<int>> g(n);
  set<pair<int, int>> s;
  for (int i = 0; i < m; i++) {
    int u = rnd.next(0, n - 1);
    int v = rnd.next(0, n - 1);
    if (u == v || s.find({min(u, v), max(u, v)}) != s.end()) {
      i--;
    } else {
      g[u].push_back(v);
      s.insert({min(u, v), max(u, v)});
    }
  }
  if (p) {
    for (int i = 0; i < n; i++) {
      for (int j : g[i]) {
        cout << i + st << " " << j + st << "\n";
      }
    }
  }
  return g;
}

inline vector<vector<int>> gen_weighted_graph(int n, int m, int min_wt, int max_wt, int st = 1, bool p = true) {
  vector<vector<int>> g(n);
  set<pair<int, int>> s;
  vector<pair<int, int>> edges;
  for (int i = 0; i < m; i++) {
    int u = rnd.next(0, n - 1);
    int v = rnd.next(0, n - 1);
    if (u == v || s.find({u, v}) != s.end()) {
      i--;
    } else {
      edges.push_back({u, v});
      s.insert({u, v});
      s.insert({v, u});
    }
  }
  if (p) {
    for (auto [i, j] : edges) {
      cout << i + st << " " << j + st << " " << rnd.next(min_wt, max_wt) << "\n";
    }
  }
  return g;
}

inline vector<vector<array<int, 2>>> gen_weighted_tree(int n, int min_wt, int max_wt, int st = 1, bool p = true) {
  vector<array<int, 3>> edge;
  vector<vector<array<int, 2>>> tree(n);
  for (int i = 1; i < n; i++) {
    int pre = rnd.next(0, i - 1);
    int k = rnd.next(min_wt, max_wt);
    edge.push_back({i, pre, k});
    tree[i].push_back({pre, k});
    tree[pre].push_back({i, k});
  }
  if (p) {
    for (auto [i, j, k] : edge) {
      cout << i + st << " " << j + st << " " << k << "\n";
    }
  }
  return tree;
}

inline vector<array<int, 3>> gen_weighted_tree_edge_list(int n, int min_wt, int max_wt, int st = 1, bool p = true) {
  vector<array<int, 3>> edge;
  for (int i = 1; i < n; i++) {
    int pre = rnd.next(0, i - 1);
    int k = rnd.next(min_wt, max_wt);
    edge.push_back({i, pre, k});
  }
  if (p) {
    for (auto [i, j, k] : edge) {
      cout << i + st << " " << j + st << " " << k << "\n";
    }
  }
  return edge;
}

inline vector<array<int, 3>>
gen_weighted_connected_graph(int n, int m, int min_wt, int max_wt, int st = 1, bool p = true) {
  assert(m >= n - 1);
  m -= (n - 1);
  set<pair<int, int>> s;
  auto edges = gen_weighted_tree_edge_list(n, min_wt, max_wt, st, false);
  for (auto [u, v, w] : edges) {
    s.insert({u, v});
    s.insert({v, u});
  }
  for (int i = 0; i < m; i++) {
    int u = rnd.next(0, n - 1);
    int v = rnd.next(0, n - 1);
    if (u == v || s.find({u, v}) != s.end()) {
      i--;
    } else {
      int w = rnd.next(min_wt, max_wt);
      edges.push_back({u, v, w});
      s.insert({u, v});
      s.insert({v, u});
    }
  }
  if (p) {
    for (auto [i, j, w] : edges) {
      cout << i + st << " " << j + st << " " << w << "\n";
    }
  }
  return edges;
}

inline vector<vector<int>> gen_tree(int n, int st = 1, bool p = true) {
  vector<array<int, 2>> edge;
  vector<vector<int>> tree(n);
  for (int i = 1; i < n; i++) {
    int pre = rnd.next(0, i - 1);
    edge.push_back({i, pre});
    tree[i].push_back(pre);
    tree[pre].push_back(i);
  }
  if (p) {
    for (auto [i, j] : edge) {
      cout << i + st << " " << j + st << "\n";
    }
  }
  return tree;
}

inline vector<vector<int>> gen_forest(int n, int m, int st = 1, bool p = true) {
  assert(n > m);
  vector<array<int, 2>> edge;
  vector<vector<int>> forest(n);
  vector<int> perm = rnd.perm(n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (perm[i] != 0) {
      int pre = rnd.next(0, perm[i] - 1);
      edge.push_back({perm[i], pre});
      forest[perm[i]].push_back(pre);
      forest[pre].push_back(perm[i]);
      cnt++;
      if (cnt == m) {
        break;
      }
    }
  }
  if (p) {
    for (auto [i, j] : edge) {
      cout << i + st << " " << j + st << "\n";
    }
  }
  return forest;
}

inline vector<int> gen_tree_p_list(int n, int st = 1, bool p = true) {
  vector<int> parent;
  for (int i = 1; i < n; i++) {
    int pre = rnd.next(0, i - 1);
    parent.push_back(pre + st);
  }
  if (p) {
    for (int i : parent) {
      cout << i << ' ';
    }
    cout << '\n';
  }
  return parent;
}

inline vector<vector<int>> gen_connected_graph(int n, int m, int st = 1, bool p = true) {
  assert(m >= n - 1);
  set<pair<int, int>> edge;
  auto g = gen_tree(n, 0, false);
  for (int i = 0; i < n; i++) {
    for (int j : g[i]) {
      edge.insert({min(i, j), max(i, j)});
    }
  }
  for (int i = 0; i < m - (n - 1); i++) {
    int u = rnd.next(0, n - 1);
    int v = rnd.next(0, n - 1);
    if (u == v || edge.find({min(u, v), max(u, v)}) != edge.end()) {
      i--;
    } else {
      g[u].push_back(v);
      g[v].push_back(u);
      edge.insert({min(u, v), max(u, v)});
    }
  }
  if (p) {
    for (auto [i, j] : edge) {
      if (rnd.next(0, 2))
        cout << i + st << " " << j + st << "\n";
      else {
        cout << j + st << " " << i + st << "\n";
      }
    }
  }
  return g;
}
#endif
