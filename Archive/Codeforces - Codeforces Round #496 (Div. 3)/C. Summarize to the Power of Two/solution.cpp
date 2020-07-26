#include <iostream>	
#include <vector>	
#include <utility>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int>	vi;
map<int,int> check;
const int MAXA = 120005;
int n, a[MAXA], pow2[MAXA];
int main() {
	ios_base::sync_with_stdio(0);
	//freopen("in.in","r",stdin);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		check[a[i]]++;
	}
	pow2[0] = 1;
	for(int i = 1; i <= 31; i++){
		pow2[i] = pow2[i-1]*2;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		bool ok = 0;
		for(int j = 0; j <= 31; j++){
			if(check[pow2[j] - a[i]]) {
				if(pow2[j] - a[i] == a[i] && check[pow2[j] - a[i]] == 1) continue;
				//cout << pow2[j] - a[i] << endl;
				ok = 1;
				break; 
			}
		}
		if(!ok) ans ++;
	}
	cout << ans;
	return 0;
}