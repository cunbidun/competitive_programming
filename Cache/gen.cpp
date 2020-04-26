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
int ___solve() {
    int n;
    in >> n;
    out << n + n << '\n';
    int ascdcin;

}
