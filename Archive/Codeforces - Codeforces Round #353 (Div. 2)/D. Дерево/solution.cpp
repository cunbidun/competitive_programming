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

int n, val[MAXA], num[MAXA], p[MAXA], l[MAXA], r[MAXA];
ii a[MAXA];
set<int> numList;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
//        /freopen("in.in", "r", stdin);
    #endif
    cin >> n;
    rf(i, 1, n) {
        cin >> a[i].F;
        a[i].S = i;
    }
    sort(a + 1, a + n + 1);
    rf(i, 1, n) {
        num[a[i].S] = i;
        val[i] = a[i].F;
    }
//    rf(i, 1, n) cout << num[i] << " ";
//    cout << endl;
    numList.insert(num[1]);
    rf(i, 2, n) {
        if(num[i] < *numList.begin()) {
            p[i] = val[*numList.begin()];
            l[*numList.begin()] = 1;
            numList.insert(num[i]);
            continue;
        }
        else if(num[i] > *numList.rbegin()){
            p[i] = val[*numList.rbegin()];
            r[*numList.rbegin()] = 1;
            numList.insert(num[i]);
            continue;
        }
        set<int>::iterator pos = numList.lower_bound(num[i]);
        pos --;
        if(r[*pos] == 1) {
            pos ++;
            p[i] = val[*pos];
            l[*pos] = 1;
            numList.insert(num[i]);
        }
        else {
            p[i] = val[*pos];
            r[*pos] = 1;
            numList.insert(num[i]);
        }
    }
    rf(i, 2, n) cout << p[i] << " ";
    return 0;
}