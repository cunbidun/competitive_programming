#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>

#define ll long long
#define pb push_back    
#define watch(x) cout << (#x) << " = " << (x) << endl

const int INF = 1e9 + 7;
const int MAXA = 2e5 + 10;
const int MOD = 1e9 + 7;

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n;
vii ans;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        //cout << i << endl;
        string temp;
        cin >> temp;
        if (temp == "insert" ) {
            int val;
            cin >> val;
            pq.push(val);
            ans.pb(ii(1,val));
        }
        if (temp == "getMin") {
            int val;
            cin >> val;
            while(!pq.empty()) {
                int f = pq.top();
                if(f < val) {
                    ans.pb(ii(3,0));
                    pq.pop();
                }
                else break;
            }
            if(pq.empty() || pq.top() > val) {
                pq.push(val);
                ans.pb(ii(1,val));
                ans.pb(ii(2,val));
            }
            else {
                ans.pb(ii(2,val));
            }
        }
        if(temp == "removeMin") {
            if(pq.empty()) {
                ans.pb(ii(1,0));
                pq.push(0);
            }
            pq.pop();
            ans.pb(ii(3,0));
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i].first == 1) {
            cout << "insert " << ans[i].second << endl;
        }
        else if(ans[i].first == 2) {
            cout << "getMin " << ans[i].second << endl;
        }
        else cout << "removeMin" << endl;
    }
}