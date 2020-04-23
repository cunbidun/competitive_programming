#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)

using namespace std;

class Solver {
  public:
    typedef long long ll;
    typedef vector<int> vi;
    typedef pair<int, int> ii;
    typedef pair<ii, int> iii;
    typedef vector<ii> vii;

    const int N = 1e5 + 1;
    const int INF = 2e9;

    vi a{N};
    int solve() {
        int n;
        cin >> n;
        int ans = 0;
        rf(i, 1, n) ans += i;
        cout << ans << "\n";
    }
};

class Checker {
  public:
    typedef long long ll;
    typedef vector<int> vi;
    typedef pair<int, int> ii;
    typedef pair<ii, int> iii;
    typedef vector<ii> vii;

    const int N = 1e5 + 1;
    const int INF = 2e9;

    vi a{N};
    int get() {
        int n;
        cin >> n;
        return n;
    }
    int solve() {
        int n = get();
        cout << n * (n + 1) / 2 << "\n";
    }
};

int cur = 0;

void change_out_stream() {
    ofstream out("./TestCase/" + to_string(cur++) + ".out");
    cout.rdbuf(out.rdbuf());
}

int main(int argc, char *argv[]) {
    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i <= 2; i++) {
        string name = to_string(i) + ".in";
        FILE *f = freopen(name.c_str(), "r", stdin);
        ios_base::sync_with_stdio(0);
        Solver *solver = new Solver();
        (*solver).solve();

        Checker *checker = new Checker();
        (*checker).solve();

        free(solver);
        free(checker);
    }
    ios_base::sync_with_stdio(0);
    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    cout << time_span.count() << "\n";
}

// g++ -DLOCAL -include ../../Script/stdc++.h -o solution ./solution.cpp --std=c++17;