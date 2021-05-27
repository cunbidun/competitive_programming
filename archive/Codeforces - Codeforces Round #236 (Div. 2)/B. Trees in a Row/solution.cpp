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
const int MAXA = 1e3 + 10;
const int MOD = 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
       // freopen("in.in", "r", stdin);
    #endif
    int n, k, a[MAXA];
    cin >> n >> k;
    rf(i, 1, n) cin >> a[i];
    int mn = INF;
    int best;
    rf(i, 1, 1000) {
        int cnt = 0;
        rf(j, 1, n) {
            if(a[j] != i + k * (j - 1)) cnt ++;
        }
        if(cnt < mn) {
            mn = cnt;
            best = i;
        }
    }
    cout << mn<< endl;
    rf(i, 1, n) {
        if(a[i] - (best + (i - 1) * k) == 0) continue;
        if(a[i] > (best + (i - 1) * k)) cout << "- " << i << " " << a[i] - (best + (i - 1) * k) << endl;
        else cout << "+ " << i << " " << (best + (i - 1) * k) - a[i]<< endl;
    }
    return 0;
}