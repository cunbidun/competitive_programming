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

int n, mx = 0;
stack<int> curr;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        int temp;
        cin >> temp;
        mx = max(mx, temp);
        if(!curr.empty()) {
            if(curr.top() == temp) {
                //cout << i << endl;
                curr.pop();
            }
            else {
                if(curr.top() >= temp)
                    curr.push(temp);
                else {
                    cout << "NO";
                    return 0;
                }
            }
        }
        else {
            curr.push(temp);
            //cout << i << endl;
        }
    }
    int cnt = 0;
    int last;
    while(!curr.empty()) {
        last = curr.top();
        curr.pop();
        cnt ++;
    }
    //cout << cnt << endl;
    if(cnt > 1) cout << "NO";
    else if(cnt == 0) cout << "YES";
    else {
        if(last == mx) 
            cout << "YES";
        else 
            cout << "NO";
    }
}