#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin >> n;
	int ans = 0;
	while(n --) {
		string s;
		cin >> s;
		if(s == "Icosahedron") ans += 20;
		if(s == "Tetrahedron") ans += 4;
		if(s == "Dodecahedron") ans += 12;
		if(s == "Octahedron") ans += 8;
		if(s == "Cube") ans += 6;
	}
	cout << ans << "\n";
	return 0;
}