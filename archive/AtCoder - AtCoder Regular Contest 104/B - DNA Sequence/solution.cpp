#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 5e3 + 5;

int n, cntA[N], cntT[N], cntG[N], cntC[N];
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> s;
  s = "*" + s;
  for (int i = 1; i <= n; i++) {
    cntA[i] = cntA[i - 1];
    cntT[i] = cntT[i - 1];
    cntG[i] = cntG[i - 1];
    cntC[i] = cntC[i - 1];
    if (s[i] == 'A') {
      cntA[i]++;
    }
    if (s[i] == 'T') {
      cntT[i]++;
    }
    if (s[i] == 'G') {
      cntG[i]++;
    }
    if (s[i] == 'C') {
      cntC[i]++;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (cntA[i] - cntA[j - 1] == cntT[i] - cntT[j - 1] && cntC[i] - cntC[j - 1] == cntG[i] - cntG[j - 1]) {
        ans++;
      }
    }
  }
  cout << ans << "\n";
}