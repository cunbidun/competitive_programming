#include <bits/stdc++.h>

using namespace std;

template <class T>
struct compressor {
public:
  vector<T> l;
  map<T, int> mp;
  compressor() {}
  void add(T x) {
    l.push_back(x);
  }
  void compress() {
    sort(l.begin(), l.end());
    l.resize(distance(l.begin(), unique(l.begin(), l.end())));
    for (int i : l)
      mp[i] = (int)mp.size() + 1;
  }
  int get(T x) {
    return mp[x];
  }
  int size() {
    return (int)mp.size();
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}
