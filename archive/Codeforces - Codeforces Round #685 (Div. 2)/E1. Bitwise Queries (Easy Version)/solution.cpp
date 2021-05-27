#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, a[1 << 17];

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
  int a12 = ask("AND", 1, 2);
  int x12 = ask("XOR", 1, 2);
  int a13 = ask("AND", 1, 3);
  int x13 = ask("XOR", 1, 3);
  int a23 = ask("AND", 2, 3);
  int a1 = 0;
  for (int i = 0; i <= 16; i++) {
    if (((x12 >> i) & 1) == 0) {
      a1 += ((a12 >> i) & 1) << i;
    } else {
      if (((x13 >> i) & 1) == 0) {
        a1 += ((a13 >> i) & 1) << i;
      } else {
        a1 += (1 - ((a23 >> i) & 1)) << i;
      }
    }
  }
  a[1] = a1;
  a[2] = x12 ^ a1;
  a[3] = x13 ^ a1;
  for (int i = 4; i <= n; i++) {
    int x = ask("XOR", 1, i);
    a[i] = x ^ a[1];
  }
  cout << "!";
  for (int i = 1; i <= n; i++) {
    cout << " " << a[i];
  }
  cout << endl;
}
