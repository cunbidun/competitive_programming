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

ii num[1005];
int kx, ky;
bool f[1005][1005];

int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, 1, -1, 1};

bool updateRook() {
    fflush(stdout);
    int k, x, y;
    cin >> k >> x >> y;
    if(k == -1 || k == 0) return 1;
    f[num[k].F][num[k].S] = 0;
    f[x][y] = 1;
    num[k] = ii(x,y);
    return 0;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    cin >> kx >> ky;
    rf(i, 1, 666) {
        int x, y;
        cin >> x >> y;
        f[x][y] = 1;
        num[i] = ii(x,y);
    }
    while(kx < 500) {
        cout << ++kx << " " << ky << endl;
        fflush(stdout);
        if(updateRook()) return 0;
    }
    while(kx > 500) {
        cout << --kx << " " << ky << endl;
        if(updateRook()) return 0;
    }
    while(ky < 500) {
        cout << kx << " " << ++ky << endl;
        if(updateRook()) return 0;
    }
    while(ky > 500) {
        cout << kx << " " << --ky << endl;
        if(updateRook()) return 0;
    }
    int cnt[] = {0,0,0,0,0};
    rf(i, 1, 666) {
        if(num[i].F < 500) {
            if(num[i].S < 500) cnt[1] ++;
            else cnt[2] ++;
        }
        else {
            if(num[i].S < 500) cnt[3] ++;
            else cnt[4] ++;
        }
    }
    int td = 1;
    rf(i,1,4) {
        if(cnt[i] < cnt[td]) td = i;
    }
    td = 5 - td;
    while(1) {
        kx += dx[td - 1];
        ky += dy[td - 1];
        if(f[kx][ky])
            kx -= dx[td - 1];
        cout << kx << " " << ky << endl;
        if(updateRook()) return 0;
    }
}