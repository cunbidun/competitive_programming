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
const int MAXA = 1e5 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;
const double PI = 3.14159265358979323846264;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;
int n;
int a[1502];
int ans = INF,pos;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
      //  freopen("in.in", "r", stdin);
    #endif
    cin >> n;
    rf(i,1,n) cin >> a[i];
    rf(t,1,1000) {
        int cur = 0;
        rf(i, 1, n) {
            if(t == a[i]) continue;
            if(a[i] > t) cur += (a[i] - t - 1);
            else if(a[i] < t) {
                cur += (t - a[i] - 1);
            }
        }
        if(ans > cur) {
            ans = min(cur, ans);
            pos = t;
        }
    }
    cout << pos << " " <<ans;
    return 0;
}