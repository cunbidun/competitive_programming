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
    if (n == 0) {
        cout << "+------------------------+\n";
        cout << "|#.#.#.#.#.#.#.#.#.#.#.|D|)\n";
        cout << "|#.#.#.#.#.#.#.#.#.#.#.|.|\n";
        cout << "|#.......................|\n";
        cout << "|#.#.#.#.#.#.#.#.#.#.#.|.|)\n";
        cout << "+------------------------+\n";
        return 0;
    }
    if (n == 1) {
        cout << "+------------------------+\n";
        cout << "|O.#.#.#.#.#.#.#.#.#.#.|D|)\n";
        cout << "|#.#.#.#.#.#.#.#.#.#.#.|.|\n";
        cout << "|#.......................|\n";
        cout << "|#.#.#.#.#.#.#.#.#.#.#.|.|)\n";
        cout << "+------------------------+\n";
        return 0;
    }
    if (n == 2) {
        cout << "+------------------------+\n";
        cout << "|O.#.#.#.#.#.#.#.#.#.#.|D|)\n";
        cout << "|O.#.#.#.#.#.#.#.#.#.#.|.|\n";
        cout << "|#.......................|\n";
        cout << "|#.#.#.#.#.#.#.#.#.#.#.|.|)\n";
        cout << "+------------------------+\n";
        return 0;
    }
    if (n == 3) {
        cout << "+------------------------+\n";
        cout << "|O.#.#.#.#.#.#.#.#.#.#.|D|)\n";
        cout << "|O.#.#.#.#.#.#.#.#.#.#.|.|\n";
        cout << "|O.......................|\n";
        cout << "|#.#.#.#.#.#.#.#.#.#.#.|.|)\n";
        cout << "+------------------------+\n";
        return 0;
    }
    if (n == 4) {
        cout << "+------------------------+\n";
        cout << "|O.#.#.#.#.#.#.#.#.#.#.|D|)\n";
        cout << "|O.#.#.#.#.#.#.#.#.#.#.|.|\n";
        cout << "|O.......................|\n";
        cout << "|O.#.#.#.#.#.#.#.#.#.#.|.|)\n";
        cout << "+------------------------+\n";
        return 0;
    }
    int cnt = 0;
    n -= 4;
    cout << "+------------------------+\n";
    cout << "|O.";
    rf(i, 1, 10) {
        if (i <= n / 3 + (cnt < n % 3))
            cout << "O.";
        else
            cout << "#.";
    }
    cout << "|D|)\n";
    cnt++;

    cout << "|O.";
    rf(i, 1, 10) {
        if (i <= n / 3 + (cnt < n % 3))
            cout << "O.";
        else
            cout << "#.";
    }
    cout << "|.|\n";
    cnt++;
    cout << "|O.......................|\n";

    cout << "|O.";
    rf(i, 1, 10) {
        if (i <= n / 3 + (cnt < n % 3))
            cout << "O.";
        else
            cout << "#.";
    }
    cout << "|.|)\n";
    cnt++;

    cout << "+------------------------+\n";
}