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
const int MAXA = 2e5 + 20;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, gr[MAXA], ans[MAXA],mx,mi;
II a[MAXA];
bool ch[5];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    test(t) {
        cin >> n;
        rf(i, 1, n + 1) {
            a[i].F.F = 0;
            a[i].F.S = 0;
            a[i].S = 0;
            ans[i] = 0;

        }
        ch[1] = 1; ch[2] = 0;
        rf(i, 1, n) {
            cin >> a[i].F.F >> a[i].F.S;
            a[i].S = i;
        }
        sort(a + 1, a + n + 1);
//        rf(i, 1, n) {
//            cout << a[i].F.F << " " << a[i].F.S << endl;
//        }
        ch[1] = 1; ans[a[1].S] = 1; mx = a[1].F.S;
        rf(i, 2, n) {
            if((a[i].F.F > mx)) {
                ans[a[i].S] = 2;
                ch[2] = 1;
            }
            else {
                mx = max(mx, a[i].F.S);
                ans[a[i].S] = 1;
                ch[1] = 1;
            }
        }
        if(ch[1] && ch[2]) {
            rf(i, 1, n) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}