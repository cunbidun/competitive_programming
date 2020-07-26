#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <functional> 
#include <queue>
#include <string>

#define ll long long
#define pb push_back    
#define watch(x) cout << (#x) << " = " << (x) << endl

const int INF = 1e9 + 7;
const int MAXA = 3162278;
const int MOD = 1e9 + 7;

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

string S;
char ans[2000];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin >> S;
    int pos;
    if(S.length() % 2 == 0) {
        ans[1] = S[S.length()/2 - 1];
        pos = S.length()/2 - 1;
    }
    else {
        ans[1] = S[S.length()/2];
        pos = S.length()/2 ;
    }
    int cur = 2;
    int dir = 1;
    for(int i = 1; i <= S.length(); i++) {
        if(pos + i * dir >= S.length()) break;
        //cout << pos + i * dir << endl;
        ans[cur] = S[pos + i * dir];
        if(dir == 1) dir = -1;
        else dir = 1; 
        if(pos + i * dir < 0) break;
        ans[cur + 1] = S[pos + i * dir];
        
        if(dir == 1) dir = -1;
        else dir = 1; 
        cur += 2;
    }
    for(int i = 1; i <= S.length(); i ++) {
        cout << ans[i];
    }
}