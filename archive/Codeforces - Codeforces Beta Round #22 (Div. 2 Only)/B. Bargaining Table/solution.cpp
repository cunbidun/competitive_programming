#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define F first
#define S second
#define rf(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
#define rb(i,b,a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) cout << (#x) << " = " << (x) << endl
#define test(t) int(testCnt) = 0; int(t); cin >> (t); while(t -- && ++testCnt) 

const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m;
char a[30][30];
int f[30][30][30][30];
int ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    cin >> n >> m;

    rf(i, 1, n) 
    	rf(j, 1, m) {
            cin >> a[i][j];
    	    if(a[i][j] == '0') {
                ans = 4;    
                f[i][j][i][j] = 1;
            }
        }
    
    if(ans != 4) return cout << 0, 0;

    rf(i, 1, n)
    	rf(j, 1, m) {
    		rf(l, 1, i) {
                rf(k, 1, j) {
                    if(i == l && j == k) continue;
                    if(a[i][j] == '0' && a[l][k] == '0'){
                        //cout << i << " " << j << " " << l <<" " <<k << endl;
                        if(i == 1) {
                            if(f[i][j - 1][l][k]) {
                                f[i][j][l][k] = 1;
                                //cout << i << " " << j << " " << l <<" " <<k << endl;
                                ans = max(2 * (i - l + 1 + j - k + 1), ans);
                            }
                            continue;
                        }
                        if(j == 1) {
                            if(f[i - 1][j][l][k]) {
                                f[i][j][l][k] = 1;
                                //cout << i << " " << j << " " << l <<" " <<k << endl;
                                ans = max(2 * (i - l + 1 + j - k + 1), ans);
                            }
                            continue;
                        }
                        if((l == i || f[i - 1][j][l][k]) &&  (j == k || f[i][j - 1][l][k])){
                            f[i][j][l][k] = 1;
                            //cout << i << " " << j << " " << l <<" " <<k << endl;
                            ans = max(2 * (i - l + 1 + j - k + 1), ans);
                        }
                    } 
                }
            }
    	}
    cout << ans;
    return 0;
}