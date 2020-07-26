#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

#define ll long long

const int MAXA = 1e3+5;

int n, m, a[MAXA], c[MAXA];
int ans;

int main(){
    ios_base::sync_with_stdio(0);
    //freopen("in.txt","r",stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    int pos = 1;
    ans = 0;
    for(int i = 1; i <= n; i++) {
        if(c[i] <= a[pos]){
            ans ++;
            pos ++;
        }
        if(pos > n) break;
    }
    cout << ans;
    return 0;
}