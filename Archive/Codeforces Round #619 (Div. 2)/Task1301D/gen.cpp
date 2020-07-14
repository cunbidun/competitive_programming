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
string get(string rawInput) { return rawInput; }

// use in and out to read and write to solution file
void solve() {}

int main(int argc, char *argv[]) {
    in << get(string(argv[1]));
    cout << in.str();
    if (argv[3][0] == 't') {
        out.open(string(argv[2]) + ".out");
        out << fixed << setprecision(10);
        solve();
        out.close();
    }
}
