#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std; 

#define ll long long
const ll INF = 1e18 + 1;


ll n, h, ans;

ll cal(ll x){
	ll need = x*(x+1)/2;
	ll remain = n - need;
	if(remain % x == 0) return (remain / x + x);
	else return (remain/x+x+1);
}

int main() {
	ios_base::sync_with_stdio(0);
	//freopen("inp.inp","r",stdin);
	cin >> n >> h;
	ll l = 1, r = 2e9;
	while (l != r) {
		ll m = (l+r+1)/2;
		if(m > h){
			if((((m+h)*(m-h+1) + m*(m+1))/2 - m) > n) r = m-1;
			else l = m;
		}
		else{
			if(m*(m+1) > 2*n) r = m-1;
			else l = m;
		}
	}
	if(l > h){
		if(!(n - (((l+h)*(l-h+1) + l*(l+1) )/2 - l))) cout << l-h+l;
		else if ((n - (( (l+h)*(l-h+1) + l*(l+1) )/2 - l)) % l == 0)
			cout << l - h + l + (n - (( (l+h)*(l-h+1) + l*(l+1) )/2 - l))/l;
		else cout << l - h + l + (n - (( (l+h)*(l-h+1) + l*(l+1) )/2 - l))/l+1;
		 
	}
	else{
		cout << cal(l);
	}

	return 0;
}