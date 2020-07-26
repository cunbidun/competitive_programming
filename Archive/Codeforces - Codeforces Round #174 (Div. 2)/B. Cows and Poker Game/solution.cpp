#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

#define ll long long
#define pb push_back    

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
string S;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    cin >> n >> S;
    S = '*' + S;
    int ans = n;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(S[i] == 'F') ans --; 
        if(S[i] == 'I') {
            cnt ++;
        }
    }
    if(cnt == 0){
        cout << ans;
        return 0;
    }
    if(cnt == 1) {
        cout << 1;
        return 0;
    }
    else cout << 0;
    return 0;
}