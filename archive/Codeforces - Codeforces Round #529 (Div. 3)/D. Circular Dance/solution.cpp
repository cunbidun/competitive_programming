#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <ctime>
    
#define ll long long
#define pb push_back    
#define watch(x) cout << (#x) << " = " << (x) << endl
    
const int INF = 2e9 + 7;
const int MAXA = 2e5 + 10;
const int MOD = 1e9 + 7;
    
using namespace std;
    
typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;
       
int n, ans[MAXA];
ii a[MAXA];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    clock_t clk = clock();
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    int curr = 1, filled = 1;
    ans[1] = 1;
    while(filled <= n) {
        int x1 = a[curr].first, x2 = a[curr].second;
        if(a[x1].first == x2 || a[x1].second == x2) {
            ans[filled + 1] = x1;
            ans[filled + 2] = x2; filled += 2;
            curr = x2;
        }
        else {
            ans[filled + 1] = x2;
            ans[filled + 2] = x1; filled += 2;
            curr = x1;
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
    cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}