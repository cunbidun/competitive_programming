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

stringstream in;
ofstream out;

// get correct input format from rawInput
void get(string rawInput) {
    stringstream tmp;
    tmp << rawInput;
    int n, m;
    tmp >> n >> n >> m;
    vi a;
    vi b;
    while (n--) {
        int x;
        tmp >> x;
        if (x != 0)
            a.pb(x);
    }

    while (m--) {
        int x;
        tmp >> x;
        if (x != 0)
            b.pb(x);
    }
    sort(all(a));
    sort(all(b));
    a.erase(unique(all(a)), a.end());
    b.erase(unique(all(b)), b.end());
    in << 1 << "\n";
    in << sz(a) << " " << sz(b) << "\n";
    for (int i : a)
        in << i << " ";
    in << "\n";
    for (int i : b)
        in << i << " ";
    in << "\n";
}

bool ch(int i) {
    int x = sqrt(i);
    return x * x == i;
}
// use in and out to read and write to solution file
void solve() {
    int n, m;
    in >> n >> n >> m;
    set<int> xP, xN, yP, yN;
    bool h0 = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        in >> x;
        if (x > 0)
            xP.insert(x);
        else if (x < 0)
            xN.insert(-x);
        else
            h0 = 1;
    }
    for (int i = 1; i <= m; i++) {
        int y;
        in >> y;
        if (y > 0)
            yP.insert(y);
        else if (y < 0)
            yN.insert(-y);
        else
            h0 = 1;
    }
    int ans = ((h0) ? ((sz(yP) + sz(yN)) * (sz(xN) + sz(xP))) : 0);
    for (int i : xP)
        for (int j : xN) {
            int n = i * j;
            if (ch(n)) {
                if (yP.find(sqrt(n)) != yP.end())
                    ans++;
                if (yN.find(sqrt(n)) != yN.end())
                    ans++;
            }
        }

    for (int i : yP)
        for (int j : yN) {
            int n = i * j;
            if (ch(n)) {
                if (xP.find(sqrt(n)) != xP.end())
                    ans++;
                if (xN.find(sqrt(n)) != xN.end())
                    ans++;
            }
        }
    out << ans << "\n";
}

int main(int argc, char *argv[]) {
    get(string(argv[1]));
    cout << in.str();
    if (argv[3][0] == 't') {
        out.open(string(argv[2]) + ".out");
        out << fixed << setprecision(10);
        solve();
        out.flush();
        out.close();
    }
}
