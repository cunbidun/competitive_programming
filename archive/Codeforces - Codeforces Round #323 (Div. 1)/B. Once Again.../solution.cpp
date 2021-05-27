#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

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

int n, T;
int a[101];
int f[101][101];
vi l;
map<int, int> mp;
void compress() {
  sort(all(l));
  l.resize(distance(l.begin(), unique(all(l))));
  for (int i : l)
    mp[i] = sz(mp) + 1;
}

void mul(int A[101][101], int B[101][101]) {
  int C[101][101];
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      C[i][j] = 0;
      for (int k = i; k <= j; k++) {
        C[i][j] = max(C[i][j], A[i][k] + B[k][j]);
      }
    }
  }
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      if (i > j)
        A[i][j] = 0;
      else
        A[i][j] = C[i][j];
    }
  }
}

void bin_pow(int A[101][101], int p) {
  if (p == 1)
    return;
  int C[101][101];
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      if (i > j)
        C[i][j] = 0;
      else
        C[i][j] = A[i][j];
    }
  }
  bin_pow(C, p / 2);
  mul(C, C);
  if (p % 2 == 1)
    mul(C, A);
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      if (i > j)
        A[i][j] = 0;
      else
        A[i][j] = C[i][j];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> T;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    l.push_back(a[i]);
  }
  compress();
  for (int i = 1; i <= n; i++) {
    a[i] = mp[a[i]];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      vi tmp;
      tmp.push_back(0);
      for (int k = 1; k <= n; k++) {
        if (a[k] >= i && a[k] <= j) {
          tmp.push_back(a[k]);
        }
      }
      vi arr(n + 1);
      arr[1] = 1;
      int res = 1;
      for (int k = 2; k < sz(tmp); k++) {
        int cur = 0;
        for (int x = 1; x < k; x++) {
          if (tmp[k] >= tmp[x]) {
            cur = max(cur, arr[x]);
          }
        }
        arr[k] = cur + 1;
        res = max(res, arr[k]);
      }
      f[i][j] = res;
    }
  }
  bin_pow(f, T);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans = max(ans, f[i][j]);
    }
  }
  cout << ans << "\n";
}