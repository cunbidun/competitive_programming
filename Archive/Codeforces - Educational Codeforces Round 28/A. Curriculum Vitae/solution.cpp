#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
#define INF 1e9
int a[MAX];
int n, ans = -INF;
int main() {
	#ifndef ONLINE_JUDGE
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	cin>>n;
	for (int i = 1; i <= n; ++i) cin>>a[i];
	for (int i = 1; i <= n; ++i) {
			int cnt = 0;
			for (int j = 1; j < i; j++)
				if (a[j]) cnt ++;
			for (int j = i+1; j <= n; j++)
				if (!a[j]) cnt ++;
			ans = max(n-cnt, ans);
		}
		cout << ans;
}