#include <iostream>
#include <algorithm>
#include <set>
#include <map>
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
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, a[MAXA], pos[MAXA];
ii b[MAXA];
bool isPrime[MAXA];
vii ans;
vi primeList;
void sieve(int val) {
    isPrime[0] = 0;
    isPrime[1] = 0;
    for(int i = 2; i <= val; i++) {
        isPrime[i] = 1;
    }    

    for(int i = 2; i <= val; i++) {
        if(isPrime[i]) {
            primeList.pb(i);
        }
        for(int j = 2 * i; j <= val; j += i) {
            isPrime[j] = 0;
        }
    }
}

void swapArr(int x, int y) {
    // cout << "swap: ";
    // cout << x << " " << y << endl;
    pos[a[x]] = y;
    pos[a[y]] = x;
    ans.pb(ii(x,y));
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
    // for(int i = 1; i <= n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // for(int i = 1; i <= n; i++) {
    //     cout << pos[i] << " ";
    // }
    // cout << endl;
}
int findNum(int val) {
    int l = 0, r = primeList.size() - 1;
    while(l != r) {
        int m = (l + r) >> 1;
        if (l == r - 1) {
            if(primeList[r] <= val) return r;
            else return l;
        }
        if(primeList[m] < val) {
            l = m;
        }
        else 
            r = m;
    }
    return l;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    sieve(100000);
    cin >> n;
    //cout << n << endl;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i].first = a[i];
        b[i].second = i;
    }
    sort(b + 1, b + n + 1);
    for(int i = 1; i <= n; i++) {
        pos[i] = b[i].second;
        a[b[i].second] = i;
    }
    // for(int i = 1; i <= n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // for(int i = 1; i <= n; i++) {
    //     cout << pos[i] << " ";
    // }
    // cout << endl;
    for(int i = 1; i <= n; i++) {
        //watch(i);
        int move = abs(pos[i] - i) + 1;
        //watch(move);
        if(move == 1) continue;
        while(move) {
            if (move == 1) break;
            int low = findNum(move);   
            //watch(low);
            int temp = primeList[low];
            //watch(temp);
            move -= temp;
            move ++;
            //watch(move);
            swapArr(pos[i], pos[i] - temp + 1);
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << min(ans[i].first,ans[i].second) << " " << max(ans[i].first,ans[i].second)<< endl;
    }
}