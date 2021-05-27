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
const int MAXA = 50 + 10;
const int MOD = 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n,k;
ii a[MAXA];
int S[MAXA];
map<int, bool> ch;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    cin >> n >> k;
    rf(i, 1, n) cin >> a[i].F, a[i].S = i;
    sort(a + 1, a + 1 + n);
    rf(i, 1, n) S[i] = S[i - 1] + a[i].F;
    rf(i, 1, n) {
        rf(j , i, n) {
            if(k && !ch[S[j]- S[i - 1]]) {
                ch[S[j]- S[i - 1]] = 1;
                cout << j - i + 1 << " ";
                rf(l, i, j) cout << a[l].F << " ";
                cout << endl;
                k --;
            }

            if(k && !ch[S[n] - S[j - 1] +  S[i]] && i != j) {
                ch[S[n] - S[j - 1] +  S[i]] = 1;
                cout << n - j + 1 + i << " ";
                rf(l, 1, i) cout << a[l].F << " ";
                rf(l, j, n) cout << a[l].F << " ";
                cout << endl;
                k --;
            }
        }
    }
    rf(i, 1, n) {
        rf(j , i + 1, n) {
            rf(l, j + 1, n) {
                rf(m, l + 1, n) {
                    if(k && !ch[S[j] - S[i] +  S[m] - S[l]] ) {
                        ch[S[j] - S[i] +  S[m] - S[l]] = 1;
                        cout << j - i + m - l << " ";
                        rf(x, i + 1, j) cout << a[x].F << " ";
                        rf(x, l + 1, m) cout << a[x].F << " ";
                        cout << endl;
                        k --;
                    }
                }
            }
        }
    }
    return 0;
}