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

bool isLeapYear(int i) {
    if (i % 400 == 0)
        return 1;
    if (i % 100 == 0)
        return 0;
    return i % 4 == 0;
}

int sol(int m, int y) {
    if (m < 2)
        y--;
    if (y == 0)
        return 0;
    int ans = y / 400 * 101;
    int day = 0;
    for (int i = 0; i <= y % 400; i++) {
        if (isLeapYear(i)) {
            if ((day + 31) % 7 == 0)
                ans++;
        } else {
            if ((day + 31) % 7 == 0 || (day + 31) % 7 == 1)
                ans++;
        }
        day += 365 + isLeapYear(i);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int m1, m2, y1, y2;
        cin >> m1 >> y1 >> m2 >> y2;
        if (m1 != 1)
            cout << sol(m2, y2) - sol(m1 - 1, y1) << "\n";
        else if (y1 != 1)
            cout << sol(m2, y2) - sol(12, y1 - 1) << "\n";
        else
            cout << sol(m2, y2) << "\n";
    }
}