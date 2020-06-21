#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int INF = 2e9;

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
  return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
  os << '[';
  for (unsigned int i = 0; i < a.size(); i++)
    os << a[i] << (i < a.size() - 1 ? ", " : "");
  os << ']';
  return os;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  int N = sqrt(n);
  int step = N - 1;
  vi pos;

  for (int i = 1; i <= step; i++) {
    for (int j = i; j < n; j += N) {
      pos.push_back(j);
    }
  }

  // cout << pos << "\n";

  set<int> cur;
  while (true) {
    if (sz(cur) >= sz(pos) - step) {
      cout << 0 << endl;
      return 0;
    }
    vi l;
    for (int i : pos) {
      if (sz(l) == N) {
        break;
      }
      if (cur.find(i) == cur.end()) {
        l.push_back(i);
      }
    }
    for (int i : pos) {
      if (sz(l) == N) {
        break;
      }
      if (cur.find(i) == cur.end()) {
        l.push_back(i);
      }
    }
		
    cout << N << " ";
    for (int i : l) {
      cout << i << " ";
      cur.insert(i);
    }
    cout << endl;

    int rep;
    cin >> rep;
    for (int i = rep; i <= rep + N - 1; i++) {
      if (i > n)
        cur.erase(i - n);
      else
        cur.erase(i);
    }
  }
}