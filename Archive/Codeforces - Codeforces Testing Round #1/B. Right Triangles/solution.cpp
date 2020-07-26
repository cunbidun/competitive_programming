#include <bits/stdc++.h>
using namespace std;

int n, m, c[1001], r[1001];
char a[1001][1001]; 
long long ans = 0;

int main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
			if (a[i][j] == '*'){
				r[i]++;
				c[j]++;
			}	
		}
	}
	for (int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j ++)
			if (a[i][j] == '*'){
				ans += (r[i]-1)*(c[j]-1);
			}
	}
	cout << ans <<"\n";

}