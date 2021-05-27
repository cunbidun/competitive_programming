#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>


using namespace std;
#define ll long long

#define MAXA 200005
const ll INF = 1000000007;

typedef pair<ll, ll> ii;
typedef pair<ll, ii> II;
typedef vector<ll> vi;
typedef vector<ii> vii;

ll n;
ii a[MAXA];
ll sum;
vi ans;
int main() {
    //freopen("in.in","r",stdin);
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        sum += a[i].first;
    }
    sort(a+1,a+n+1);    
    for(ll i = 1; i < n; i++) {
        //cout << i << " " << sum - a[i].first - a[n].first << endl;
        if(sum - a[i].first - a[n].first == a[n].first) {
            //cout << a[i].first << endl;
            ans.push_back(a[i].second);
        }
    }
    if(sum - a[n].first - a[n-1].first == a[n-1].first) ans.push_back(a[n].second);
    cout << ans.size() << endl;
    for(ll i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}