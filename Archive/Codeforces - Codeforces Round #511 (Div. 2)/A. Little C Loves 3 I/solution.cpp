#include <iostream>
#include <algorithm>

using namespace std;

const long long  MOD = 998244353;
int n, k;
long long f[1005][2010][4];
int main() {
//	freopen("in.in","r",stdin);
	
	cin >> n;
	if(n%3==0){
		cout << 1 << " " << 1 << " " << n-2;
	}
	else if (n%3==1){
		cout << 1 << " " << 1 << " " << n-2;
	}
	else if (n%3==2){
		cout << 2 << " " << 1 << " " << n-3;
	}
	return 0;
}