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
#define reset(a,v,b) rf(i, 0, b) a[i] = v

const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n;
vii bList, wList;
vector<II> ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    cin >> n;
    rf(i, 1, n) {
        int c, s;
        cin >> c >> s;
        if(c == 1) bList.pb(ii(s,i));
        else wList.pb(ii(s,i));
    }
    int cur = 0;
    int last = 1;
    sort(bList.begin(), bList.end());
    sort(wList.begin(), wList.end());
    if(bList.size() >= wList.size())
        rf(i, 0, bList.size() - 1) {
            while(1) {
                int temp = min(bList[i].F, wList[cur].F);
                ans.pb(II(ii(bList[i].S, wList[cur].S), temp));
                bList[i].F -= temp;
                wList[cur].F -= temp;
                if(!wList[cur].F && wList[cur].F != bList[i].F) {
                    if(cur == wList.size() - 1) break;
                    cur++;
                }
                else if(!wList[cur].F && wList[cur].F == bList[i].F && last) {
                    last = 0;
                    break;
                }
                else if(!wList[cur].F && wList[cur].F == bList[i].F && !last) {
                    if(cur == wList.size() - 1) break;
                    cur++;
                    last = 1;
                }
                else if(!bList[i].F && wList[cur].F != bList[i].F) break;
            }
        }
    else {
        rf(i, 0, wList.size() - 1) {
            while(1) {
                int temp = min(bList[cur].F, wList[i].F);
                ans.pb(II(ii(bList[cur].S, wList[i].S), temp));
                bList[cur].F -= temp;
                wList[i].F -= temp;
                if(!bList[cur].F && bList[cur].F != wList[i].F) {
                    if(cur == bList.size() - 1) break;
                    cur++;
                }
                else if(!bList[cur].F && bList[cur].F == wList[i].F && last) {
                    last = 0;
                    break;
                }
                else if(!bList[cur].F && bList[cur].F == wList[i].F && !last) {
                    if(cur == bList.size() - 1) break;
                    cur++;
                    last = 1;
                }
                else if(!wList[i].F && bList[cur].F != wList[i].F) break;
            }
        }
    }
    rf(i, 0, ans.size() - 1) {
        cout << ans[i].F.F << " " << ans[i].F.S << " " << ans[i].S << endl;
    }
    return 0;
}