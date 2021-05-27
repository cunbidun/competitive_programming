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

int n, x, y, d, t;

int main() {
    //freopen("in.in", "r", stdin);
    cin >> t;
    while(t -- ) {
        cin >> n >> x >> y >> d;
        if(abs(x - y) % d == 0) {
            cout << abs(x - y) / d << endl;    
            continue;  
        }
        int ans = INF;
        if((y - 1) % d == 0) {
            ans = min(ans, (y - 1) / d + (x - 1) / d + 1);   
        }
        if((n - y) % d == 0) {
            ans = min(ans, (n - y) / d + (n - x) / d + 1);
        }
        if(ans == INF) cout << "-1" << endl;
        else cout << ans << endl;
    }
}