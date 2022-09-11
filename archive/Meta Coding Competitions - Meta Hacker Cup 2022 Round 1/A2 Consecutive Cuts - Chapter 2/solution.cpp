#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int P = 999995749;
// const int P = 10;

struct mod_int {
  int MOD;
  mod_int(int MOD) { this->MOD = MOD; }
  int add(int x, int y) { return ((x + y) >= MOD ? x + y - MOD : x + y); }
  int sub(int x, int y) { return ((x - y) < 0 ? x - y + MOD : x - y); }
  int mul(int x, int y) { return (int)((1LL * x * y) % MOD); }
  int pow(int x, int p) {
    if (p == 0) {
      return 1;
    }
    int t = pow(x, p / 2);
    if ((p & 1) == 1) {
      return mul(mul(t, t), x);
    }
    return mul(t, t);
  }
  int inv(int x) { return pow(x, MOD - 2); }
  int div(int x, int y) { return mul(x, inv(y)); }
};

struct polynomial_rolling_hash {
  vector<int> hash;
  vector<int> ppow;
  int mod;

  polynomial_rolling_hash(vector<int> &a, int p, int _mod) : mod(_mod) {
    int N = a.size();
    hash.assign(N, 0);
    ppow.assign(N, 0);

    hash[0] = a[0];
    ppow[0] = 1;

    for (int i = 1; i < N; i++) {
      ppow[i] = (1LL * ppow[i - 1] * p) % mod;
      hash[i] = (hash[i - 1] + (1LL * ppow[i] * a[i])) % mod;
    }
  }
  int get_hash(int i, int j) {
    assert(i <= j);
    auto mint = mod_int(mod);
    return mint.div(mint.sub(hash[j], (i == 0) ? 0 : hash[i - 1]), ppow[i]);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int N, K;
    cin >> N >> K;
    vector<int> a(N), b(N);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
      cin >> b[i];
      if (b[i] != a[i]) {
        cnt++;
      }
    }
    if (K == 0) {
      if (cnt != 0) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
      continue;
    }
    if (N == 2) {
      if (cnt != 0) {
        if (K % 2 == 0) {
          cout << "NO\n";
        } else {
          cout << "YES\n";
        }
      } else {
        if (K % 2 == 1) {
          cout << "NO\n";
        } else {
          cout << "YES\n";
        }
      }
      continue;
    }
    if (cnt == 0) {
      if (K == 1) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
      continue;
    }
    auto a_p1 = polynomial_rolling_hash(a, P, MOD1);
    auto a_p2 = polynomial_rolling_hash(a, P, MOD2);
    auto b_p1 = polynomial_rolling_hash(b, P, MOD1);
    auto b_p2 = polynomial_rolling_hash(b, P, MOD2);
    // cout << a_p1.hash[1] << '\n';
    // cout << a_p1.get_hash(0, 1) << '\n';
    // cout << b_p1.get_hash(3, 4) << '\n';
    int f = 0;
    for (int i = 0; i < N - 1; i++) {
      auto p11 = (a_p1.get_hash(0, i) == b_p1.get_hash(N - i - 1, N - 1));
      auto p12 = (a_p1.get_hash(i + 1, N - 1) == b_p1.get_hash(0, N - i - 2));

      auto p21 = (a_p2.get_hash(0, i) == b_p2.get_hash(N - i - 1, N - 1));
      auto p22 = (a_p2.get_hash(i + 1, N - 1) == b_p2.get_hash(0, N - i - 2));
      if (p11 && p12 && p21 && p22) {
        f = 1;
      }
    }
    cout << (f ? "YES" : "NO") << '\n';
  }
}
