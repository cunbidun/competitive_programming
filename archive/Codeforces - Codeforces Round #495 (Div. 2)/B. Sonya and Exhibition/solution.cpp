#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

const int MAXA = 1e5+5;
int n, a[MAXA], ans, m;

int main(){
    ios_base::sync_with_stdio(0);
    //freopen("in.txt","r",stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        if(i & 1) cout << 1;
        else cout << 0;
    }
    return 0;
}