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

int n, num[19], a[19];
int sum = 0;
bool ok;

void bt(int i) {
    if(i == n + 1) {
        sum = 0;
        rf(i, 1, n) {
        if(num[i] == 1)sum += a[i];
        else sum -= a[i];
        }
        if(sum % 360 == 0) {
            ok = 1;
        }
        return;
    }
    num[i] = 1;
    bt(i + 1);
    num[i] = 0;
    bt(i + 1);

}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    cin >> n;
    rf(i,1,n) cin >> a[i];
    bt(1);
    if(ok) cout << "YES";
    else cout << "NO";
    return 0;
}