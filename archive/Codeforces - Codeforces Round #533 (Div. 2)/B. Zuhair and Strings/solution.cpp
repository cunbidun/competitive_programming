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
const int MAXA = 2e5 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;
const double PI = 3.14159265358979323846264;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, k;
string s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
       // freopen("in.in", "r", stdin);
    #endif
    cin >> n >> k;
    cin >> s;
    s = '*' + s;
    int ans = 0;
    rf(i,0,26){
      //int i = 0;{
        int cur = 0;
        int cnt = 0;
        rf(j,1,n) {
            if(s[j] == (char)('a' + i)) {
                if(s[j] == s[j - 1]) {
                    cnt ++;
                   // cout << cnt << endl;
                }
                else {
                    cnt = 1;
                }
            }
            else {
                cur += (cnt / k);
                cnt = 0;
            }
        }
        cur += (cnt / k);
        ans = max(ans, cur);
    }
    cout << ans;
    return 0;
}