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
const int MAXA = 1e6 + 10;
const int MOD = 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;
vi numList;
int f[MAXA];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
      //  freopen("in.in", "r", stdin);
    #endif
    string S;
    cin >> S;
    S = 'x' + S;
    int pos = 1, cnt = 0;
    int ans = 0;
    numList.pb(0);
    rf(i, 1, S.size() - 1) {
        if(S[i] == 'F') {
            numList.pb(i);
        }
    }
    f[1] = numList[1] - 1;

    rf(i, 2, numList.size() - 1) {
        if(numList[i] == i) continue;
        f[i] = max(f[i - 1] + 1, numList[i] - i);

    }
    cout << f[numList.size() - 1];
    return 0;
}