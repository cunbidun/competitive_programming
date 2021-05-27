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

const int N = 1e3 + 1;
const int INF = 2e9;

vi a(N);
int n, p;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p;
    rf(i, 1, n) {
        char x;
        cin >> x;
        a[i] = x - 'a' + 1;
    }
    int cur = n;
    if (a[cur] == (char)('a' + p - 1))
        cur--;
    while (cur >= 1) {
        while (a[cur] + 1 <= p) {
            a[cur]++;
            if ((cur > 2 && a[cur] != a[cur - 2] && a[cur] != a[cur - 1]) || (cur == 2 && a[cur] != a[cur - 1]) || cur == 1) {
                rf(i, 1, cur) cout << (char)('a' + a[i] - 1);
                int cnt = 0;
                int num[3];
                if(a[cur] != 2){
                    num[0] = 0;
                    num[1] = 1;
                    num[2] = 2;

                    if (cur > 1 && a[cur - 1] == 1) {
                        num[0] = 1;
                        num[1] = 0;
                        num[2] = 2;
                    }
                } else {
                    num[0] = 0;
                    num[1] = 2;
                    num[2] = 1;

                    if (cur > 1 && a[cur - 1] == 1) {
                        num[0] = 2;
                        num[1] = 0;
                        num[2] = 1;
                    }
                }
                rf(i, cur + 1, n) {
                    cout << (char)('a' + num[cnt]);
                    cnt = (cnt + 1) % 3;
                }
                return 0;
            }
        }
        cur--;
    }
    cout << "NO\n";
}