#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define F first
#define S second
#define rf(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
#define rb(i,b,a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) cout << (#x) << " = " << (x) << endl
#define test(t) int(testCnt) = 0; int(t); cin >> (t); while(t -- && ++testCnt)
#define reset(a,v,b) rf(i, 0, b) a[i] = v

const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;
int n;
void c4() {
    cout << "2 * 3 = 6" << endl;
    cout << "6 * 4 = 24" << endl;
}
void c5() {
    cout << "4 + 3 = 7" << endl;
    cout << "7 + 5 = 12" << endl;
    cout << "12 * 2 = 24" << endl;
}

void c0(int x) {
    vi numList;
    rf(i,x,n-3) {
        cout << i << " + " << i + 3 << " = " << i + i + 3 << endl;
        cout << i + 1 << " + " << i + 2 << " = " << i + i + 3 << endl;
        cout << i + i + 3 << " - " << i + i + 3 << " = " << 0 << endl;
        i += 3;
        numList.pb(0);
    }
    if (numList.size() == 1) return;
    rf(i,0,numList.size() - 2) {
        cout << "0 * 0 = 0" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif

    cin >> n;
    if(n <= 3) return cout << "NO", 0;
    cout << "YES" << endl;
    if (n == 4) {
        c4();
        cout << "24 * 1 = 24" << endl;
        return 0;
    }
    if(n == 5) {
        c5();
        cout << "24 * 1 = 24" << endl;
        return 0;
    }
    if(n == 6) {
        cout << "1 + 5 = 6" << endl;
        cout << "6 - 6 = 0" << endl;
        cout << "0 + 2 = 2" << endl;
        c4();
        return 0;
    }
    if(n == 7) {
        cout << "1 + 6 = 7" << endl;
        cout << "7 - 7 = 0" << endl;
        cout << "0 + 2 = 2" << endl;
        c5();
        return 0;
    }
    if(n % 4 == 0) {
        c0(5);
        c4();
        cout << "24 + 0 = 24" << endl;
        cout << "24 * 1 = 24" << endl;
        return 0;
    }
    if(n % 4 == 1) {
        c0(6);
        c5();
        cout << "24 + 0 = 24" << endl;
        cout << "24 * 1 = 24" << endl;
        return 0;
    }
    if(n % 4 == 2) {
        cout << "1 + 5 = 6" << endl;
        cout << "6 - 6 = 0" << endl;
        cout << "0 + 2 = 2" << endl;
        c0(7);
        c4();
        cout << "24 + 0 = 24" << endl;
        return 0;
    }
    if(n % 4 == 3) {
        cout << "1 + 6 = 7" << endl;
        cout << "7 - 7 = 0" << endl;
        cout << "0 + 2 = 2" << endl;
        c0(8);
        c5();
        cout << "24 + 0 = 24" << endl;
        return 0;
    }
    return 0;
}