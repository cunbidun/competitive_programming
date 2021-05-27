#include <bits/stdc++.h>

#define ll long long
#define pb push_back    

const int INF = 1e9 + 7;
const int MAXA = 1e5 + 5;
const int MOD = 1e9 + 7;

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n;
int a[MAXA];
int cnt[MAXA * 10];
int ans = 0;

int main() {
    //freopen("in.in", "r", stdin);
    cin >> n;
    cnt[0] = 1;
    for(int i = 1; i <= n; i ++) {
    	cin >> a[i];
        vi curr;
        for(int j = 1; j * j <= a[i]; j++) {
            if(a[i] % j == 0){
                curr.pb(j);
                if(j != a[i]/j) curr.pb(a[i]/j);
            }
        }
        sort(curr.begin(), curr.end(), greater<int>());
        for(int i = 0; i < curr.size(); i++) {
            cnt[curr[i]] += cnt[curr[i] - 1];
            cnt[curr[i]] %= MOD;
        }
    }
    for(int i = 1; i <= n; i++) {
        ans += cnt[i];
        ans %= MOD;
    }
    cout << ans;
    return 0;
}