#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const ll Mod = 1e9+7;
ll m,n;
ll modPow(ll a, ll b){
	ll res = 1;
	if(b == 1) return a;
	if(b == 0) return 1LL;
	if(b%2 == 1) return (((modPow(a,b/2)*modPow(a,b/2))%Mod)*a)%Mod;
	else return((modPow(a,b/2)*modPow(a,b/2))%Mod);
}
int main() {
	ios_base::sync_with_stdio(0);
	//freopen("in.in","r",stdin);
	cin >> n >> m;
	//cout << modPow(2,10000002) <<endl;
	if(modPow(n,m) == modPow(m,n)) {
		cout << "=";
		return 0;
	}
	if(n == 1) {cout << "<"; return 0;}
	if(m == 1) {cout << ">"; return 0;}
	
	if(n <= 3 && m <= 3) {
		if(m == 3 && n == 2){
			cout << "<";
		}
		if(m == 2 && n == 3){
			cout << ">";
		}
	} 
	else{
		if(n>m) cout << "<";
		else cout << ">";
	}
	return 0;
}