#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerTestlibCmd(argc, argv);

  int T = inf.readInt();
  while (T--) {
    int N = inf.readInt();
    int Q = inf.readInt();
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
      a[i] = inf.readInt();
    }
    for (int t = 1; t <= Q; t++) {
      int L, R;
      L = inf.readInt();
      R = inf.readInt();
      int p1 = ouf.readInt();
      int p2 = ouf.readInt();
      int j1 = ans.readInt();
      int j2 = ans.readInt();
      if (p1 > p2 || p1 < L || R < p2) {
        quitf(_wa, "Invalid range on test %d", t);
      }
      if (p2 - p1 != j2 - j1) {
        quitf(_wa, "Range too long on test %d", t);
      }
    }
  }
  if (!ans.seekEof() || !ouf.seekEof()) {
    quitf(_wa, "number of token differs");
  }
  quitf(_ok, "");
}
