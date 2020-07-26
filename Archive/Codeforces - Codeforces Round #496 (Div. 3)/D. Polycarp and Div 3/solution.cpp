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
const int MAXA = 2e5+10;
int n, a[MAXA];
string S;
int main() {
	ios_base::sync_with_stdio(0);
	//freopen("in.in","r",stdin);	 
	cin >> S;
	n = S.length();
	//cout << n << endl;
	for(int i = 0; i < S.length(); i++){
		a[i+1] = (S[i]-'0') % 3;
	}
	// for(int i = 1; i <= n; i++){
	// 	cout << a[i] << " ";
	// }
	// cout << endl;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		//cout << a[i] << endl;
		if (a[i] == 0) {
			ans ++;
			//i++;
		}
		else{
			if(i == n) break;
			if(i == n-1){
				if(a[i+1] == 0 || (a[i]+a[i+1])%3==0) 
					ans++;
				break;
			}
			else{
				if(a[i+1] == 0 || (a[i]+a[i+1])%3==0){
					ans++;
					i++;
					continue;
				}
				if(a[i+2] == 0 || (a[i]+a[i+1]+a[i+2])%3==0 || (a[i+1]+a[i+2])%3==0){
					ans++;
					i+=2;
					continue;
				}
			}
		}
	}
	cout << ans;
	return 0;
}