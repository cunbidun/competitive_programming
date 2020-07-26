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

string S, T;
int ans = 1;

int main() {
    //freopen("in.in", "r", stdin);
    cin >> S >> T;
    int curr = 0;
    for(int i = 0; i < S.size(); ) {
        if(S[i] == T[curr]) {
            ans ++;
            i ++;
        }
        curr++;
        if(curr == T.size()) {
            cout << ans;
            return 0;
        }
    }
    cout << ans;
}