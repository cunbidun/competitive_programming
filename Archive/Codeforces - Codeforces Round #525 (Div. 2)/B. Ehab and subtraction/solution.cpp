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
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, k;
int a[MAXA];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int track = 0;
    int curr = 1;
    for(int i = 1; i <= k; i++) {
        if(curr >= n + 1) cout << 0 << endl;
        else {
            while(!(a[curr] - track)) curr ++;
            if(curr >= n + 1) {cout << 0 << endl; continue;}
            cout << a[curr] - track << endl;
            track += a[curr] - track;
            curr ++;
        }
    }
    return 0;
}