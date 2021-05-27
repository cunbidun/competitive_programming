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
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int p = 0, mx = 0;
    int n;
    cin >> n;
    rf(i, 1, n) {
        cin >> a[i];
        if (a[i] > mx) {
            mx = a[i];
            p = i;
        }
    }
    if (a[p] != 1)
        a[p] = 1;
    else
        a[p] = 2;
    sort(a + 1, a + n + 1);
    rf(i, 1, n) cout << a[i] << " ";
    cout << "\n";
}