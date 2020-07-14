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

char a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k;
    string s;
    cin >> k >> s;
    int sum = 0;

    rf(i, 0, sz(s) - 1) {
        sum += s[i] - '0';
        a[i] = s[i];
    }
    
    sort(a, a + sz(s));

    int ans = 0;
    rf(i, 0, sz(s)) {
        if (sum >= k)
            break;
        ans++;
        sum += 9 - (a[i] - '0');
    }
    cout << ans << "\n";
}