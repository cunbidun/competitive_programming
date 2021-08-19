#ifndef _GENLIB_H_
#define _GENLIB_H_
#include <iostream>

#include "testlib.h"
using namespace std;

string gen_string(int n, bool lower, bool upper, bool number, string custom, bool p = true) {
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

template <class T>
vector<T> gen_array(int n, T min_val, T max_val, bool p = true) {
  vector<T> array;
  for (int i = 0; i < n; i++) {
    array.push_back(rnd.next(min_val, max_val));
  }
  if (p) {
    for (int i = 0; i < n; i++) {
      if (i != 0) {
        cout << " ";
      }
      cout << rnd.next(min_val, max_val);
    }
  }
  return array;
}

vector<vector<int>> gen_directed_graph(int n, int m, int st = 1, bool p = true) {
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

vector<vector<int>> gen_weighted_graph(int n, int m, int min_wt, int max_wt, int st = 1, bool p = true) {
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

vector<vector<array<int, 2>>> gen_weighted_tree(int n, int min_wt, int max_wt, int st = 1, bool p = true) {
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

vector<vector<int>> gen_tree(int n, int st = 1, bool p = true) {
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

vector<int> gen_tree_p_list(int n, int st = 1, bool p = true) {
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
#endif
