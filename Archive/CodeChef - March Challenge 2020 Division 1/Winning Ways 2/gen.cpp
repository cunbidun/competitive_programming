// Mo
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a) memset(a, 0, sizeof(a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define endl '\n'
#define init(n)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        \
    int n;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             \
    in >> n;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           \
    int a[n];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \
    rep(i, n) in >> a[i];
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long int> vll;
typedef vector<pii> vii;
ll p = 998244353;
ll const N = 1e3 + 5;
int n, q;
ll fac[N];
ll invfac[N];

inline ll add(ll a, ll b) {
    ll t = (a + b);
    if (t >= p)
        t -= p;
    return t;
}
inline ll sub(ll a, ll b) {
    ll t = a - b + p;
    t = t % p;
    return t;
}
inline ll power(ll a, ll x) {
    ll r = 1;
    while (x != 0) {
        if (x % 2 == 1) {
            r = r * a;
            r %= p;
        }
        a = a * a;
        a %= p;
        x = x / 2;
    }
    return r;
}
inline ll mul(ll a, ll b) {
    ll t = (a * b);
    if (t >= p)
        t %= p;
    return t;
}
inline ll divide(ll a, ll b) { return mul(a, power(b, p - 2)); }
inline ll npr(ll n, ll r) {
    if (n < r)
        return 0;
    return mul(fac[n], invfac[n - r]);
}
inline ll ncr(ll n, ll r) {
    if (n < r)
        return 0;
    return mul(fac[n], mul(invfac[n - r], invfac[r]));
}
struct node {
    int l, r, i;
};
int answer = 0;
int arr[100001];
int s;
inline int setBitNumber(int n) {
    if (n == 0)
        return 0;

    int msb = -1;
    while (n != 0) {
        n = n / 2;
        msb++;
    }

    return (msb);
}
unordered_map<int, int> m[18];
bool comp(node a, node b) {
    if ((a.l / s) == (b.l / s)) {
        return a.r < b.r;
    }
    return (a.l / s) < (b.l / s);
}
inline void add(int pos, int *a, vector<int> &v) {
    if (pos == 0)
        return;
    int x = a[pos];
    arr[x]++;
    int cnt = arr[x];
    answer ^= (cnt ^ (cnt - 1));
    if (cnt > 0) {
        int x = cnt;
        int j = 0;
        while (x != 0) {
            if (x % 2) {
                m[j][cnt]++;
            }
            x = x / 2;
            j++;
        }
    }
    if (cnt > 1) {
        int x = cnt - 1;
        int j = 0;
        while (x != 0) {
            if (x % 2) {
                m[j][cnt - 1]--;
                if (m[j][cnt - 1] == 0) {
                    m[j].erase(cnt - 1);
                }
            }
            x = x / 2;
            j++;
        }
    }
}
inline void remove(int pos, int *a, vector<int> &v) {
    if (pos == 0)
        return;
    int x = a[pos];
    arr[x]--;
    int cnt = arr[x];
    answer ^= (cnt ^ (cnt + 1));
    if (cnt + 1 >= 1) {
        int x = cnt + 1;
        int j = 0;
        while (x != 0) {
            if (x % 2) {
                m[j][cnt + 1]--;
                if (m[j][cnt + 1] == 0) {
                    m[j].erase(cnt + 1);
                }
            }
            x = x / 2;
            j++;
        }
    }
    if (cnt > 0) {
        int x = cnt;
        int j = 0;
        while (x != 0) {
            if (x % 2) {
                m[j][cnt]++;
            }
            x = x / 2;
            j++;
        }
    }
}
ofstream out;
stringstream in;

string TextFileToString(string filename) {
    ostringstream dosString(ios::out | ios::binary); // *** binary
    ifstream inFile(filename.c_str());

    string line;
    while (getline(inFile, line))
        dosString << line << "\r\n";

    return dosString.str();
}

// get correct input format from rawInput
void get(string name) { in << TextFileToString(name); }

// use in and out to read and write to solution file
void solve() {
    int T;
    in >> T;
    fac[0] = 1;
    for (ll i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i;
        fac[i] %= p;
    }
    for (ll i = 0; i < N; i++) {
        invfac[i] = power(fac[i], p - 2);
    }
    while (T--) {
        in >> n;
        rep(i, 18) m[i].clear();
        answer = 0;
        int a[n + 1];
        rep(i, n) in >> a[i + 1];
        s = 64;
        map<int, int> mp;
        rep(i, n) mp[a[i + 1]] = 1;
        int k = 1;
        for (auto &j : mp) {
            j.snd = k;
            k++;
        }
        rep(i, n) { a[i + 1] = mp[a[i + 1]]; }
        in >> q;
        node que[q];
        rep(i, q) in >> (que[i].l) >> (que[i].r), que[i].i = (i);
        sort(que, que + q, comp);
        int ans[q];
        int cl = 0, cr = 0;
        memset(arr, 0, sizeof(arr));
        a[0] = 0;
        vector<int> v;
        rep(i, q) {
            int l = que[i].l, r = que[i].r;
            while (cl < l) {
                remove(cl, a, v);
                cl++;
            }
            while (cl > l) {
                cl--;
                add(cl, a, v);
            }
            while (cr < r) {
                cr++;
                add(cr, a, v);
            }
            while (cr > r) {
                remove(cr, a, v);
                cr--;
            }
            int val = 0;
            if (answer == 0) {
                ans[que[i].i] = 0;
                continue;
            }
            int msb = setBitNumber(answer);
            for (auto j : m[msb]) {
                val = add(val, mul(j.snd, ncr(j.fst, j.fst ^ answer)));
            }
            ans[que[i].i] = val;
        }
        rep(i, q) { out << ans[i] << endl; }
    }
}

int main(int argc, char *argv[]) {
    string name = string(argv[1]);
    get(name);
    out.open(name);
    out << in.str();
    out.close();
    if (argv[2][0] == 't') {
        name.pop_back();
        name.pop_back();
        name.pop_back();
        out.open(name + ".out");
        out << fixed << setprecision(10);
        solve();
        out.close();
    }
}
