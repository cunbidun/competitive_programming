#include "../../testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerTestlibCmd(argc, argv);
  vector<string> v_ans, v_ouf;

  while (!ans.seekEof()) {
    v_ans.push_back(ans.readToken());
  }
  while (!ouf.seekEof()) {
    v_ouf.push_back(ouf.readToken());
  }
  if (v_ans.size() == 0) {
    quitf(_ok, "undecided\n");
  }
  if (v_ans.size() != v_ouf.size()) {
    quitf(_wa, "wrong answer\nnumber of token differs");
  }
  for (int i = 1; i <= v_ans.size(); i++) {
    string j, p;
    j = v_ans[i - 1];
    p = v_ouf[i - 1];
    if (j != p) {
      quitf(_wa, "wrong answer\n%d%s words differ - expected: '%s', found: '%s'", i,
            englishEnding(i).c_str(), compress(j).c_str(), compress(p).c_str());
    }
  }
  quitf(_ok, "accepted\n");
}
