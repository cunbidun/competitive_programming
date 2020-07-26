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
const int INF = 1000000007;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, Min;
int a[MAXA];
ll T, ans, cnt, total;

void collect(ll curMoney) {
    for(int i = 1; i <= n; i++) {
        if(a[i] <= curMoney) {
            curMoney -= a[i];
            total += a[i];
            cnt ++;
        }
    }
}

int main() {
    //freopen("in.in","r",stdin);
    cin >> n >> T;
    Min = INF;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        Min = min(Min, a[i]);
    }
    while(T >= Min) {
        //cout << T << endl;
        cnt = 0;
        total = 0;
        collect(T);
        ans += (T/total) * cnt;
        T%=total;    
    }
    cout << ans ;
    return 0;   
}