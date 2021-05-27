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

int vx,vy,hx,hy,n;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    cin >> n;
    rf(i, 1, n) {
        char cmd;
        int h, w;
        cin >> cmd;
        if(cmd == '+') {
            cin >> h >> w;
            if(h > w) swap(h,w);
            vx = max(vx, h);
            vy = max(vy, w);
        }
        else {
            cin >> h >> w;
            if(h > w) swap(h,w);
            if(h >= vx && w >= vy) cout << "YES" << endl;
            //else if(h >= hy && w >= hx)cout << "YES" << endl;
            else cout<<"NO" <<endl;;
        }
    }
    return 0;
}