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
const int MAXA = 1e3 + 10;
const int MOD = 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n;
ii a[MAXA];    
ii clue[MAXA];
vii pointList;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
    clock_t clk = clock();
    #endif

    ios::sync_with_stdio(0); cin.tie(0); 
    
    cin >> n;
    for(int i = 1 ; i <= n; i++) {
        cin >> a[i].F >> a[i].S;
    }
    for(int i = 1 ; i <= n; i++) {
        cin >> clue[i].F >> clue[i].S;
    }
    for(int i = 1; i <= n; i++) {
        rep(j, 1, n) {
            int tempF = a[i].F + clue[j].F;
            int tempS = a[i].S + clue[j].S;
            pointList.pb(ii(tempF, tempS));
        }
    }
    sort(pointList.begin(), pointList.end());
    // rep(i,0,pointList.size() - 1) {
    //     cout << pointList[i].F << " " << pointList[i].S << endl;
    // }
    if(pointList.size() == 1) {
        cout << pointList[0].F << " " << pointList[0].S << endl;
        return 0;
    }
    int cnt = 1;
    rep(i,1,pointList.size() - 1) {  
        if(!(pointList[i].F == pointList[i - 1].F && pointList[i].S == pointList[i - 1].S)) {  
            if(cnt == n) {
                cout << pointList[i - 1].F << " " << pointList[i - 1].S << endl;
                return 0;
            }  
            cnt = 1;
        }
        else cnt++;
        

    }
    #ifndef ONLINE_JUDGE 
    cout << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';
    #endif
    
    return 0;
}