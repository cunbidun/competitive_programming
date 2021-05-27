#include <iostream>	
#include <vector>	
#include <utility>
#include <cstdio>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int>	vi;

int a[1001], ans, ch[1001];
int main() {
	ios_base::sync_with_stdio(0);
	//freopen("in.in","r",stdin);
	int n;
	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] <= a[i-1]){
			ch[i-1]=1;
			ans++;
		}
	}
	cout << ans+1 << endl;
	for(int i = 1; i< n; i++) if(ch[i]) cout << a[i] << " ";\
	cout << a[n];
	return 0;
}