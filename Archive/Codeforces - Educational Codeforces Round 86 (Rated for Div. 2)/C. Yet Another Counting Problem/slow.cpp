#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

// Code below this line will be copied.

const int INF = (int)(1e9 + 7);
const double EPS = 1e-6;
const int MAXN = (int)(1e5 + 500);
ll a, b, q, l, r;
 
ll calc(ll x, ll f, ll s, ll tr){
    if (f == 0)
        return 0;
    if (x < f)
        return 0;
    x -= (f - 1);
    ll ans = x / (tr - f) * (s - f + 1);
    ans += min(x % (tr - f), (s - f + 1));
    return ans;
}
 
 
ll f, s, tr;
 
int main(){
    //freopen("A.out", "w", stdout);
    int t;
    cin >> t;
 
    for (int ttt = 1; ttt <= t; ttt++){
        cin >> a >> b >> q;
 
        bool was = false;
        bool waas = false;
        f = s = tr = 0;
        for (ll j = max(a, b); j <= 3000000; j++)
            if (j % a % b != j % b % a){
                if (!was)
                {
                    f = j;
                    was = true;
                }
                else if (waas == false){
                    s = j;
                }
                else{
                    tr = j;
                    break;
                }
            }
            else
                waas = true;
       //cout << f <<  ' ' << s << ' ' << tr << endl;
        for (int i = 1; i <= q; i++){
            cin >> l >> r;
            cout << calc(r, f, s, tr) - calc(l - 1, f, s, tr) << ' ';
        }
        cout << endl;
    }
 
 
 
	return 0;
}