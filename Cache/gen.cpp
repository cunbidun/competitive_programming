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
int pre[200005];
int solve() {
    int n, k;
    in >> n >> n>> k;
    vi a(n);
    rf(i, 0, n - 1) { in >> a[i]; }
    memset(pre, 0, sizeof(pre));
    rf(i, 1, n - 1) {
        pre[i] += pre[i - 1];
        if (i + 1 < n && a[i] > a[i - 1] && a[i] > a[i + 1])
            pre[i + 1]++;
    }
    int ans = 1, ma = 0;
    for (int i = 0; i + k - 1 < n; i++) {
        int tmp = pre[i + k - 1] - pre[i];
        if (i > 0 && i < n - 1 && a[i] > a[i - 1] && a[i] > a[i + 1])
            tmp--;
        if (tmp > ma) {
            ma = tmp;
            ans = i + 1;
        }
    }
    out << ma + 1 << " " << ans << "\n";
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
