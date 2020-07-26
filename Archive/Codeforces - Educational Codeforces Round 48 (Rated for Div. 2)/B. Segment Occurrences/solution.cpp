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

int n, m ,q;
string s, t;
int ans[1010], cnt[1010],a[1010];
int main() {
    //freopen("in.in","r",stdin);
    cin >> n >> m >> q;
    cin >> s >> t;
    for(int i = 0; i < n - m + 1; i++) {
        cnt[i+1] = cnt[i];
      
        if(s[i] == t[0]) {
            bool ok = 1;
            for(int j = 0; j < m; j++) {
                if(s[i+j] != t[j]) {
                    ok = 0;
                    break;
                } 
            }
            if (ok) cnt[i+1]++;
        }
    }
    for(int i = max(0,n - m + 2); i <= n; i++) cnt[i] = cnt[i - 1];
    //for(int i = 1; i <= n; i++) cout << cnt[i] << " "; cout << endl;
    while(q--) {
        int l,r;
        cin >> l >> r;
        r -= m - 1;
        l--;
        cout << max(cnt[r] - cnt[l],0) << endl;
    }
    return 0;
}