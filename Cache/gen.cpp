#include "bits/stdc++.h"

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

ofstream out;
stringstream in;

string TextFileToString(string filename) {
    ostringstream dosString(ios::out | ios::binary); // *** binary
    ifstream inFile(filename.c_str());

    string line;
    while (getline(inFile, line))
        dosString << line << "\r\n";

    return dosString.str();
}

// get correct input format from rawInput
void get(string name) { in << TextFileToString(name); }

int ___solve();

int main(int argc, char *argv[]) {
    string name = string(argv[1]);
    get(name);
    out.open(name);
    out << in.str();
    out.close();
    if (argv[2][0] == 't') {
        name.pop_back();
        name.pop_back();
        name.pop_back();
        out.open(name + ".out");
        out << fixed << setprecision(10);
        ___solve();
        out.close();
    }
}
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
 
int ___solve(){
    //freopen("A.out", "w", stdout);
    int t;
    in >> t;
 
    for (int ttt = 1; ttt <= t; ttt++){
        in >> a >> b >> q;
 
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
            in >> l >> r;
            out << calc(r, f, s, tr) - calc(l - 1, f, s, tr) << ' ';
        }
        out << endl;
    }
 
 
 
	return 0;
}
