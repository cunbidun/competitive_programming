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
const int MAXA = 5e5 + 10;
const int MOD = 1e9 + 7;
    
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, k, d, a[MAXA];
int fenwickTree[MAXA];
bool f[MAXA];       
// f[i] = 1 if we can properly distribute first i - 1 pencils
void update(int pos) {
    while(pos <= n + 1) {
        fenwickTree[pos] ++;
        pos += pos & -pos;
    }
}

int getSum(int pos) {
    int ans = 0;
    while(pos > 0) {
        ans += fenwickTree[pos];
        pos -= pos & (-pos);
    }
    return ans;
}
int rangeSum(int l, int r) {
    if(l > r) return 0;
    return(getSum(r) - getSum(l - 1));
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    clock_t clk = clock();
    cin >> n >> k >> d;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = 0;
    }
    sort(a + 1, a + n + 1);
    f[1] = 1;
    update(1);
    int cur = 1;
    for(int i = 1; i <= n; i++) {
        while(((a[i] - a[cur]) > d) && cur < i) {
            cur ++;
        }
        if(rangeSum(cur, i - k + 1) >= 1) {
            f[i + 1] = 1;
            update(i + 1);
        }
    }
    if(f[n + 1]) cout << "YES" << endl;
    else cout << "NO" << endl;
    cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}