#include <iostream>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <functional> 
#include <queue>
#include <string>

#define ll long long
#define pb push_back    
#define watch(x) cout << (#x) << " = " << (x) << endl

const int INF = 1e9 + 7;
const int MAXA = 2e5 + 10;
const int MOD = 1e9 + 7;

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n;
ii a[MAXA];
vi firstTeam, secondTeam;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    firstTeam.pb(a[n].second);
    for(int i = n - 1; i >= 1; i -= 2) {
        secondTeam.pb(a[i].second);
        if(i - 1 > 0)
            firstTeam.pb(a[i - 1].second);
    }
    cout << firstTeam.size() << endl;
    for(int i = 0; i < firstTeam.size(); i ++) 
        cout << firstTeam[i] << " ";
    cout << endl;
    cout << secondTeam.size() << endl;
    for(int i = 0; i < secondTeam.size(); i ++) 
        cout << secondTeam[i] << " ";
    cout << endl;


}