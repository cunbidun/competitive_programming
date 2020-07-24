#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e6 + 5;
string a, b;
int cnt0[N], cnt1[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
	cin >> a >> b;
  for (int i = 0; i < sz(a); i++) {
    cnt0[i] = cnt0[i - 1];
    if (a[i] == '0') {
      cnt0[i]++;
    }
  }
  
	int cnt = 0;
  for (int i = 0; i < sz(b); i++) {
    if (b[i] == '0')
      cnt++;
  }
	
  int ans = 0;
  for (int i = sz(b) - 1; i < sz(a); i++) {
    int c0 = cnt0[i] - ((i == sz(b) - 1) ? 0 : cnt0[i - sz(b)]);
    if ((c0 + cnt) % 2 == 0) {
      ans++;
    }
  }

  cout << ans << "\n";
}