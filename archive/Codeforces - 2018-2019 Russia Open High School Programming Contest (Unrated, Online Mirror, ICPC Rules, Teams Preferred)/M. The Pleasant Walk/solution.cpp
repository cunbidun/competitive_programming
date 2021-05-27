#include <bits/stdc++.h>

using namespace std;
    
#define ll long long
#define pb push_back  
#define F first
#define S second
#define rep(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)  
#define watch(x) cout << (#x) << " = " << (x) << endl

const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;  
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n,k;  
int a[MAXA];
int ans = 1;

int main() {
    #ifndef ONLINE_JUDGE
    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    rep(i, 1, n) {
        cin >> a[i];
    }
    int cnt = 1;
    rep(i, 2, n) {
        if(a[i] == a[i - 1]) {
            cnt = 0;
        }   
        cnt ++;
        ans = max(ans, cnt);

    }
    cout << ans << endl;

    return 0;
}