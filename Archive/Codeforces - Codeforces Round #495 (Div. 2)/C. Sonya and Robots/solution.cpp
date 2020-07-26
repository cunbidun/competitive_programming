#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

#define ll long long

const int MAXA = 1e5+5;

int n, a[MAXA], diff[MAXA];
ll ans = 0;
bool used[MAXA], cnt[MAXA];
int main(){
    ios_base::sync_with_stdio(0);
    //freopen("in.txt","r",stdin);
    cin >> n;
    if(n == 1){
        cout << 0;
        return 0;
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cnt[a[n]] = 1;
    diff[n] = 1;
    for(int i = n-1; i >= 1; i--) {
        diff[i] = diff[i+1];
        if(!cnt[a[i]]){
            diff[i] = diff[i+1] + 1;
            cnt[a[i]] = 1;
        }
    }
    //for(int i = 1; i <= n ; i++) { cout << diff[i] << " ";} cout << endl;
    for(int i = 1; i <= n - 1; i++) {
        if(!used[a[i]]){
            used[a[i]] = 1;
            ans+=diff[i+1]; 
        }   
    }
    cout << ans;
    return 0;
}