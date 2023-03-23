/**
 *  author: cunbidun
 *  created: Wednesday, 2023-03-01 22:07:20 CST
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

template <class c> struct rge { c b, e; };
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c> char dud(...);
struct debug {
#ifdef LOCALN
  ~debug() { cout << endl; }
  template <class c> typename enable_if<sizeof dud<c>(0) != 1, debug &>::type operator<<(c i) {
    cout << boolalpha << i;
    return *this;
  }
  template <class c> typename enable_if<sizeof dud<c>(0) == 1, debug &>::type operator<<(c i) {
    return *this << range(begin(i), end(i));
  }
  template <class c, class b> debug &operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class c> debug &operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) {
      *this << ((it == d.b) ? "" : ", ") << *it;
    }
    return *this << "]";
  }
#else
  template <class c> debug &operator<<(const c &) { return *this; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int MX_N = 64;
const int MX_M = 201;

int gauss(vector<bitset<MX_M>> a) {
  debug() << imie(a);
  vector<int> where(MX_M, -1);
  for (int col = MX_M - 1, row = 0; col >= 0 && row < MX_N; --col) {
    for (int i = row; i < MX_N; ++i)
      if (a[i][col]) {
        swap(a[i], a[row]);
        break;
      }
    if (!a[row][col])
      continue;
    where[col] = row;

    for (int i = 0; i < MX_N; ++i)
      if (i != row && a[i][col])
        a[i] ^= a[row];
    ++row;
  }

  debug() << imie(a);
  if (where[0] == -1) {
    return 1;
  }
  bool found = 0;
  for (int j = MX_M - 1; j > 0; --j) {
    found |= (a[where[0]][j]);
  }
  return found;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    string S;
    cin >> S;
    vector<bitset<MX_M>> bs(MX_N);
    int f = 0;
    int cnt = 0;
    for (int i = N - 1; i >= 0; i--) {
      for (int j = 0; j < MX_N; j++) {
        bs[j] = (bs[j] << 1) | bitset<MX_M>(((a[i] >> j) & 1));
      }
      cnt++;
      if (S[i] == '1') {
        auto val = gauss(bs);
        // debug() << imie(val);
        if (val == 0) {
          f = 1;
          break;
        }
        for (int j = 0; j < MX_N; j++) {
          bs[j] = bs[j] >> 1;
        }
        cnt--;
      }
    }
    cout << f << '\n';
  }
}
