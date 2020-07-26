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

int n;
float ans = 0, S;
int cnt[MAXA];
int dis(int a, int b, int c, int d){
    return abs(a - c) + abs(b - d) - 1;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    cin >> n >> S; 

    for(int i = 1; i <= n - 1; i ++) {
        int u, v; 
        cin >> u >> v;
        cnt[u] ++;
        cnt[v] ++;
    }
    for(int i = 1; i <= n; i++) {
        if(cnt[i] == 1) {
            ans++;
        }
    }
    S *= 2;
    cout << fixed << setprecision(7) << (float) (S / ans) << endl;
}