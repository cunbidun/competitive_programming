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

int n, total;
map<int,int> cnt;
map<int,bool> ch;
int mx = 0;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    cin >> n;
    vi a(n + 1);
    a[0] = -1;
    rf(i, 1, n) {
        cin >> a[i];
        if(a[i] != a[i - 1] && !ch[a[i]]) {
            ch[a[i]] = 1;
            total ++;
        }
        cnt[a[i]] ++;
    }
//    cout << total << endl;
    rf(i, 1, a.size() - 1) {
        if(a[i] == a[i - 1]) continue;
        int temp = cnt[a[i]];
        if(temp != 0) {
            cnt[a[i]] = 0;
            ch[a[i]] = 0;
            total --;
        }
        for(int j = 0; (1 << j) <= temp; j++) {
            if((temp >> j) & 1) {
                cnt[a[i] + j] += 1;
                if(!ch[a[i] + j]) {
                    total ++;
                    ch[a[i] + j] = 1;
                }
                if(cnt[a[i] + j] > 1) a.pb(a[i] + j);
                //cout << "+ " << a[i] + j << endl;
                mx = max(mx, a[i] + j);
            }
        }
    }
//    cout << mx << endl;
//    cout << total << endl;
    cout << mx - total + 1;
    return 0;
}