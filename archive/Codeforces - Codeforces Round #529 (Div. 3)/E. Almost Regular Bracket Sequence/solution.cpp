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
const int MAXA = 1e6 + 10;
const int MOD = 1e9 + 7;
    
using namespace std;
    
typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

string S;
int n, ans = 0, sum[MAXA];
int sTree[4 * MAXA], lazyUpdate[4 * MAXA];
void buildTree(int nodeID, int l, int r) {
    if(l > r) return;
    int m = (l + r) >> 1;
    if(l == r) {
        sTree[nodeID] = sum[l];
        return;
    }
    buildTree(nodeID * 2, l, m);
    buildTree(nodeID * 2 + 1, m + 1, r);
    sTree[nodeID] = min(sTree[nodeID * 2], sTree[nodeID * 2 + 1]);
}

void trueVal(int nodeID, int l, int r) {
    if(l > r || lazyUpdate[nodeID] == 0) return;
    sTree[nodeID] += lazyUpdate[nodeID];
    if(l != r) {
        lazyUpdate[nodeID * 2] += lazyUpdate[nodeID];
        lazyUpdate[nodeID * 2 + 1] += lazyUpdate[nodeID];
    }
    lazyUpdate[nodeID] = 0;
}

void updateTree(int nodeID, int l, int r, int tarL, int tarR, int val) {
    trueVal(nodeID, l, r);  
    if(tarR < l || r < tarL || r < l) return;
    if(tarL <= l && r <= tarR){
        sTree[nodeID] += val;
        if(l != r) {
            lazyUpdate[nodeID * 2] += val;
            lazyUpdate[nodeID * 2 + 1] += val;
        }
        return;
    }
    int m = (l + r) >> 1;
    updateTree(nodeID * 2, l, m, tarL, tarR, val);
    updateTree(nodeID * 2 + 1, m + 1, r, tarL, tarR, val);
    sTree[nodeID] = min(sTree[nodeID * 2], sTree[nodeID * 2 + 1]);
}

int getMin(int nodeID, int l, int r, int tarL, int tarR) {
    trueVal(nodeID, l, r);
    if(tarR < l || r < tarL || r < l) return INF;
    int m = (l + r) >> 1;
    if(tarL <= l && r <= tarR) return sTree[nodeID];
    return min(getMin(nodeID * 2, l, m, tarL, tarR), getMin(nodeID * 2 + 1, m + 1, r, tarL, tarR));
}                              
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    clock_t clk = clock();
    cin >> n;
    cin >> S;
    S = 'x' + S;
    for(int i = 1; i <= n; i++) {
        if(S[i] == '(') sum[i] = sum[i - 1] + 1;
        if(S[i] == ')') sum[i] = sum[i - 1] - 1;    
        if(sum[i] < -2) {
            cout << 0;
            return 0;
        }
    }
    if(sum[n] % 2 == 1) {
        cout << 0;
        return 0;
    } 
    buildTree(1,1,n);
    for(int i = 1; i <= n; i++) {
    	if(S[i] == '(') {
    	    updateTree(1,1,n,i,n,-2);
	        if(sum[n] == 2 && getMin(1,1,n,1,n) == 0) {
	            ans ++;
	        }
	        updateTree(1,1,n,i,n,2);
	    }
	    else {
	    	updateTree(1,1,n,i,n,2);
	        if(sum[n] == -2 && getMin(1,1,n,1,n) == 0) {
	            ans ++;
	        }
	        updateTree(1,1,n,i,n,-2);
	    }
    }
    cout << ans << endl;
    cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}