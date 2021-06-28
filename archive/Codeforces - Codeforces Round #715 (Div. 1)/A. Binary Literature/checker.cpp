#include "../libs/testlib.h"

using namespace std;

void ok() {
  while (!ouf.seekEof()) {
    ouf.readLine();
  }
  quitf(_ok, "accepted\n");
}

void undecided() {
  while (!ouf.seekEof()) {
    ouf.readLine();
  }
  quitf(_ok, "undecided\n");
}

bool is_sub_string(string &a, string &b) {
  int p = 0;
  for (int i = 0; i < (int)a.size(); i++) {
    if (p < (int)b.size() && b[p] == a[i]) {
      p++;
    }
  }
  return p == (int)b.size();
}
int main(int argc, char *argv[]) {
  registerTestlibCmd(argc, argv);
  int T = inf.readInt();
  for (int j = 1; j <= T; j++) {
    int N = inf.readInt();
    string res = ouf.readString();
    if ((int)res.size() > 3 * N) {
      quitf(_wa, "wrong answer\ntestcase %d too long", j);
    }
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
      string s = inf.readToken();
      if (is_sub_string(res, s)) {
        cnt++;
      }
    }
    if (cnt < 2) {
      quitf(_wa, "wrong answer\n testcase %d", j);
    }
  }
  ok();
}
