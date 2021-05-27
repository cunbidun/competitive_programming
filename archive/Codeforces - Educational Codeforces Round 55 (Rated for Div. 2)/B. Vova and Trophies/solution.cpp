#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

#define ll long long
#define pb push_back    

const int INF = 1e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, start[MAXA], finish[MAXA], cnt[MAXA], total;
string S;

int main() {
    //freopen("in.in", "r", stdin);
    cin >> n;
    cin >> S;
    S = 'x' + S;
    memset(start, -1, sizeof(start));
    memset(finish, -1, sizeof(finish));
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        cnt[i] = cnt[i - 1];

        if(S[i] != 'G') {
            start[i] = -1;
            cnt[i] = 0;
        }
        else if(S[i] == 'G') {
            cnt[i] ++;
            total ++;
            if(start[i - 1] == -1) start[i] = i;
            else 
                start[i] = start[i - 1];
        } 
        ans = max(ans, cnt[i]);
    }
    for(int i = n ; i >= 1; i--) {
        if(S[i] != 'G') finish[i] = -1;
        else if(S[i] == 'G') {
            if(finish[i + 1] == -1) finish[i] = i;
            else 
                finish[i] = finish[i + 1];
        } 
    }
    // for(int i = 1; i <= n; i++) {
    //     cout << start[i] << " ";
    // }
    // cout << endl;
    // for(int i = 1; i <= n; i++) {
    //     cout << finish[i] << " ";
    // }
    // cout << endl;
    // cout << cnt[n] << endl;
    // cout << ans << endl;
    if (ans == total) {
        cout << ans;
        return 0;
    }
    else ans ++;
    //cout << ans << endl;
    for(int i = 2; i <= n - 1; i++) {
        if(S[i] == 'S' && S[i - 1] == 'G' && S[i + 1] == 'G') {
            //cout << "i: " << i << endl;
            int temp = finish[i - 1] - start[i - 1] + 1 + finish[i + 1] - start[i + 1] + 1;
            if(total > temp)
                ans = max(ans, temp + 1);
            else 
                ans = max(ans, temp);
        } 
    }
    cout << ans;
}