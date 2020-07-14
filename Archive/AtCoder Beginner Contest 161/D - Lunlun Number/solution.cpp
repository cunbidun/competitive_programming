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

string gen(string n) {
    rb(i, sz(n) - 1, 1) {
        if (n[i] == '9' || n[i] == n[i - 1] + 1)
            continue;
        n[i] = n[i] + 1;
        rf(j, i + 1, sz(n) - 1) n[j] = (char)max(n[j - 1] - 1, 48);
        return n;
    }
    if (n[0] != '9') {
        n[0] = n[0] + 1;
        rf(j, 1, sz(n) - 1) n[j] = (char)max(n[j - 1] - 1, 48);
        return n;
    }
    string res = "1";
    rf(i, 1, sz(n)) res += '0';
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string num = "0";
    while (n--) {
        num = gen(num);
    }
    cout << num << "\n";
}