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
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
int const nmax = 3000;
char v[1 + nmax];

vector<int> processlevel(int n) {
    vector<int> sol;
    for (int i = 1; i < n; i++)
        if (v[i] == 'R' && v[i + 1] == 'L')
            sol.push_back(i);
    for (int i = 0; i < sol.size(); i++)
        swap(v[sol[i]], v[sol[i] + 1]);
    return sol;
}

int solve() {
    int n, k;
    in >> n >> k;
    for (int i = 1; i <= n; i++)
        in >> v[i];
    vector<vector<int>> solbig;
    int movesmax = 0;
    while (true) {
        vector<int> sol = processlevel(n);
        if (sol.size() == 0)
            break;
        movesmax += sol.size();
        solbig.push_back(sol);
    }
    if (k < solbig.size() || movesmax < k) {
        out << -1;
        return 0;
    }
    int ptr = 0, movesmin = solbig.size();

    while (movesmin < k) {
        if (solbig[ptr].size() == 0) {
            ptr++;
            movesmin--;
        }
        out << 1 << " " << solbig[ptr].back() << '\n';
        solbig[ptr].pop_back();
        k--;
        if (solbig[ptr].size() == 0) {
            ptr++;
            movesmin--;
        }
    }

    for (int i = ptr; i < solbig.size(); i++) {
        out << solbig[i].size() << " ";
        for (int j = 0; j < solbig[i].size(); j++)
            out << solbig[i][j] << " ";
        out << '\n';
    }

    return 0;
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
