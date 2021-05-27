#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std; 

const int MAXN = 2e5+2;

typedef vector<int> vi;

int n, m, OK[2001], ans = 0;
char a[2001][2001];
vector<int> check[2001];
int main() {
	ios_base::sync_with_stdio(0);
	//freopen("inp.inp","r",stdin);
	cin >> n >> m;
	for(int i = 1; i <= n ; i ++)
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
			if(a[i][j] == '1') {
				check[j].push_back(i);
			}
		}

	for(int j = 1; j <= m; j++){
		if(check[j].size() == 1) {
			OK[check[j][0]] = 1;
		}
	}
	for(int i = 1; i <= n; i++){
		if(OK[i]) ans ++;
	}
	//cout << ans << endl;
	if(ans < n) cout << "YES";
	else cout << "NO";
	return 0;
}