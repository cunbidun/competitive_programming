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

int n;
ll s, Sum, temp, a[MAXA];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin >> n >> s;
    for(int i = 1;i <= n; i++) {
        cin >> a[i];
        Sum += a[i];
    }
    if(Sum < s) {
        cout << -1;
        return 0;
    }

    sort(a + 1, a + n + 1, greater<int>());
    ll temp = 0;
    for(int i = 1; i <= n; i++) {
        temp = 0;
        for(int j = 1; j <= i - 1; j++) {
            temp += a[j] - a[i];
        }
        if(temp >= s) {
            //watch(temp);
            cout << a[n];
            return 0;
        }
    }
    //watch(temp);
    while(a[n]--) {
        temp += n;
        if(temp >= s) {
            cout << a[n];
            return 0;
        }
    }
    return 0;
}