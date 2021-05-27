#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;
#define ll long long
#define INF 1000000007

const int MAXA = 2e5+5;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m, k;
int a[MAXA];

bool check(int val) {
    //cout << "val" <<" " << val << endl;
    int temp = k;
    int cnt = 1;
    for(int i = val + 1; i <= n; i++) {
        if(a[i] <= temp) {
            temp -= a[i];   
        }
        else {
            if(cnt == m) {
                //cout << "false:" << i << endl;
                return 0;
            }
            temp = k;
            cnt ++;
            temp -= a[i];
        }
    }
    return 1;
}

int main() {
    //freopen("in.in","r",stdin);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 0, h = n;
    while(l != h) {
        int mid = (l+h) >> 1;
        if(check(mid)) {
            h = mid;
        }
        else l = mid + 1;
    }
    //cout << l << endl;
    cout << n - l;
    return 0;   
}