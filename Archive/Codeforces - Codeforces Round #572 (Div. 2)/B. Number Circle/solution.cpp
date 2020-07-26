/*input

*/
#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010]; 

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if (a[n] >= a[n - 1] + a[n - 2]) {
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++) if (i % 2 == 1) cout << a[i] << " ";
	for (int i = n; i >= 1; i--) if (i % 2 == 0) cout << a[i] << " ";
}