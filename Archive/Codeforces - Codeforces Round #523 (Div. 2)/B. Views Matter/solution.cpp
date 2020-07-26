#include <iostream>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <functional> 
#include <queue>
#include <string>

using namespace std;

#define ll long long
#define INF 1000000007

const int MAXA = 1e5+5;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m;
ll ans;
int a[MAXA];

int main() {
    //freopen("in.in","r",stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
    	cin >> a[i];
    }
    sort(a+1, a+n+1);
    if(n == 1) {
    	cout << 0;
    	return 0;
    }
    int curr = 1;
    for(int i = 1; i <= n-1; i++) {
    	if(a[i] > 1) ans += a[i] - 1;
    	curr = min(curr + 1, a[i]);
  		curr = min(curr, i);		
    	//cout << i << " " << curr << " " << a[i] << endl;
    }
    // cout << ans << endl;
    // cout << curr << endl
    ans += min(curr, a[n] - 1);
    cout << ans;
    return 0;
}