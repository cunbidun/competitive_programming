#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

#define ll long long
#define pb push_back    
#define watch(x) cout << (#x) << " = " << (x) << endl

const int INF = 1e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, q;
string S;
int cntx[MAXA], cnty[MAXA], cntz[MAXA];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    cin >> S;
    n = S.length();
    S = '*' + S;
    for(int i = 1; i <= n; i++){
        cntx[i] = cntx[i - 1] + (S[i] == 'x');
        cnty[i] = cnty[i - 1] + (S[i] == 'y');
        cntz[i] = cntz[i - 1] + (S[i] == 'z');
    }
    //for(int i = 1; i <= n; i++) cout << cntz[i]; cout << endl;
    cin >> q;
    while(q -- ){
        int l, r;
        cin >> l >> r;
        int dis = r - l + 1;
        //watch(dis);
        if(dis < 3) {
            cout << "YES" << endl; 
            continue;
        }
        int x = cntx[r] - cntx[l - 1];
        int y = cnty[r] - cnty[l - 1];
        int z = cntz[r] - cntz[l - 1];

        //watch(x);
        //watch(y);
        //watch(z);
        if(!x || !y || !z) {
            cout << "NO" << endl; 
            continue;
        }
        if (x >= dis / 3 && y >= dis / 3 && z >= dis / 3) {
            if(abs(x - y) <= 1 && abs(y - z) <= 1 && abs(x - z) <= 1)
                cout << "YES" << endl;
            else 
                cout << "NO" << endl;
            continue;
        } 
        cout << "NO" << endl;
    }
    return 0;
}