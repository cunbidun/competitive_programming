#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>


using namespace std;
#define ll long long

#define MAXA 200020
const ll INF = 1000000007;

typedef pair<ll, ll> ii;
typedef pair<ll, ii> II;
typedef vector<ll> vi;
typedef vector<ii> vii;

int n, m;
ll k;
string s;
int cnt;
int main() {
    //freopen("in.in","r",stdin);
    cin >> n >> m >> k;
    if(k <= n-1) {
        cout << k+1 << " " << 1;
        return 0;
    }
    k -= n;
    ll r = k/(m - 1);
    ll c = k%(m - 1);
    if((n - r) % 2 == 0)
        cout << n - r << " " << 2 + c;
    else
        cout << n - r << " " << m - c;
}