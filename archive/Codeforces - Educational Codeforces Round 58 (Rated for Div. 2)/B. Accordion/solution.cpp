#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
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

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;
string s;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    cin >> s;
    int n = s.length();
    s = '*' + s;
    //cout << s << endl;
    int st = 0, en = 0;
    bool ch1 = 0;
    rf(i, 1, n){
        if(s[i] == '[' && !ch1) ch1 = 1;
        if(s[i] == ':' && ch1) {
            st = i;
            break;
        }
    }
    ch1 = 0;
    rb(i,n,1) {
        if(s[i] == ']' && !ch1) ch1 = 1;
        if(s[i] == ':' && ch1) {
            en = i;
            if(en == st) return cout << -1, 0;
            break;
        }
    }
    //cout << st << " " << en << endl;
    if(st && en && st < en) {
        int ans = 4;
        rf(i,st,en) if(s[i] == '|') ans ++;
        cout << ans;
    }
    else cout << -1;
    return 0;
}