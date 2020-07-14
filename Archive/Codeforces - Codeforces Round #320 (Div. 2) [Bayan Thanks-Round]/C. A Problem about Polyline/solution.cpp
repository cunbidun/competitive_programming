#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int a, b;
double cal(int x) {
  int p = x / b;
  if (p % 2 == 1)
    return (double)x / (p - 1);
  return (double)x / (p);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(15);
  cin >> a >> b;
  if (b > a) {
    cout << -1 << "\n";
    return 0;
  }
  if (a == b) {
    cout << a << "\n";
    return 0;
  }
  cout << min(cal(a - b), cal(a + b)) << "\n";
}