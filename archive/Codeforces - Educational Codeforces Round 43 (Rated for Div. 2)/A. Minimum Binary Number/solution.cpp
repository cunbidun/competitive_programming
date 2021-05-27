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

int n, a[MAXA],k;
string s;
int cnt;
int main() {
    //freopen("in.in","r",stdin);
    cin >> n >> s; 
    if(s[0] == '0') {
        cout << 0;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        if(s[i]=='0') cnt ++;
    }
    cout << 1;
    for(int i = 1; i <= cnt; i ++) cout << 0;
    return 0;
}