#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define ll long long
#define MAXA 2071
using namespace std;

ll n,a,k,b,ans;
int main(){
    //freopen("inp.inp","r",stdin);
    cin >> n >> k >> a >> b;
    ans = 0;
    if (k == 1) {
    	cout << (a)*(n-1);
    	return 0;
    }

    else {
    	while (n!=1) {
    		if (n<k){
    			ans += a * (n-1);
    			break;
    		}
    		else if(n%k!=0 && n!=1){
    			ll temp = n/k;
    			ans += a*(n-k*temp);
    			n = k*temp; 
    		}
    		else if (n == 1 || n == 0) break;
    		if (b > (a * n / k * (k-1) )){
    			ans += a * n / k * (k-1);
    			n = n / k;
   			}
   			else{
   				n/=k;
   				ans += b;
   			}
   		}
    }
    cout << ans;
}