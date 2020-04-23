#include "bits/stdc++.h"

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define watch(x) in << (#x) << " = " << (x) << endl
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
    ostringstream dosString(ios::in | ios::binary); // *** binary
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
    in << 1 << "\n";
    int n, q;
    tmp >> n >> q;
    in << n << " " << q << "\n";
    vi a;
    rf(i, 1, n) a.pb(i);
    rf(i, 1, q) {
        random_shuffle(all(a));
        for (int j : a)
            in << j << " ";
        in << "\n";
    }
}

// use in and out read and write to solution file
void solve() {
    int n,q;
    in >> n >> n >> q;
    
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
        in << fixed << setprecision(10);
        solve();
        out.close();
    }
}
