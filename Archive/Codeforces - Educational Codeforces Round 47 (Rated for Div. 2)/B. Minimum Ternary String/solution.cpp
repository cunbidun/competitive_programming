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
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

string S;
char a[MAXA];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    clock_t clk = clock();
    cin >> S;
    int n = S.length();
    S = 'x' + S;
    int curr = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(S[i] == '1') cnt++;
        else {
            curr ++;
            a[curr] = S[i]; 
        }
    }
    for(int i = 1; i <= curr; i++) {
        if(a[i] == '2' && cnt) {
            while(cnt) {
                cout << "1";
                cnt --;
            }
            cout << 2;
            continue;
        }
        else {
            cout << a[i];
        }
    }
    while(cnt) {
        cout << "1";
        cnt --;
    }
    cout << endl;
    cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}