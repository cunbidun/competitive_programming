#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

#define ll long long
#define pb push_back    

const int INF = 1e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, k;
int ans = 0;

bool cal(int temp) {
    int cnt = 0;
    while(temp) {
        if(temp % 10 == 4 || temp % 10 == 7) cnt ++;
        temp /= 10;
    }
    if(cnt <= k) return 1;
    return 0;
}

int main() {
    //freopen("in.in", "r", stdin);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        if(cal(temp)) ans ++;
    }
    cout << ans;
    return 0;
}