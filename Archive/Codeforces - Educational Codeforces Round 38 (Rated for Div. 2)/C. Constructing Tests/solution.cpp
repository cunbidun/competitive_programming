#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define ll long long
#define MAXA 2071
using namespace std;

bool check(ll x){
	ll temp = sqrt(x);
	if (temp * temp == x) return 1; else return 0;
}
ll valid(ll n, ll m){
	ll temp = (n/m);
	return n*n - temp*temp;
}

int main(){
    //freopen("inp.inp","r",stdin);
	ll t;
	cin >> t;
	while (t--) {
		ll n, m, x;
		bool ch = 0;
		cin >> x;
		n = sqrt(x) + 1;
		//cout << n << endl;
		for (ll i = n ; i <= 1000000; i++){
			long long X = (i*i - x);
			if (check(X)) {
				ll temp = sqrt(X);
				m = i / temp;
			}
			else 
				continue;

			if (valid(i,m) == x) {
				cout << i << " " << m << endl;
				ch = 1;
				break;
			}	
		}
		if (!ch)cout << "-1" << endl;
	}
}