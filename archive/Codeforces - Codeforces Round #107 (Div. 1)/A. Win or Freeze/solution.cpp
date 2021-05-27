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
const int MAXA = 3162278;
const int MOD = 1e9 + 7;

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

ll n;
vi listNum, primeList;
bool isPrime[MAXA];

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

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    sieve(3162278);
    cin >> n;
    ll temp = n;
    int cnt = 0;
    for(int i = 0; i < primeList.size(); i++) {
        if(n == primeList[i]) {
            cout << 1 << endl; 
            cout << 0 << endl;
            return 0;
        }
        while(temp % primeList[i] == 0) {
            cnt ++;
            listNum.pb(primeList[i]);
            temp /= primeList[i];
        }
    }
    
    if(temp > 1) cnt ++;
    if(cnt == 2 ) {
        cout << 2 << endl;
        return 0;
    }
    else if(cnt > 2){
        cout << 1 << endl;
        cout << 1LL * listNum[0] * listNum[1] << endl;
        return 0;
    }
    cout << 1 << endl; 
    cout << 0 << endl;
    return 0;
}