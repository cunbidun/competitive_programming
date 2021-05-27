/*input

*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int NMAX = 2e5 + 10;
const int MOD = 1e9 + 7;

int n;
string s;
int cnt1 = 1, cnt0 = 1;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == '1') cnt1++;
		else cnt0++;
	}
	if (cnt1 != cnt0) {
		cout << 1 << "\n";
		cout << s;
	}else {
		cout << 2 << "\n";
		cout << s[0] << " ";
		for (int i = 1; i < s.length(); i++) cout << s[i];
	}
}