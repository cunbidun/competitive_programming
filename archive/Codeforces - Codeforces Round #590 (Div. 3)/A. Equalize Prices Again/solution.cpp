#include<bits/stdc++.h>
using namespace std;

int q, n, a[101 ];
int main() {
    cin >> q;
    while(q--) {
        cin >> n;
        int s = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            s += a[i];
        }
        cout << (s + n - 1) / n << "\n";
    }

    return 0;
}