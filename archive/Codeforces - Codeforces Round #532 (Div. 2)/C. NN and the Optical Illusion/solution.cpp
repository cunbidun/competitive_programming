#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define PI 3.14159265
#define F first
#define S second
#define rf(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
#define rb(i,b,a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) cout << (#x) << " = " << (x) << endl
#define test(t) int(testCnt) = 0; int(t); cin >> (t); while(t -- && ++testCnt)

const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

double n, r;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    cin >> n >> r;
    double temp = 360 / n / 2;
    double t = r * sin(temp * PI / 180);
    t/=r;
    double x = r*t/(1 - t);
    cout << setprecision(9) << x << endl;
    return 0;
}