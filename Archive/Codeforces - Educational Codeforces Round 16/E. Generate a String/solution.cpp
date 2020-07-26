#include <iostream>																					

using namespace std;

#define ll long long

ll n, x, y, f[10000001];

ll Min(ll a, ll b){
	return (a <= b) ? a : b;
}

int main(){
	ios_base::sync_with_stdio(0);
	//freopen("inp.inp","r",stdin);
	cin >> n >> x >> y;
	f[1] = x;
	for(int i = 2; i <= n; i++) f[i] = 1e18;
	for(int i = 2; i <= n; i++){
		f[i] = Min(f[i-1] + x, f[i]);	
		if(i % 2 == 0) f[i] = Min(f[i], f[i/2] + y); 
		else f[i] = Min(f[i], f[(i+1)/2]+x+y);
	}
	cout << f[n];
}