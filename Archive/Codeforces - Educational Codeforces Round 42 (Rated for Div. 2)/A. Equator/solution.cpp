#include <bits/stdc++.h>

using namespace std;


int n, a[200010];
long long s = 0,sum = 0;
int main() {
    cin >> n;
    for(int i =1; i <= n;i++) {
        cin >> a[i], sum += a[i];
    }
    for(int i =1;i<=n;i++) {
        s+=a[i];
        if(s*2>=sum)return cout << i,0;
}}