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

int n, m;
ii ans[N];
vector<iii> edge;
set<int> connected[N];
int smallest = 2;
int pos = 2;
int cur = 2;

int find() {
    if(smallest >= cur) return -1;
    while (connected[smallest].find(pos) != connected[smallest].end()) {
        pos++;
        if (pos >= cur) {
            smallest++;
            pos = 2;
            return find();
        }
    }
    return pos;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    rf(i, 1, m) {
        connected[i].insert(i);
        int a, b;
        cin >> a >> b;
        edge.pb({{a, 1 - b}, i});
    }
    sort(all(edge));
    for (iii e : edge) {
        int idx = e.second;
        if (e.first.second == 0) {
            connected[1].insert(cur);
            connected[cur].insert(1);
            ans[idx] = {1, cur++};
        } else {
            int next = find();
            if(next == -1)
                return cout << -1 << "\n", 0;
            ans[idx] = {smallest, next};
            connected[smallest].insert(next);
            connected[next].insert(smallest);
        }
    }
    rf(i, 1, m) cout << ans[i].first << " " << ans[i].second << "\n";
}