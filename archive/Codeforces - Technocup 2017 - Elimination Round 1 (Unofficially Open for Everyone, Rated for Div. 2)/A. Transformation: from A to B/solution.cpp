#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>
#include <stack>

using namespace std;

const int INF = 1e9;

int a, b;

map <int, int> step;
stack <int> ans;

// int dfs(int x){
// 	if(!step[x]) step[x] = INF; 
// 	if (step[x] = INF &&((x%2 == 1 && x%10 != 1) || x < a)) return step[x] = -1;
// 	ans.push(x);
// 	if(x == a) return step[a] = 1;
// 	if(x%2 == 0){
// 		int temp = dfs(x/2);
// 		if(temp != -1)
// 			return step[x] = min(step[x], temp + 1);
// 	}
// 	else if(x % 10 == 1){
// 		int temp = dfs(x/10);
// 		if(temp != -1)
// 			return step[x] = min(step[x], temp + 1);
// 	}
// }
int main() {
	ios_base::sync_with_stdio(0);
	//freopen("inp.inp","r",stdin);
	cin >> a >> b;
	//dfs(b);
	ans.push(b);
	while (b>a) {
		if(b%2 == 0) {
			ans.push(b/2);
			b/=2;
		}
		else if(b%10 == 1) {
			ans.push(b/10);
			b/=10;
		}
		else if(b%2 == 1 && b%10 != 1) {
			cout << "NO";
			return 0;
		}
	}
	if(b < a) {
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;
	cout << ans.size() << endl;
	while (!ans.empty()) {
	    cout << ans.top() << " ";
	    ans.pop();
	}
	return 0;
}