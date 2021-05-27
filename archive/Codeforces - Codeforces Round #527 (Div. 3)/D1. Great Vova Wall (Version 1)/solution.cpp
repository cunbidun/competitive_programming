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
        temp %= 2;
        if(!curr.empty()) {
            if(curr.top() == temp) {
                curr.pop();
            }
            else curr.push(temp);
        }
        else curr.push(temp);
    }
    int cnt= 0;
    while(!curr.empty()) {
        curr.pop();
        cnt ++;
    }
    //cout << cnt << endl;
    if(cnt > 1) cout << "NO";
    else cout << "YES";
}