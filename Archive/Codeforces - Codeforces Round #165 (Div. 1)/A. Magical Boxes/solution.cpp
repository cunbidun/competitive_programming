#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define ll long long

const int MAXA = 1e5 + 10;

int n, Mx = 0;
pair <int, int> a[MAXA];

bool check(int x){
    if (x > Mx + 15) return 1;
    ll currSize = 1LL;
    for(int i = 1; i <= n; i++) {
        int temp = x - a[i].F;
        if(temp > 15) continue;
        ll cur = 1LL;
        while(temp --) {
            cur *= 4;
            if(cur > a[i].S) continue;
        }
        if(cur < a[i].S) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].F >> a[i].S;
        Mx = max(Mx, a[i].F);
    }

    for(int i = 1; i <= 15; i++) {
        if(check(Mx + i)) {
            cout << Mx + i;
            return 0;
        }
    }

    return 0;
}