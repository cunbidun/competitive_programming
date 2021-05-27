#include <iostream>
#include <algorithm>

using namespace std;

const long long  MOD = 998244353;
int n, k;
long long f[1005][2010][4];
int main() {
	//freopen("in.in","r",stdin);
	
	cin >> n >> k;
	f[1][1][0] = 0;
	f[1][1][1] = 0;
	f[1][1][2] = 1;
	f[1][1][3] = 1;
	
	f[1][2][0] = 1;
	f[1][2][1] = 1;
	f[1][2][2] = 0;
	f[1][2][3] = 0;
	
	for(int i = 2; i <= n ; i++){
		for(int j = 1; j <= 2*i; j++) {
			f[i][j][0] = (f[i-1][j][0] + f[i-1][j-2][1] + f[i-1][j-1][2] + f[i-1][j-1][3])%MOD;
			f[i][j][1] = (f[i-1][j][1] + f[i-1][j-2][0] + f[i-1][j-1][2] + f[i-1][j-1][3])%MOD;
			f[i][j][2] = (f[i-1][j][0] + f[i-1][j][1] + f[i-1][j][2] + f[i-1][j-1][3])%MOD;
			f[i][j][3] = (f[i-1][j][0] + f[i-1][j][1] + f[i-1][j-1][2] + f[i-1][j][2])%MOD;	
		}
	}	
	cout << (f[n][k][0] + f[n][k][1] + f[n][k][2] + f[n][k][3])%MOD;
	return 0;
}