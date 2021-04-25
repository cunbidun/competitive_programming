/*input
5
axabcrwmvd
abcn
tabchwqsl
bvrkabcayna
tyabc
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define PI 3.14159265
#define int long long

typedef pair<string, int> ii;
typedef pair<int, pair<string, int>> iii;
const int N = 101;
const int mod = 1e9 + 7; 

const int base = 19; /* base is a prime */

int n;
string a[1001];
int fact[N]; /* factorial */
int hsh[1001][N]; /* hash from idx 0, i.e. hsh[i] is the hash for substring from index 0 to i */

void init(string& str, int index){
    hsh[0][index] = str[0] - 'a' + 1;
    for(int i = 1; i < str.length(); i++){
        hsh[i][index] = (1ll * hsh[i - 1][index] * base) % mod  +  (str[i] - 'a' + 1);
        hsh[i][index] %= mod;
    }
}

int get_hash(int l, int r, int index){ /* get hashing value of substring from index l to r */
    int res = hsh[r][index];
    if(l == 0) return res; /* return the value we've already initialized */
    res = (res - 1ll * hsh[l - 1][index] * fact[r - l + 1] + 1ll * mod * mod) % mod;
    
    return res;
}

bool isValid(int len){
    set<int> h[1001];
    for(int i = 1; i <= n; i++){
        if(a[i].length() < len) return false;
        for(int j = 0; j < a[i].length(); j++){
            if(j + len - 1 >= a[i].length()) break;
            h[i].insert(get_hash(j, j + len - 1, i));
        }
    }

    for(auto it = h[1].begin(); it != h[1].end(); it++){
        // cout << *it << " ";
        bool contains = true;
        for(int i = 2; i <= n; i++){
            if(h[i].find(*it) == h[i].end()){
                contains = false;
                break;
            }
        }
        if(contains) {
            // cout << *it << endl;
            return true;
        }
    }
    return false;
}

int solve(){
    if(n == 1) return a[1].length();
    int l = 0, r = a[1].length();
    while(l < r){
        // cout << l << " " << r << endl;
        int m = (l + r + 1) >> 1;
        if(isValid(m)) l = m;
        else r = m - 1;
    }
    return l;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    /* factorial init */
    fact[0] = 1;
    for(int i = 1; i < N; i++) fact[i] = (1ll * fact[i - 1] * base) % mod;

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        init(a[i], i);
    }

    // cout << isValid(4);
    // cout << get_hash(1,3,3);

    cout << solve();

    return 0; 
}
