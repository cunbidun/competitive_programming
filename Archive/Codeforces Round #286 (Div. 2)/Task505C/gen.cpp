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

const int N = 1e2 + 1;
const int INF = 2e9;
int n, d;
set<int> a[N];
int g[N];
int ans[N];

void build(int cur, int l) {
    rf(i, -1, 1) {
        if (l + i >= 1) {
            if (a[cur].find(cur + l + i) == a[cur].end() && cur + l + i < N) {
                build(cur + l + i, l + i);
                a[cur].insert(cur + l + i);
                if (sz(a[cur + l + i]) == N - (cur + l + i) - 1)
                    break;
            }
        }
    }
}

vi l;
bool vis[N];
void topologicalSort(int u) {
    vis[u] = 1;
    for (int v : a[u])
        if (!vis[v])
            topologicalSort(v);
    l.pb(u);
    reverse(all(l));
}

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
    in >> n >> d;
    rf(i, 1, n) {
        int x;
        in >> x;
        g[x]++;
    }
    build(d, d);
    topologicalSort(d);

    int res = 0;
    rf(u, d, N - 1) {
        ans[u] += g[u];
        for (int v : a[u]) {
            ans[v] = max(ans[v], ans[u]);
        }
        res = max(res, ans[u]);
    }
    out << res << "\n";
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
