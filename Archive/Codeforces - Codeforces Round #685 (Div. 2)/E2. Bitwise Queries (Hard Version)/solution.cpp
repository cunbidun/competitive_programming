#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1 << 17;
int n, a[N], x[N];
ii cnt[N];

int ask(string op, int i, int j) {
  cout << op << " " << i << " " << j << endl;
  int res;
  cin >> res;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  int p1 = -1, p2 = -1;
  cnt[0] = {1, 1};
  for (int i = 2; i <= n; i++) {
    x[i] = ask("XOR", 1, i);
    if (p1 != -1) {
      continue;
    }
    if (cnt[x[i]].first == 1) {
      p1 = cnt[x[i]].second;
      p2 = i;
    }
    cnt[x[i]] = {1, i};
  }
  if (p1 != -1) {
    int p = ask("AND", p1, p2);
    a[1] = p ^ x[p1];
  } else {
    int p3 = 0;
    for (int i = 2; i <= n; i++) {
      if (x[i] == n - 1) {
        p2 = 1;
        p3 = i;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i != p2 && i != p3) {
        p1 = i;
        break;
      }
    }
    int a12 = ask("AND", p1, p2);
    int x12 = x[p1] ^ x[p2];
    int a13 = ask("AND", p1, p3);
    int x13 = x[p1] ^ x[p3];
    int a23 = 0;
    for (int i = 0; i <= 16; i++) {
      if (((x12 >> i) & 1) == 0) {
        a[p1] += ((a12 >> i) & 1) << i;
      } else {
        if (((x13 >> i) & 1) == 0) {
          a[p1] += ((a13 >> i) & 1) << i;
        } else {
          a[p1] += (1 - ((a23 >> i) & 1)) << i;
        }
      }
    }
    a[1] = a[p1] ^ x[p1];
  }

  for (int i = 2; i <= n; i++) {
    a[i] = a[1] ^ x[i];
  }
  cout << "!";
  for (int i = 1; i <= n; i++) {
    cout << " " << a[i];
  }
  cout << endl;
}
