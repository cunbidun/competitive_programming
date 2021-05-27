#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std; 

const int MAXN = 2e5+2;

typedef vector<int> vi;

int n, a[104];

int main() {
	ios_base::sync_with_stdio(0);
	//freopen("inp.inp","r",stdin);
	cin >> n;
	for(int i = 1; i <= n/2 ; i ++){
		cin >> a[i];
	}
	sort(a+1,a + n/2 +1);
	int ans = 0;
	int temp = 0;
	for(int i = 1; i <= n/2 ; i ++){
		ans += abs(a[i]-(i*2-1));
	}
	for(int i = 1; i <= n/2 ; i ++){
		temp += abs(a[i]-(i*2));
	}
	cout << min (ans, temp);
	return 0;
}