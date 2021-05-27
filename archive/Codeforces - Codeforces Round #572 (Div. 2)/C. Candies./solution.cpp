/*input

*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, q;
int a[100010];
ll s[100010];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}

	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << (s[r] - s[l - 1]) / 10 << "\n";
	}
}