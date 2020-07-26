#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> tree[100010];

int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		if (tree[i].size() == 2)
			return cout << "NO", 0;
	cout << "YES" ;
}