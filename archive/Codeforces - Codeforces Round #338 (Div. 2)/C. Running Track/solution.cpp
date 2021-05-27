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

string s, sr, t;
vii ans;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
      //freopen("in.in", "r", stdin);
    #endif
    cin >> s >> t;
    sr = s;
    reverse(sr.begin(), sr.end());
   // cout << s << " " << sr << endl;
    rf(j, 0 , t.length() - 1) {
        //cout << j << endl;
        int mx = 0;
        int x = -1, y = -1;

        rf(i, 1, min(s.length(), t.length())) {
            string temp = t.substr(j,i);
            size_t pos = s.find(temp);
            if(i > mx && pos != string::npos) {
                //watch(temp);
                x = pos;
                y = pos + temp.length() - 1;
                mx = i;
                //cout << x << " " << y << endl;
            }
            else if(pos == string::npos) break;
            //if(i == 1 && x == -1) return cout << "-1", 0;
        }
       // cout << mx << endl;
        rf(i, 1, min(s.length(), t.length())) {
            string temp = t.substr(j,i);
            size_t pos = sr.find(temp);
            //cout << sr << " " << temp << endl;
            if(i > mx && pos != string::npos) {
                //watch(temp);
                x = s.length() - pos - 1;
                y = x - temp.length() + 1;
                mx = i;
                //cout << x << " " << y << endl;
            }
            else if(pos == string::npos) break;
        }
        //cout << mx << endl;
        if(mx == 0) return cout << "-1", 0;
        j += mx - 1;
        ans.pb(ii(x,y));
    }
    cout << ans.size() << endl;
    rf(i, 0, ans.size() - 1) {
        cout << ++ ans[i].F  << " " << ++ ans[i].S << endl;
    }
    return 0;
}