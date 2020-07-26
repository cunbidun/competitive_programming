#include <iostream>	
#include <algorithm>	

using namespace std;
#define ll long long

ll n;
bool solve(ll a){
	ll curr = n;
	ll cnt = 0;
	while(curr != 0){
		cnt += min(curr,a);
		curr -= min(curr,a);
		curr -= curr/10;
	}
	//cout << cnt << endl;
	if(n%2==0)
		if(cnt >= n/2) return 1;
	if(n%2==1)
		if(cnt>n/2) return 1;
	return 0;
}
int main() {
	ios_base::sync_with_stdio(0);
	//freopen("in.in","r",stdin);
	cin >> n;
	ll l = 1;
	ll r = n;
	ll result;
	while (l <= r) {
  		ll m = (l + r) / 2;
  		//cout << l << " " << r << endl;        
		if (solve(m)) {
		    result = m;
		    r = m - 1;
		  	} 
		else {
	    	l = m + 1;
	  	}
	}
	cout << result << endl;
	return 0;
}