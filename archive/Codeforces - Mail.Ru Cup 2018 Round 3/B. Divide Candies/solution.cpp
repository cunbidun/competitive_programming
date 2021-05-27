#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

#define ll long long
#define pb push_back    

const int INF = 1e9 + 7;
const int MAXA = 1e3 + 10;
const int MOD = 1e9 + 7;

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m;
ll ans;

int main() {
    //freopen("in.in", "r", stdin);
    cin >> n >> m; 
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if((i*i + j*j) % m == 0) {
                //cout << i << " " << j << endl;
                ll temp1 = n / m;
                ll temp2 = temp1;
                if(n % m >= i && i != 0) temp1++;
                if(n % m >= j && j != 0) temp2++;
                ans += temp1 * temp2;
            }
        }
    }
    cout << ans;
    return 0;
}