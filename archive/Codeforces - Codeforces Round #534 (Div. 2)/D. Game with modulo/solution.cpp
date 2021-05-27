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
const int MAXA = 1e5 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;
const double PI = 3.14159265358979323846264;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int a = 1, cnt = 0;
int ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
#ifndef ONLINE_JUDGE
    cnt ++;
    if(cnt > 60) {
        cout << "wrong answer too many queries asked";
        exit(0);
    }
    if(x % a >= y % a)
        return x;
    else
        return y;
#endif
    string tmp;
    cin >> tmp;
    if(tmp[0] == 'e')
        exit(0);
    if (tmp[0] == 'x')
        return x;
    else
        return y;
}

void ans(int x) {
    cout << "! " << x << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
#endif // ONLINE_JUDGE
    while (1) {
        string cmd;
        cin >> cmd;
        if (cmd[0] != 's')
            return 0;
#ifndef ONLINE_JUDGE
        cin >> a;
#endif
        if (ask(0, 1) == 0) {
            ans(1);
            continue;
        }
        int cur = 1;
        while (1) {
            if (ask(cur, cur * 2) == cur)
                break;
            cur *= 2;
        }
        int l = cur + 1, r = 2 * cur;
        if(l == r) {
            ans(l);
            continue;
        }
        while (l != r) {
            if (l == r - 1) {
                if (ask(cur, l) == l) {
                    ans(r);

                } else {
                    ans(l);
                }
                break;
            }
            int m = (l + r) >> 1;
            if (ask(cur, m) == m) {
                l = m + 1;
            } else {
                r = m;
            }
        }
    }
    return 0;
}