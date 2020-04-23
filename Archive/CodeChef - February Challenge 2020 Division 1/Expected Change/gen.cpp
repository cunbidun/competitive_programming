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
void get(string name) {
    stringstream tmp;
    tmp << TextFileToString(name);
    int n;
    tmp >> n >> n;
    string res = "";
    rf(i, 1, n) {
        int x;
        tmp >> x;
        if (x == 0)
            res += '*';
        if (x == 1)
            res += '(';
        if (x == 2)
            res += ')';
    }
    in << "1\n";
    in << n << '\n';
    in << res;
}

struct modInt {
    int MOD;

    modInt(int MOD) { this->MOD = MOD; }

    int add(int x, int y) { return ((x + y) >= MOD ? x + y - MOD : x + y); }

    int sub(int x, int y) { return ((x - y) < 0 ? x - y + MOD : x - y); }

    int mul(int x, int y) { return (int)((1LL * x * y) % MOD); }

    int pow(int x, ll p) {
        if (p == 0)
            return 1;
        int t = pow(x, p / 2);
        if ((p & 1) == 1)
            return mul(mul(t, t), x);
        return mul(t, t);
    }

    int inv(int x) { return pow(x, MOD - 2); }

    int div(int x, int y) { return mul(x, inv(y)); }
} op(1e9 + 7);

// use in and out to read and write to solution file
void solve() {
    int n;
    in >> n >> n;
    vector<char> a(n + 1);
    rf(i, 1, n) in >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int cnt = 0;
            for (int k = i; k <= j; k++) {
                if (a[k] == '(')
                    cnt++;
                else if (a[k] == ')')
                    cnt--;
                if (cnt < 0) {
                    cnt += 2;
                    ans++;
                }
            }
        }
    }
    // out << ans << "\n";
    out << op.div(ans, (n * (n + 1) / 2)) << '\n';
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
