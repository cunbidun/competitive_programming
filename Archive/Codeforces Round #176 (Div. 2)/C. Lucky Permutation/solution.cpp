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
    if (n % 4 == 2 || n%4 == 3)
        return cout << -1 << "\n", 0;
    int l = 1, r = n;
    int a[N];
    rf(i, 1, n) a[i] = i;
    while (l < r) {
        swap(a[l], a[l + 1]);
        swap(a[l], a[r - 1]);
        swap(a[r], a[r - 1]);
        l += 2;
        r -= 2;
    }
    rf(i, 1, n) cout << a[i] << " ";
    cout << "\n";
}