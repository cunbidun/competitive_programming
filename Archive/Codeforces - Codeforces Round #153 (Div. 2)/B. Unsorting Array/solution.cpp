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

int a[N];
int n;
bool check() {
    int cnt = 0;
    rf(i, 2, n) if (a[i] < a[i - 1]) {
        cnt++;
        break;
    }
    rf(i, 2, n) if (a[i] > a[i - 1]) {
        cnt++;
        break;
    }
    return cnt == 2;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    bool ok = 0;
    rf(i, 1, n) {
        cin >> a[i];
        if (i > 1 && a[i] != a[i - 1])
            ok = 1;
    }

    if (ok == 0)
        return cout << -1 << "\n", 0;
    rf(i, 1, n) rf(j, 1, n) if (i != j && a[i] != a[j]) {
        swap(a[i], a[j]);
        if (check())
            return cout << i << " " << j << "\n", 0;
        swap(a[i], a[j]);
    }
    cout << -1 << "\n";
}