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

int main(int argc, char *argv[]) {
  registerTestlibCmd(argc, argv);
  int n = inf.readInt();
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = inf.readInt();
  }
  vector<string> v_ouf;
  string ans = ouf.readToken();
  if (ans == "NO") {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          for (int l = k + 1; l < n; l++) {
            if (a[i] + a[j] == a[l] + a[k]) {
              quitf(_wa, "wrong answer\n");
            }
          }
        }
      }
    }

    quitf(_ok, "accepted\n");
  }
  vector<int> l;
  while (!ouf.seekEof()) {
    l.push_back(ouf.readInt());
  }
  if (a[l[0] - 1] + a[l[1] - 1] == a[l[2] - 1] + a[l[3] - 1]) {
    quitf(_ok, "accepted\n");
  }
  quitf(_wa, "wrong answer\n");
}
