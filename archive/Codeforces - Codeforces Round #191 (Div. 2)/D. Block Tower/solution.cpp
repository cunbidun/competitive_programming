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

const int INF = 2e9 + 7;
const int MAXA = 505;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;
const double PI = 3.14159265358979323846264;
typedef pair<int, int> ii;
typedef pair<char, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m, ch[MAXA][MAXA];
char a[MAXA][MAXA];
bool visited[MAXA][MAXA];
ii par[MAXA][MAXA];
vector<iii> ans;

bool inside(int i, int j) {
    if(i == 0 || j == 0 || i > n || j > m || a[i][j] == '#') return 0;
    return 1;
}

void dfs(int i, int j) {
    visited[i][j] = 1;
    rf(k, 0, 3) {
        if(!visited[i + dx[k]][j + dy[k]] && inside(i + dx[k], j + dy[k])) {
            par[i + dx[k]][j + dy[k]] = ii(i,j);
            ch[i][j] ++;
            dfs(i + dx[k], j + dy[k]);
        }
    }
    if(!ch[i][j] && par[i][j] != ii(0,0)) {
        ans.pb(iii('B', ii(par[i][j].F, par[i][j].S)));
        ans.pb(iii('R', ii(i,j)));
        ans.pb(iii('D', ii(par[i][j].F, par[i][j].S)));
        ch[par[i][j].F][par[i][j].S] --;
    }
    else ans.pb(iii('B', ii(i,j)));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    cin >> n >> m;
    rf(i, 1, n) rf(j, 1, m) cin >> a[i][j];
    rf(i, 1, n) rf(j, 1, m) if(!visited[i][j] && a[i][j] != '#') {
        dfs(i, j);
    }
    cout << ans.size() << endl;
    rf(i,0,(int)ans.size() - 1) printf("%c %d %d\n", ans[i].F, ans[i].S.F, ans[i].S.S);
    return 0;
}