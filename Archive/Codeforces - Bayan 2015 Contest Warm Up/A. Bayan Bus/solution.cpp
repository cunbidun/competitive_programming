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

char a[6][100]{
    "+------------------------+", "|#.#.#.#.#.#.#.#.#.#.#.|D|)", "|#.#.#.#.#.#.#.#.#.#.#.|.|", "|#.......................|", "|#.#.#.#.#.#.#.#.#.#.#.|.|)", "+------------------------+",
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    rf(j, 0, 21) {
        rf(i, 1, 4) {

            if (n != 0 && a[i][j] == '#') {
                a[i][j] = 'O';
                n--;
            }

            if (n == 0) {
                rf(i, 0, 5) { cout << a[i] << "\n"; }
                return 0;
            }
        }
    }
}