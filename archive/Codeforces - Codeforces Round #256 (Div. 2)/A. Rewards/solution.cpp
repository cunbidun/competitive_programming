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

int n, a, b;
int ans = 0;

int main() {
    //freopen("in.in", "r", stdin);
    int a1, a2, a3, b1, b2, b3;
    cin >> a1 >> a2 >> a3;
    cin >> b1 >> b2 >> b3;
    cin >> n;
    a = a1 + a2 + a3;
    b = b1 + b2 + b3;
    if(a % 5 == 0) ans += a / 5;
    else ans += a / 5 + 1;
    
    if(b % 10 == 0) ans += b / 10;
    else ans += b / 10 + 1;
    if(ans <= n) cout << "YES";
    else cout << "NO";
}