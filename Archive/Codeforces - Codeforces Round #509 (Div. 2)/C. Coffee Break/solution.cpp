#include <iostream>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <functional> 
#include <queue>
#include <string>

using namespace std;

#define ll long long
#define INF 1000000007

const int MAXA = 2e5+5;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m, k;
ii a[MAXA];
int ch[MAXA], Ans[MAXA];

int Find(int val){
    int l = 1, h = n;
    while(l != h) {
        int m = (l+h) >> 1;
        if(l == h - 1) break;
        if(a[m].first == val) return m;
        if(a[m].first > val) 
            h = m;
        else 
            l = m + 1; 
    }
    if(a[h].first < val) return -1;
    if(l == h) return l;
    if(a[l].first >= val) return l;
    return h;
}

int main() {
    //freopen("in.in","r",stdin);
    cin >> n >> m >> k;
    k++;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a+1,a+n+1);
    //cout << Find(5) << endl;
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        if(ch[i]) continue;
        int curr = a[i].first + k;
        ch[i] = ans;
        Ans[a[i].second] = ans;
        //cout << "new: " << i << " " << curr << endl;
        while(curr <= m) {
            int next = Find(curr);
            if(next == -1) break;
            while(ch[next]) next++;
            if(next > n) break;
            //cout << next << endl;
            curr = a[next].first+k;
            ch[next] = ans;
            Ans[a[next].second] = ans;
        }   
        ans ++;
    }

    cout << ans - 1<< endl;
    for(int i = 1; i <= n; i++) {
        cout << Ans[i] << " ";
    }
    return 0;
}