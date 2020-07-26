#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <utility>

#define ll long long
#define pb push_back    
#define watch(x) cout << (#x) << " = " << (x) << endl

const int INF = 1e9 + 7;
const int MAXA = 2e3 + 10;
const int MOD = 1e9 + 7;

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, cntS, cntP;
string S[MAXA];
string temp[4];
string s;
char ans[MAXA];
bool check[MAXA];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin >> n;
    if(n == 2) {
        cout << "SP";
        return 0;
    }
    int cnt = 1;
    for(int i = 1; i <= 2 * n - 2; i++) {
        ans[i] = 'E';
        cin >> S[i];
        if(S[i].length() == n - 1) {
            temp[cnt] = S[i];
            cnt ++;
        }
    }

    //watch(temp[1]); watch(temp[2]);

    bool okay = 0;
    for(int i = 1; i < temp[1].size(); i++) {
        if(temp[1][i] != temp[2][i - 1]) {
            s = temp[2][0] + temp[1];
            okay = 1;
            break;
        }
    }

    //watch(okay);

    if(!okay) s = temp[1][0] + temp[2];

    //cout << s << endl;
    okay = 1;
    for(int i = 1; i <= 2 * n - 2; i++) {
        for(int j = 0; j < S[i].length(); j++) {
            if(S[i][j] != s[j]) {
                okay = 0;
                break;
            }
        }

        if(!okay) {
            okay = 1;
            for(int j = 0; j <= S[i].length() - 1; j--) {
                if(S[i][S[i].length() - 1 - j] != s[n - 1 - j]) {
                    okay = 0;
                    break;
                }
            }
        }
        if(!okay) break;
    }
    
    if(!okay) s = temp[2][0] + temp[1];
    //cout << s << endl;

    for(int i = 1; i <= 2 * n - 2; i++) {
        bool ok = 1;
        // watch(S[i]);
        for(int j = 0; j < S[i].length(); j++) {
            if(S[i][j] != s[j]) {
                ok = 0;
                break;
            }
        }
        if(!ok) {
            ans[i] = 'S';
            cntS ++;
            //cout <<"S"; watch(i);
            // cout << endl;
        }
        else {
            ok = 1;
            for(int j = 0; j <= S[i].length() - 1; j--) {
                if(S[i][S[i].length() - 1 - j] != s[n - 1 - j]) {
                    ok = 0;
                    break;
                }
            }
            if(!ok) {
                ans[i] = 'P';
                check[S[i].length()] = 1;
                //watch(i);
                cntP++;
            }
            // cout << endl;
        }
    }
    // watch(cntP);
    // watch(cntS);
    cntP = n - 1 - cntP;
    cntS = n - 1 - cntS;
    // watch(cntP);
    // watch(cntS);
    // for(int i = 1; i <= 2*n-2; i++) {
    //     cout << ans[i];
    // }
    // cout << endl;
    for(int i = 1; i <= 2 * n - 2; i++) {
        if(ans[i] == 'E') {
            if(cntP && !check[S[i].length()]) {
                ans[i] = 'P';
                check[S[i].length()] = 1;
                cntP --;
            }
            else ans[i] = 'S';
                
        }
    }

    for(int i = 1; i <= 2*n-2; i++) 
        cout << ans[i];
    return 0;
}