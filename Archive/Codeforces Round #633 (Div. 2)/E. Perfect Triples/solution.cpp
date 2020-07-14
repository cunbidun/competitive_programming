#include <bits/stdc++.h>

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

const int N = 1e5 + 1;
const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        set<int> used;
    rf(i, 1, 63) if (used.find(i) == used.end()) {
        used.insert(i);
        rf(j, 1, 100) if (used.find(j) == used.end() && used.find(i ^ j) == used.end()) {
            cout << i << " " << j << " " << (i ^ j) << "\n";
            used.insert(i ^ j);
            used.insert(j);
            break;
        }
    }
}