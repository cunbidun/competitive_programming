#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

#define ll long long
#define pb push_back    
#define watch(x) cout << (#x) << " = " << (x) << endl

const int INF = 1e9 + 7;
const int MAXA = 1e3 + 10;
const int MOD = 1e9 + 7;
const int BL = 1500;

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, a[MAXA];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n; i++) {
        cin >> a[i];
    }
    int ans = INF;
    for(int i = 1; i <= n; i ++) {
        int temp = 0;
        //watch(i);
        for(int j = 1; j <= n; j++) {
            int curr = 0;
            //watch(j);
            curr += abs(i - j);
            curr += j - 1;
            curr += i - 1;
            curr += i - 1;
            curr += j - 1;
            curr += abs(i - j);
            curr *= a[j];
            temp += curr;
        }
        ans = min(ans, temp);
    }   
    cout << ans << endl;
    return 0;
}