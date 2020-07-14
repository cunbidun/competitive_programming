#include "bits/stdc++.h"

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define watch(x) out << (#x) << " = " << (x) << endl
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int MOD = 1e9 + 7;
const int INF = 2e9;

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

// use in and out to read and write to solution file
void solve() {
    ll n;
    in >> n;
    ll a[n], b[n];
    map<ll, multiset<ll>> m;
    for (int i = 0; i < n; ++i) {
        in >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        in >> b[i];
        m[a[i]].insert(b[i]);
    }
    multiset<ll, greater<>> newset;
    sort(a, a + n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll x = 0;
        // out << m[a[i]].size();
        if (m[a[i]].size() > 1) {
            x = a[i];
            ll tosum = 0;
            while (1) {
                for (auto j : m[x]) {
                    newset.insert(j);
                    tosum += j;
                }
                tosum -= *newset.begin();
                newset.erase(newset.find(*newset.begin()));
                ans += tosum;
                // out << x;
                // out << tosum<<"\n";
                x++;
                if (newset.empty()) {
                    break;
                }
            }
        }
        // out << x;
        while (a[i] < x) {
            i++;
        }
        // out << i;
    }
    out << ans;
}

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
        solve();
        out.close();
    }
}
