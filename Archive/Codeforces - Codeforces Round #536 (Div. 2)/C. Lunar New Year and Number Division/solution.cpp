#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define endl "\n"
#define F first
#define S second
#define rf(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
#define rb(i,b,a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) cout << (#x) << " = " << (x) << endl
#define test(t) int(testCnt) = 0; int(t); cin >> (t); while(t -- && ++testCnt)

const int INF = 2e9 + 7;
const int MAXA = 3e5 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;
const double PI = 3.14159265358979323846264;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

ll a[MAXA];
ll ans;
int n;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
//        freopen("in.in", "r", stdin);
    #endif
    cin >> n;
    rf(i,1,n) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    rf(i,1,n/2){
//        cout << i << " " << n - i + 1 << endl;
        ans += (a[i] + a[n - i + 1]) * (a[i] + a[n - i + 1] );
    }
    cout << ans;
    return 0;
}