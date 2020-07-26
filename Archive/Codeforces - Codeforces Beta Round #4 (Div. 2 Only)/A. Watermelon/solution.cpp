#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	//freopen("in.in","r",stdin);
	int n;
	cin >> n;
	if (n%2 == 0 && n > 2) cout << "YES";
	else cout << "NO";
	return 0;
}