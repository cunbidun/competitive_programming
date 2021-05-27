#include <bits/stdc++.h>

using namespace std;

int n,m,a;
int main() {
    cin >> n >> m >> a;
    cout << (1LL * (n + a - 1) / a ) * (1LL * (m + a - 1) / a) << "\n";
    // cout << (m + a - 1) / a << "\n";
    return 0;    
}