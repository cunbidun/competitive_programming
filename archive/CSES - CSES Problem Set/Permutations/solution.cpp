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
    int n;
    cin >> n;
    if (n == 1)
        return cout << 1 << "\n", 0;
    if (n == 2 || n == 3)
        return cout << "NO SOLUTION\n", 0;
    if (n == 4)
        return cout << "3 1 4 2\n", 0;
    rf(i, 1, (n + 1) / 2) cout << i * 2 - 1 << " ";
    rf(i, 1, n / 2) cout << i * 2 << " ";
}