#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <ctime>
    
#define ll long long
#define pb push_back    
#define watch(x) cout << (#x) << " = " << (x) << endl
    
const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;
    
using namespace std;
    
typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;
        
int n, a[MAXA], xmax = 2e5;  
vii numList[2 * MAXA];
int sq[MAXA];   
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    clock_t clk = clock();
    
    for(int a = 1; a <= xmax; a ++) {
        if(2 * a + 1 > xmax) break;
        for(int b = a + 1; (1LL * b * b - 1LL * a * a) <= xmax; b ++) {
            numList[(1LL * b * b - 1LL * a * a)].pb({a,b});
            if ((b - a) > xmax / a) break;
        }
    }

    
    cin >> n;
    
    for(int i = 2; i <= n; i += 2) {
        cin >> a[i];
        if(numList[a[i]].size() == 0) {
            cout << "No";
            return 0;
        }
        for(int j = 0; j < numList[a[i]].size(); j++) {
            // cout << a[i] << endl;
            // cout << numList[a[i]][j].first << " " << numList[a[i]][j].second << endl;
            if (numList[a[i]][j].first > sq[i - 2]) {

                sq[i - 1] = numList[a[i]][j].first;
                sq[i] = numList[a[i]][j].second; 
                break;
            }   
        }
        if(!sq[i - 1]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes" << endl;
    for(int i = 1; i <= n; i ++) {
        cout << 1LL * sq[i] * sq[i] - 1LL * sq[i - 1] * sq[i - 1] << " \n"[i == n];
    }
    cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}