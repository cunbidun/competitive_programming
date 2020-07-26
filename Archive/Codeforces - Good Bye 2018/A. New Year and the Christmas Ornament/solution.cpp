#include <bits/stdc++.h>

using namespace std;
    
#define ll long long
#define pb push_back  
#define F first
#define S second
#define rep(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)  
#define watch(x) cout << (#x) << " = " << (x) << endl
#define test(t) int(testCnt) = 0; int(t); cin >> (t); while(t -- && ++testCnt) 

    
const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int y,r,b;                            
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
    clock_t clk = clock();
    #endif

    ios::sync_with_stdio(0); cin.tie(0); 
    
    cin >> y >> b >> r;
    if(b <= y && b <= r) {
        if(r > b)
            cout << b  + b + 1 + b - 1;
        else 
            cout << r + r - 1 + r - 2; 
        return 0;
    }
    else if(r <= b  && r <= y) {
        cout << r + r - 1 + r - 2;
    }
    else if(y <= b &&  y <= r) {
        y = min(y, r - 2);
        y = min(y, b - 1);
        cout << y * 3 + 3;
    }
    #ifndef ONLINE_JUDGE
    cout << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';
    #endif
    
    return 0;
}