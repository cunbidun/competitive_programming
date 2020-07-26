#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <functional> 
#include <queue>

using namespace std;
#define ll long long
#define INF 1000000007

const int MAXA = 2e5+10;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, k;
int a[MAXA];
ii cnt[MAXA];
int pos; 
bool check(int val) {
    //cout << "val" <<" " << val << endl;
    int temp = k;
    for(int i = 1; i <= n; i++) {
        if(cnt[i].first == 0) break;
        temp -= (cnt[i].first/val);
        if(temp <= 0) {
            pos = i;
            return 1;
        }
    }
    return 0;
}

int main() {
    //freopen("in.in","r",stdin);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]].first++;
        cnt[a[i]].second = i;
    }

    // for(int i = 1; i <= n; i++) { 
    //     cout << "(" <<a[i] << " " << cnt[a[i]].first << ") ";
    // }
    // cout << endl;
    sort(cnt+1, cnt+MAXA-5, greater<ii>()); 
    // for(int i = 1; i <= n; i++) { 
    //     cout << cnt[i].first << " ";
    // }
    // cout << endl;
    int l = 1, h = n;
    while(l != h) {
        if(l == h - 1) break;
        int mid = (l+h) >> 1;
        if(check(mid)) {
            l = mid;
        }
        else h = mid - 1;
    }
    int ans = h;
    if(!check(h)) {
        ans = l;
        check(l);
    }
    //cout << pos << " " << ans << endl;
    for(int i = 1; i <= pos; i ++) {
        for(int j = 1; j <= cnt[i].first/ans; j++){
            cout << a[cnt[i].second] << " ";
            k--;
            if(k == 0) return 0;
        }
    }
    return 0;   
}