#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
  registerTestlibCmd(argc, argv);
  if (argv[3] == std::string("___test_case/___na___")) {
    quitf(_fail, "undecided");
  }

  auto compute = [](string &A, string &B) -> int {
    int a = atoi(A.c_str());
    int b = atoi(B.c_str());
    int s = a + b;
    int d = 0;
    while (s > 0) {
      d += s % 10;
      s /= 10;
    }
    return d;
  };

  auto ans_a = ans.readToken();
  auto ans_b = ans.readToken();
  auto out_a = ouf.readToken();
  auto out_b = ouf.readToken();
  int solution = compute(out_a, out_b);
  int answer = compute(ans_a, ans_b);
  if (answer != solution) {
    quitf(_wa, "Different digit sum. solution return %d while answer return %d", solution, answer);
  } else {
    quitf(_ok, "OK");
  }

  if (!ans.seekEof() || !ouf.seekEof()) {
    quitf(_wa, "number of token differs");
  }
  quitf(_ok, "passed");
}
