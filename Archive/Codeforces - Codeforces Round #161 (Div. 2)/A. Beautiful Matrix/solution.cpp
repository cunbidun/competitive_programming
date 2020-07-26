#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define watch(x) cout << (#x) << " = " << (x) << endl
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int N = 2e5 + 1;
const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i <= 25; i++) {
        int x;
        cin >> x;
        if (x == 1)
            return cout << abs(3 - (i + 4) / 5) + abs(3 - ((i % 5 == 0) ? 5 : i % 5)) << "\n", 0;
    }
}