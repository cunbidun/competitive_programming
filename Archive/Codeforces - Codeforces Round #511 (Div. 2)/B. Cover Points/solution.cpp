#include <iostream>
#include <algorithm>

using namespace std;

int n ;
int M = -1;
int main() {
	//freopen("in.in","r",stdin);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x, y;
		cin >> x >> y;
		M = max(M,x+y);
	}
	cout << M;
	return 0;
}