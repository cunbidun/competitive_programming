#include <bits/stdc++.h>

using namespace std;
	
#define ll long long
#define pb push_back  
#define F first
#define S second
#define rep(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)  
#define watch(x) cout << (#x) << " = " << (x) << endl

const int INF = 2e9 + 7;
const int MAXA = 1e3 + 10;
const int MOD = 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n;	
int cnt[MAXA];	
vi adjList[MAXA];

int main() {
    #ifndef ONLINE_JUDGE
    //freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    rep(i, 2, n) {
        int temp;
        cin >> temp;
        adjList[temp].pb(i);
    }  

    rep(i, 1, n) {
        if(adjList[i].size()) {
            rep(j,0,adjList[i].size() - 1) {
                int v = adjList[i][j];
                if(adjList[v].size() == 0) {
                    cnt[i] ++ ;
                }
            }
        }
    }
    rep(i, 1, n) {
        if(adjList[i].size()){
            if(cnt[i] < 3) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}