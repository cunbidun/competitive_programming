/**
 *  author: cunbidun
 *  created: Tuesday, 2022-11-29 21:11:21 CST
 *  tags: best-problem
 **/
#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  cout << ((s.size() % 2 != (s.front() == s.back())) ? "First" : "Second") << '\n';
}
