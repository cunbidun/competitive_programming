#include "../../Script/testlib.h"

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

int a[100];
int main(int argc, char *argv[]) {
  registerTestlibCmd(argc, argv);
  if (ans.seekEof()) {
    undecided();
  }
  string v_ans = ans.readToken();
  string v_ouf = ouf.readToken();

  if (v_ans != v_ouf) {
    quitf(_wa, "wrong answer\nYes/No differ");
  }
  if (v_ans == "NO") {
    ok();
  }
  int n = inf.readInt();
  n = inf.readInt();
  for (int i = 1; i <= n; i++) {
    a[i] = inf.readInt();
  }
  int x = ouf.readInt();
  int y = ouf.readInt();
  int z = ouf.readInt();

  int mx1 = 0, mx2 = 0;
  int mn = 1000000000;
  for (int i = 1; i <= x; i++) {
    mx1 = max(mx1, a[i]);
  }
  for (int i = x + 1; i <= x + y; i++) {
    mn = min(mn, a[i]);
  }
  for (int i = x + y + 1; i <= n; i++) {
    mx2 = max(mx2, a[i]);
  }
  if (mx1 == mx2 && mx1 == mn) {
    ok();
  }
  quitf(_wa, "wrong answer\nMax min is not correct");
}
