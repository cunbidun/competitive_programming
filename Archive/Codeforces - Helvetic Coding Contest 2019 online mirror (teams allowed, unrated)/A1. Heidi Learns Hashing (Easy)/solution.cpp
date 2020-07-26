/*input
4535235
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll r;
int main() {
	cin >> r;
	for (ll i = 1; 1LL * i * i <= r; i++) {
		ll tmp = r - 1LL * i * i - i - 1;
		if (tmp > 0 && tmp % (i * 2) == 0 ) {
			cout << i  << " " << tmp / i / 2 << "\n";
			return 0;
		}
	}
	cout << "NO" << "\n";
	return 0;
}