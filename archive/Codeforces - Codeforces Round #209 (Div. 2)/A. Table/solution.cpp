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

int n, m;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int temp;
            cin >> temp;
            //cout << temp << endl;
            if(temp == 1) {
            //    cout << i << " " << j << endl;
                if(i == 1 || i == n || j == 1 || j == m) {
                    cout << 2;
                    return 0;
                }
            }
        }
    }    
    cout << 4;
    return 0;
}