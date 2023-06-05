#include "genlib.hpp"
#include "testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int N = rnd.next(3, 5) * 2;
  int Q = rnd.next(1, 10);
  auto arr = gen_array(N, 0, 1, 0);
  cout << N << " " << Q << '\n';
  for (auto i : arr) {
    if (i) {
      cout << "(";
    } else {
      cout << ")";
    }
  }
  cout << "\n";
  gen_array(Q, 1, N);

  char number_str[10];
  snprintf(number_str, 10, "%d", test);
  std::rename(number_str, ('S' + to_string(test) + ".in").c_str());
}

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int NUM_TEST = opt<int>(2);
  for (int i = 0; i < NUM_TEST; i++) {
    writeTest(i);
  }
  return 0;
}
