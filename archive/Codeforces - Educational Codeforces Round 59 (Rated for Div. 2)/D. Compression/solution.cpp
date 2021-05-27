#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define endl "\n"
#define F first
#define S second
#define rf(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
#define rb(i,b,a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) cout << (#x) << " = " << (x) << endl
#define test(t) int(testCnt) = 0; int(t); cin >> (t); while(t -- && ++testCnt)

const int INF = 2e9 + 7;
const int MAXA = 5210;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;
const double PI = 3.14159265358979323846264;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n;
int a[MAXA][MAXA];
int sum[MAXA][MAXA];
bool ch(int m) {
    int s = n / m;
    rf(i,1,s) {
        rf(j,1,s) {
            int tmp = sum[i * m][j * m] + sum[(i - 1) * m][(j - 1) * m] - sum[i * m][(j - 1) * m] - sum[(i - 1) * m][j * m];
            //cout << m << " " << i << " " << j << " " << tmp << endl;
            if(tmp != (m * m) && tmp != 0)
                return 0;
        }
    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
  //  freopen("in.in", "r", stdin);
#endif
    cin >> n;
    rf(i,1,n) {
        rf(j,1,n/4) {
            char temp;
            cin >> temp;
            if(temp == '0') {
                a[i][(j - 1) * 4 + 1] = 0;
                a[i][(j - 1) * 4 + 2] = 0;
                a[i][(j - 1) * 4 + 3] = 0;
                a[i][(j - 1) * 4 + 4] = 0;
            }
            if(temp == '1') {
                a[i][(j - 1) * 4 + 1] = 0;
                a[i][(j - 1) * 4 + 2] = 0;
                a[i][(j - 1) * 4 + 3] = 0;
                a[i][(j - 1) * 4 + 4] = 1;
            }
            if(temp == '2') {
                a[i][(j - 1) * 4 + 1] = 0;
                a[i][(j - 1) * 4 + 2] = 0;
                a[i][(j - 1) * 4 + 3] = 1;
                a[i][(j - 1) * 4 + 4] = 0;
            }
            if(temp == '3') {
                a[i][(j - 1) * 4 + 1] = 0;
                a[i][(j - 1) * 4 + 2] = 0;
                a[i][(j - 1) * 4 + 3] = 1;
                a[i][(j - 1) * 4 + 4] = 1;
            }
            if(temp == '4') {
                a[i][(j - 1) * 4 + 1] = 0;
                a[i][(j - 1) * 4 + 2] = 1;
                a[i][(j - 1) * 4 + 3] = 0;
                a[i][(j - 1) * 4 + 4] = 0;
            }
            if(temp == '5') {
                a[i][(j - 1) * 4 + 1] = 0;
                a[i][(j - 1) * 4 + 2] = 1;
                a[i][(j - 1) * 4 + 3] = 0;
                a[i][(j - 1) * 4 + 4] = 1;
            }
            if(temp == '6') {
                a[i][(j - 1) * 4 + 1] = 0;
                a[i][(j - 1) * 4 + 2] = 1;
                a[i][(j - 1) * 4 + 3] = 1;
                a[i][(j - 1) * 4 + 4] = 0;
            }
            if(temp == '7') {
                a[i][(j - 1) * 4 + 1] = 0;
                a[i][(j - 1) * 4 + 2] = 1;
                a[i][(j - 1) * 4 + 3] = 1;
                a[i][(j - 1) * 4 + 4] = 1;
            }
            if(temp == '8') {
                a[i][(j - 1) * 4 + 1] = 1;
                a[i][(j - 1) * 4 + 2] = 0;
                a[i][(j - 1) * 4 + 3] = 0;
                a[i][(j - 1) * 4 + 4] = 0;
            }
            if(temp == '9') {
                a[i][(j - 1) * 4 + 1] = 1;
                a[i][(j - 1) * 4 + 2] = 0;
                a[i][(j - 1) * 4 + 3] = 0;
                a[i][(j - 1) * 4 + 4] = 1;
            }

            if(temp == 'A') {
                a[i][(j - 1) * 4 + 1] = 1;
                a[i][(j - 1) * 4 + 2] = 0;
                a[i][(j - 1) * 4 + 3] = 1;
                a[i][(j - 1) * 4 + 4] = 0;
            }
            if(temp == 'B') {
                a[i][(j - 1) * 4 + 1] = 1;
                a[i][(j - 1) * 4 + 2] = 0;
                a[i][(j - 1) * 4 + 3] = 1;
                a[i][(j - 1) * 4 + 4] = 1;
            }
            if(temp == 'C') {
                a[i][(j - 1) * 4 + 1] = 1;
                a[i][(j - 1) * 4 + 2] = 1;
                a[i][(j - 1) * 4 + 3] = 0;
                a[i][(j - 1) * 4 + 4] = 0;
            }
            if(temp == 'D') {
                a[i][(j - 1) * 4 + 1] = 1;
                a[i][(j - 1) * 4 + 2] = 1;
                a[i][(j - 1) * 4 + 3] = 0;
                a[i][(j - 1) * 4 + 4] = 1;
            }
            if(temp == 'E') {
                a[i][(j - 1) * 4 + 1] = 1;
                a[i][(j - 1) * 4 + 2] = 1;
                a[i][(j - 1) * 4 + 3] = 1;
                a[i][(j - 1) * 4 + 4] = 0;
            }
            if(temp == 'F') {
                a[i][(j - 1) * 4 + 1] = 1;
                a[i][(j - 1) * 4 + 2] = 1;
                a[i][(j - 1) * 4 + 3] = 1;
                a[i][(j - 1) * 4 + 4] = 1;
            }
        }
    }
//    rf(i,1,n) {
//        rf(j,1,n) {
//            cout << a[i][j] << " ";
//        }
//        cout << endl;
//    }
    rf(i,1,n) {
        rf (j,1,n) {
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
        }
    }
//     rf(i,1,n) {
//        rf(j,1,n) {
//            cout << sum[i][j] << " ";
//        }
//        cout << endl;
//    }
    rb(i,n,2) {
        if(n % i == 0) {
            if(ch(i)) {
                cout << i;
                return 0;
            }
        }
    }
    cout << 1;
//    rf(i,1,n) {
//        rf(j,1,n) {
//            cout << a[i][j] << " ";
//        }
//        cout << endl;
//    }
//    int l = 1, r = DIV.size() - 1;
//
//     cout << l << " " << r << endl;
//    while(l != r) {
//        if(l == r - 1) {
//            if(ch(DIV[r]))
//                l = r;
//            else
//                r = l;
//        }
//        int m = (l + r) >> 1;
//        watch(DIV[m]);
//        if(ch(DIV[m])) {
//
//            l = m;
//        } else
//            r = m - 1;
//    }
//    cout << DIV[l];
    return 0;
}