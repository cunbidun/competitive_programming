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
    cin >> n;
    cin >> S;
    S = 'x' + S;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        if(S[i] == '0') ans --;
        else ans ++;
    }
    cout << abs(ans);
    return 0;
}