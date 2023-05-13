
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<int,int,int>
using Graph = vector<vector<int>>;
 
const ll mod = 1000000007;
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll L; cin >> L;
    ll dp[L+1][5];
    ll ans = 2e18;
    ll A[L];
    rep(i,L) cin >> A[i];
    rep(i,L+1){
        rep(j,5) dp[i][j] = 2e18;
    }
    rep(i,5) dp[0][i] = 0;
    rep(i,L){
        ll ec,oc;
        oc = 1-A[i]%2;
        if(A[i]==0) ec = 2;
        else ec = A[i]%2;
        dp[i+1][0] = dp[i][0] + A[i];
        dp[i+1][1] = min(dp[i][0],dp[i][1]) + ec;
        dp[i+1][2] = min({dp[i][1],dp[i][2],dp[i][0]}) + oc;
        dp[i+1][3] = min(dp[i][3],dp[i][2]) + ec;
        dp[i+1][4] = min({dp[i][1],dp[i][2],dp[i][3],dp[i][4]}) + A[i];
    }
    rep(i,5){
        ans = min(ans,dp[L][i]);
    }
    cout << ans << endl;
}
