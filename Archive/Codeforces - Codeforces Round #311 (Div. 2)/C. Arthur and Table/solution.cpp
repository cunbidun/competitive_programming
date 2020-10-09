/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author cunbidun
 */

#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include <utility>
#include <tuple>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
/**
 * Matrix of Char MC(Row, Col, atoz?, AtoZ?, 1to9?, Custom)
 * Forest: F(NumNode, NumEdge, StartAt)
 * Graph: G(NumNode, NumEdge, StartAt, isConnected?, isMultiEdge?, iSelfLoop?)
 * Weighted Graph: WG(NumNode, NumEdge, StartAt, isConnected?, isMultiEdge?, iSelfLoop?, minW, maxW)
 */
namespace impl {
    using Random = std::mt19937;
}

inline impl::Random &randomEngine() {
    static std::random_device device;
    static impl::Random engine(device());
    return engine;
}

inline int randomInteger(int to) {
    std::uniform_int_distribution<int> d(0, to);
    return d(randomEngine());
}

inline int randInt(int from, int to) {
    return from + randomInteger(to - from);
}

inline vi randArr(int l, int min, int max) {
    vi a;
    for (int i = 1; i <= l; i++)
        a.pb(randInt(min, max));
    return a;
}

inline vector<pair<int, int>> randArrPair(int l, bool less, int min, int max) {
    vector<ii> a;
    for (int i = 1; i <= l; i++) {
        int first = randInt(min, max);
        int second = randInt(min, max);
        if (less && first > second) {
            int t = first;
            first = second;
            second = t;
        }
        a.pb(mp(first, second));
    }
    return a;
}

inline vector<vi> rand2DArr(int r, int c, int min, int max) {
    vector<vi> a(r, vi());
    for (int i = 0; i < r; i++)
        a[i] = randArr(c, min, max);
    return a;
}

inline string randString(int l, string sample) {
    string toReturn = "";
    int size = sz(sample);
    while (l--) {
        int tmp = randInt(0, size);

        toReturn += sample[randInt(0, size - 1)];
    }
    return toReturn;
}

inline string randString(int l, bool lower, bool upper, bool number) {
    string sample = "";
    string lowList = "abcdefghijklmnopqrstuvwxyz";
    string upList = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numList = "0123456789";
    if (lower) sample += lowList;
    if (upper) sample += upList;
    if (number) sample += numList;
    return randString(l, sample);
}

inline vii randTree(int n) {
    vii toReturn;
    for (int i = 2; i <= n; i++)
        toReturn.push_back({i, randInt(1, i - 1)});
    return toReturn;
}

inline vector<iii> randTree(int n, int min, int max) {
    vii tree = randTree(n);
    vector<iii> toReturn;
    for (ii p:tree) {
        toReturn.push_back(mp(mp(p.first, p.second), randInt(min, max)));
    }
    return toReturn;
}

inline vii randDAG(int v, int e) {
    set<string> set;
    vii DAG;
    for (int i = 0; i < e; i++) {
        int tmp1 = -1;
        int tmp2 = -1;
        while (tmp1 == tmp2 || set.find(to_string(tmp1) + to_string(tmp2)) != set.end()) {
            int pos = randInt(1, v - 1);
            tmp1 = pos;
            tmp2 = randInt(pos + 1, v);
        }
        DAG.pb(mp(tmp1, tmp2));
        set.insert(to_string(tmp1) + to_string(tmp2));
    }
    return DAG;
}

inline vector<iii> randDAG(int v, int e, int min, int max) {
    vii DAG = randDAG(v, e);
    vector<iii> toReturn;
    for (ii p:DAG) {
        toReturn.push_back(mp(mp(p.first, p.second), randInt(min, max)));
    }
    return toReturn;
}

inline string to_string(vii list) {
    string res = "";
    for (int i = 0; i < sz(list); i++) {
        ii p = list[i];
        res += to_string(p.first) + " " + to_string(p.second);
        if (i != sz(list) - 1) res += "\n";
    }
    return res;
}

inline string to_string(vector<iii> list) {
    string res = "";
    for (int i = 0; i < sz(list); i++) {
        iii p = list[i];
        res += to_string(p.first.first) + " " + to_string(p.first.second) + " " + to_string(p.second);
        if (i != sz(list) - 1) res += "\n";
    }
    return res;
}

inline string to_string(vi list) {
    string res = "";
    for (int i = 0; i < sz(list); i++) {
        res += to_string(list[i]) + " ";
    }
    return res;
}

inline string to_string(vector<vi> list) {
    string res = "";
    for (int i = 0; i < sz(list); i++) {
        res += to_string(list[i]) + " ";
        if (i != sz(list) - 1) res += "\n";
    }
    return res;
}

#define F first
#define S second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define rf(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) //cout << (#x) << " = " << (x) << endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 2e9;

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

class Task557C {
public:
    vi bit;
    vi pos;
    vi sum;
    vi size;
    int n;
    vi A;
    vi B;
    vector<pair<ii, int>> a;
    indexed_set set;

    void update(int p, int val) {
        while (p < N) {
            bit[p] = bit[p] + val;
            p += p & -p;
        }
    }

    int get(int p) {
        int res = 0;
        while (p >= 1) {
            res = res + bit[p];
            p -= p & -p;
        }
        return res;
    }

    int get(int l, int r) {
        return get(r) - get(l - 1);
    }

    static bool cmp(pair<ii, int> a, pair<ii, int> b) {
        return a.F.S < b.F.S;
    }

    void solve(istream &in, ostream &out) {
        bit.assign(N, 0);
        pos.assign(N, 0);
        sum.assign(N, 0);
        size.assign(N, 0);
        A.assign(N, 0);
        B.assign(N, 0);
        in >> n;
        rf(i, 0, n - 1) {
            in >> A[i];
            size[A[i]]++;
        }

        rf(i, 0, n - 1)in >> B[i];

        rf(i, 0, n - 1) {
            a.pb(mp(mp(A[i], B[i]), 0));

        }
        int p = 0;
        sort(all(a), cmp);
        rf(i, 0, n - 1) a[i].S = ++p;
        sort(all(a));
        rf(i, 0, n - 1) sum[a[i].F.F] += a[i].F.S;
        rf(i, 1, N - 1) sum[i] += sum[i - 1];
        watch(to_string(a));
        int ans = MOD;
        rf(i, 0, n - 1) {
            if (i == 0 || a[i].F.F != a[i - 1].F.F) {
                watch(a[i].F.F);
                int bigger = sum[N - 1] - sum[a[i].F.F];
                watch(bigger);
                int needDel = i - (size[a[i].F.F] - 1);
                watch(needDel);
                int res = sum[N - 1] - sum[a[i].F.F];
                if (needDel > 0) res += get(*set.find_by_order(needDel - 1));
                watch(res);
                ans = min(ans, res);
                watch(a[i].S);
                watch ("--------------------");
            }
            update(a[i].S, a[i].F.S);
            set.insert(a[i].S);
        }

        out << ans << "\n";
    }

};

class TestCase {
public:
    static constexpr int numTest = 0;
    static constexpr bool haveAns = false;

    static void generateTest(ostream &test) {
    }

    static void solve(istream &in, ostream &out) {
    }
};

class Checker {
public:
    static constexpr double arg = 0.0;

    static bool check(istream &in, istream &out) {
    }
};



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   	Task557C solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    out << fixed << setprecision(10);
	solver.solve(in, out);
	return 0;
}