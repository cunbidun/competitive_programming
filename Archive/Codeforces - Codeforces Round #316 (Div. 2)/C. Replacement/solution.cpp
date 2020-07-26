#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define F first
#define S second
#define rf(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
#define rb(i,b,a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) cout << (#x) << " = " << (x) << endl

const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int m, n;
string S;
int cnt = 0, part = 0;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    cin >> n >> m;
    cin >> S;
    S = '%' + S + '%';
    for(int i = 1; i <= n; i++) {
        if(S[i] == '.') {
                cnt ++;
        }
        if(S[i] == '.' && S[i - 1] != '.') part ++;
    }
    while(m --) {
        int pos;
        char val;
        cin >> pos >> val;
//        if(S[val] != '.' && pos !='.') cout << cnt - part << endl;
//        else if(S[val] == '.' && pos == '.') cout << cnt - part << endl;
        if(S[pos] == '.' && val !='.') {
            if(S[pos - 1] == '.' && S[pos + 1] == '.') {
                cnt --;
                part ++;
            }
            else if(S[pos - 1] != '.' && S[pos + 1] != '.') {
                cnt --;
                part --;
            }
            else {
                cnt --;
            }
            S[pos] = val;
        }
        else if (S[pos] != '.' && val =='.'){
            if(S[pos - 1] == '.' && S[pos + 1] == '.') {
                cnt ++;
                part --;
            }
            else if(S[pos - 1] != '.' && S[pos + 1] != '.') {
                cnt ++;
                part ++;
            }
            else {
                cnt ++;
            }
            S[pos] = val;
        }
        cout << cnt - part << endl;
    }
    return 0;
}