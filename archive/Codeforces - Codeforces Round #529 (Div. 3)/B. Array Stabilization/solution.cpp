#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <ctime>
#include <string>

#define ll long long
#define pb push_back    
#define watch(x) cout << (#x) << " = " << (x) << endl
    
const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;
    
using namespace std;
    
typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, a[MAXA], cnt[MAXA];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    clock_t clk = clock();
    cin >> n; 
    for(int i = 1; i <= n; i++) {
            cin >> a[i];
            cnt[a[i]] ++;
    }
    sort(a + 1, a + n + 1);
    
    if(cnt[a[1]] > 1 && cnt[a[n]] > 1) 
        cout << (a[n] - a[1]);
    else if(cnt[a[1]] == 1 && cnt[a[n]] > 1) {
        cout  << min(abs(a[n] - a[2]), abs(a[1] - a[n]));
    }
    else if(cnt[a[1]] > 1 && cnt[a[n]] == 1) {
        cout << min(abs(a[n - 1] - a[1]), abs(a[n] - a[1]));
    }
    else {
        cout << min(abs(a[n] - a[2]), abs(a[1] - a[n - 1]));
    }
    cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}