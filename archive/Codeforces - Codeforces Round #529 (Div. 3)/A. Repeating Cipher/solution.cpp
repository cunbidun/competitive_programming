#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <ctime>
#include <string>

#define ll long long
#define pb push_back    
#define watch(x) cout << (#x) << " = " << (x) << endl
    
const int INF = 2e9 + 7;
const int MAXA = 1e3 + 10;
const int MOD = 1e9 + 7;
    
using namespace std;
    
typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n;
string S;
char a[MAXA];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    clock_t clk = clock();
    cin >> n; 
    cin >> S;
    S = '*' + S;
    int curr = 1;
    for(int i = 1; i <= n; i++) {
        if(curr > n) break;
        //cout << i << endl;
        a[curr] = S[i];
        i += curr - 1;   
        curr ++;
    }
    for(int i = 1; i <= curr - 1 ; i++) cout << a[i];
        cout << endl;
    cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}