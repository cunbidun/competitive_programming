#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

#define ll long long
#define pb push_back    
#define watch(x) cout << (#x) << " = " << (x) << endl

const int INF = 1e9 + 7;
const int MAXA = 2e5 + 10;
const int MOD = 1e9 + 7;
const int BL = 1500;

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, t;
ll a[MAXA],b[MAXA];
string S;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n / 2; i ++) {
        cin >> b[i];
      //  Mn = max()
    }
    ll temp = b[1];
    a[1] = 0;
    a[n] = temp;
    //cout << temp << endl;
    for(int i = 2; i <= n / 2; i++) {
        //cout << i << " " << n - i + 1 << endl;
        a[i] = max(b[i] - temp, a[i - 1]);
        a[n - i + 1] = b[i] - a[i];
        temp = min(temp,a[n - i + 1]);
    }
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}