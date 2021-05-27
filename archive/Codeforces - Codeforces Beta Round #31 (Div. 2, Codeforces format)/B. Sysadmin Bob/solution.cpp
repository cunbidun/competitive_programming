#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define F first
#define S second
#define rf(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
#define rb(i,b,a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) cout << (#x) << " = " << (x) << endl
#define reset(a,b) memset((a),(b),sizeof(a))

const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

string S;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    cin >> S;
    int cnt = 0;
    rf(i,0,S.size() - 1) {
        if(S[i] == '@') cnt ++;
    }
    if(!cnt) return cout << "No solution", 0;
    if(S[0] == '@' || S[S.size() - 1] == '@') return cout << "No solution", 0;
    rf(i,1,S.size() - 2) {
        if(S[i] == '@' && S[i - 1] == '@') return cout << "No solution", 0;
    }
    rf(i,1,S.size() - 2) {
        if(S[i] == '@' && S[i + 2] == '@') return cout << "No solution", 0;
    }
    int cur = 0;
    rf(i,1,S.size() - 2) {
        //cout << i << endl;
        if(S[i] == '@') {
            cnt --;
            rf(j,cur, i+1) cout << S[j];
            cur = i + 2;
            i++;
            if(!cnt) break;
            if(i)cout << ",";
        }
    }
    rf(i,cur, S.size() - 1) cout << S[i];
    return 0;
}