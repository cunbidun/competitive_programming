#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <functional> 
#include <queue>
#include <string>
#include <iomanip>  

#define ll long long
#define pb push_back    
#define watch(x) cout << (#x) << " = " << (x) << endl

const int INF = 1e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int xa, xb, xc, ya, yb, yc;
vii ans;
ii pos;

int dis(int a, int b, int c, int d){
    return abs(a - c) + abs(b - d) - 1;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    cin >> xa >> ya;
    cin >> xb >> yb;
    cin >> xc >> yc;
    cin >> xa >> ya;
    int Mn = INF;
    for(int i = 0; i <= 1000; i++) {
        for(int j = 0; j <= 1000; j++) {
            if(Mn > (dis(i, j, xa, ya) + dis(i, j, xb, yb) + dis(i, j, xc, yc))) {
                pos = ii(i, j);
                Mn = (dis(i, j, xa, ya) + dis(i, j, xb, yb) + dis(i, j, xc, yc));
            }
        }
    }
    if((xa <= pos.first && ya <= pos.second) || (xa >= pos.first && ya >= pos.second)) {
        for(int i = min(xa,pos.first); i <= max(xa, pos.first); i++) {
            ans.pb(ii(i, min(ya, pos.second)));
        }
        for(int i = min(ya, pos.second); i <= max(ya, pos.second); i++) {
            ans.pb(ii(max(xa,pos.first), i));
        }
    }
    else {
        for(int i = min(xa,pos.first); i <= max(xa, pos.first); i++) {
            ans.pb(ii(i, min(ya, pos.second)));
        }
        for(int i = min(ya, pos.second); i <= max(ya, pos.second); i++) {
            ans.pb(ii(min(xa,pos.first), i));
        }
    }
    if((xb <= pos.first && yb <= pos.second) || (xb >= pos.first && yb >= pos.second)) {
        for(int i = min(xb,pos.first); i <= max(xb, pos.first); i++) {
            ans.pb(ii(i, min(yb, pos.second)));
        }
        for(int i = min(yb, pos.second); i <= max(yb, pos.second); i++) {
            ans.pb(ii(max(xb,pos.first), i));
        }
    }
    else {
        for(int i = min(xb,pos.first); i <= max(xb, pos.first); i++) {
            ans.pb(ii(i, min(yb, pos.second)));
        }
        for(int i = min(yb, pos.second); i <= max(yb, pos.second); i++) {
            ans.pb(ii(min(xb,pos.first), i));
        }
    }
    if((xc <= pos.first && yc <= pos.second) || (xc >= pos.first && yc >= pos.second)) {
        for(int i = min(xc,pos.first); i <= max(xc, pos.first); i++) {
            ans.pb(ii(i, min(yc, pos.second)));
        }
        for(int i = min(yc, pos.second); i <= max(yc, pos.second); i++) {
            ans.pb(ii(max(xc,pos.first), i));
        }
    }
    else {
        for(int i = min(xc,pos.first); i <= max(xc, pos.first); i++) {
            ans.pb(ii(i, min(yc, pos.second)));
        }
        for(int i = min(yc, pos.second); i <= max(yc, pos.second); i++) {
            ans.pb(ii(min(xc,pos.first), i));
        }
    }
    ans.pb(ii(xa,ya));
    ans.pb(ii(xb,yb));
    ans.pb(ii(xc,yc));
    sort(ans.begin(), ans.end());
    int cnt = 1;
    for(int i = 1; i < ans.size(); i++) {
        if(ans[i].first == ans[i - 1].first && ans[i].second == ans[i - 1].second) {
            continue;
        }
        cnt ++;
    }
    cout << cnt << endl;
    cout << ans[0].first << " " << ans[0].second << endl;
    for(int i = 1; i < ans.size(); i++) {
        if(ans[i].first == ans[i - 1].first && ans[i].second == ans[i - 1].second) {
            continue;
        }
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}