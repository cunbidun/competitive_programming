#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define ll long long
#define MAXA 2071
using namespace std;

int n,d,ans;
int a[101];
int main(){
   //freopen("inp.inp","r",stdin);
	cin >> n >> d;
	for(int i = 1; i<= n ;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	if (a[n] - a[1] <= d){
		cout << 0 ;
		return 0;
	}
	for(int i = 1; i <= n  ; i++ ){
		int temp;
		for(int j = i+1; j <= n ; j ++ ){
			if ( (a[j] - a[i] > d)){
				temp = j - i ;
				break;
			}
		}
		if (a[n] - a[i] <= d) ans = max(ans, n - i + 1);
		ans = max (ans, temp);
	}
	cout << n - ans;
}