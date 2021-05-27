#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

const int MAXA = 1e5+5;
int n, a[MAXA], ans,d;

int main(){
    ios_base::sync_with_stdio(0);
    //freopen("in.txt","r",stdin);
    cin >> n >> d;
    for(int i = 1; i <= n ; i++) {
        cin >> a[i];
    }

    for(int i = 2; i <= n ; i++) {
        if((a[i] - a[i - 1]) > 2*d) ans+=2;
        else if((a[i] - a[i - 1]) == 2*d) ans += 1;
    }
    cout << ans+2;
    return 0;
}