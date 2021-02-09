#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct o {
  int i, j;
  char c;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> v(n);
  vector<o> cal(n);
  map<string, int> mp;
  string s0 = "";
  for (int i = 0; i < m; i++) {
    s0 += '0';
  }
  for (int i = 0; i < n; i++) {
    string s, tmp, op1, op, op2;
    cin >> s >> tmp >> op1;
    mp[s] = i;
    if (op1[0] != '0' && op1[0] != '1') {
      cin >> op >> op2;
      if (op1 == "?" && op2 == "?") {
        v[i] = (op == "XOR") ? s0 : "?";
      } else {
        int n1 = (op1 != "?") ? mp[op1] : -1;
        int n2 = (op2 != "?") ? mp[op2] : -1;
        cal[i] = {n1, n2, op[0]};
      }
    } else {
      v[i] = op1;
    }
  }
  string ans_mn = "", ans_mx = "";
  for (int i = 0; i < m; i++) {
    vector<int> cnt;
    for (int cur = 0; cur < 2; cur++) {
      vector<int> num(n);
      for (int j = 0; j < n; j++) {
        if (v[j] == "?") {
          num[j] = cur;
        } else if (v[j] != "") {
          num[j] = v[j][i] - '0';
        } else {
          int n1 = (cal[j].i == -1) ? cur : num[cal[j].i];
          int n2 = (cal[j].j == -1) ? cur : num[cal[j].j];
          if (cal[j].c == 'A') {
            num[j] = n1 & n2;
          } else if (cal[j].c == 'O') {
            num[j] = n1 | n2;
          } else {
            num[j] = n1 ^ n2;
          }
        }
      }
      cnt.push_back(count_if(num.begin(), num.end(), [](int x) {
        return x == 1;
      }));
    }
    if (cnt[0] < cnt[1]) {
      ans_mx += "1";
      ans_mn += "0";
    } else if (cnt[0] > cnt[1]) {
      ans_mx += "0";
      ans_mn += "1";
    } else {
      ans_mx += "0";
      ans_mn += "0";
    }
  }
  cout << ans_mn << "\n";
  cout << ans_mx << "\n";
}
