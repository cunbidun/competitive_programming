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
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << '(' << a.first << ", " << a.second << ')'; }

template <class T> ostream &operator<<(ostream &os, const vector<T> &a) {
    os << '[';
    for (unsigned int i = 0; i < a.size(); i++)
        os << a[i] << (i < a.size() - 1 ? ", " : "");
    os << ']';
    return os;
}

const int N = 1e5 + 1;
const int INF = 2e9;
int arr[100][100];

vi l;
int ans;
int cnt;
void pre_cal(int n) {
    for (int line = 0; line < n; line++) {
        for (int i = 0; i <= line; i++) {
            if (line == i || i == 0)
                arr[line][i] = 1;
            else
                arr[line][i] = arr[line - 1][i - 1] + arr[line - 1][i];
            if (arr[line][i] > 1e9)
                arr[line][i] = 0;
        }
        if (arr[line][(line + 1) / 2] != 0)
            l.pb(arr[line][(line + 1) / 2]);
        else
            break;
    }
}

void cal(int n) {
    // cout << n << " " << ans << "\n";

    int sum = 0;
    rf(i, 1, sz(l) - 1) {
        sum += l[i];
        cout << i << " " << (i + 1) / 2 << "\n";
        ans += arr[i - 1][(i + 1) / 2 - 1];

        if (2 * (sum) + l[i + 1] > n) {
            rb(j, i - 1, 2) {
                cout << j << " " << (j + 1) / 2 << "\n";
                cnt++;
                ans += arr[j - 1][(j + 1) / 2 - 1];
                sum += l[j];
            }

            cal(n - sum);
            return;
        }
    }
}

void solve() {
    int cnt = 0;
    int ans = 0;
    int n;
    cin >> n;
    if (n <= 31) {
        rf(i, 1, n) cout << i << " " << 1 << "\n";
        return;
    }
    int left = 1;
    n -= 31;
    int cur = 1;
    rf(i, 0, 30) {
        if (((n >> i) & 1) == 1) {
            if (left)
                rf(j, 0, i) {
                    cout << i + 1 << " " << j + 1 << "\n";
                    cnt++;
                    ans += arr[i][j];
                }
            else {
                rb(j, i, 0) {
                    cout << i + 1 << " " << j + 1 << "\n";
                    cnt++;
                    ans += arr[i][j];
                }
            }
            left = 1 - left;
        } else {
            if (left)
                cout << i + 1 << " " << 1 << "\n";
            else
                cout << i + 1 << " " << i + 1 << "\n";
            cnt++;
            ans += 1;
        }
    }
    int tmp = n + 31 - ans;
    rf(i, 32, 32 + tmp-1) {
        if (left)
            cout << i << " " << 1 << "\n";
        else
            cout << i << " " << i << "\n";
        cnt++;
        ans += 1;
    }
    cout << cnt << " " << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    l.pb(0);
    pre_cal(99);
    // cout << l << "\n";
    int t;
    cin >> t;
    rf(i, 1, t) {
        cout << "Case #" << i << ":\n";
        solve();
    }
}