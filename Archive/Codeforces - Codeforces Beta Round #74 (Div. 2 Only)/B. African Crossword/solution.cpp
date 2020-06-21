#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e2 + 1;
const int INF = 2e9;

int n, m;
char a[N][N];
int cc[N][26], cr[N][26];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      cr[i][a[i][j] - 'a']++;
      cc[j][a[i][j] - 'a']++;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (char c = 'a'; c <= 'z'; c++) {
      if (cr[i][c - 'a'] > 1) {
        for (int j = 1; j <= m; j++) {
          if (a[i][j] == c) {
            a[i][j] = '.';
          }
        }
      }
    }
  }

  for (int i = 1; i <= m; i++) {
    for (char c = 'a'; c <= 'z'; c++) {
      if (cc[i][c - 'a'] > 1) {
        for (int j = 1; j <= n; j++) {
          if (a[j][i] == c) {
            a[j][i] = '.';
          }
        }
      }
    }
  }

	string ans ="";
	for(int i = 1; i<=n;i++){
		for(int j  = 1; j <=m ;j++){
			if(a[i][j]!='.'){
				ans += a[i][j];
			}
		}
	}
	cout << ans << "\n";
}