#include <bits/stdc++.h>

#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)

using namespace std;

typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    vi a(n);
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
                num[0] = 0;
                num[1] = 1;
                num[2] = 2;
                if (a[cur] == 2)
                    swap(num[1], num[2]);
                if (cur > 1 && a[cur - 1] == 1)
                    swap(num[0], num[1]);
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