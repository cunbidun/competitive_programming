#include "genlib.hpp"
#include "testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);
  int N = 5;
  int M1 = 3;
  int M2 = 3;
  cout << N << ' ' << M1 << ' ' << M2 << '\n';
  gen_forest(N, M1, 1);
  cout << '\n';
  gen_forest(N, M2, 1);
  cout << '\n';
  char number_str[10];
  sprintf(number_str, "%d", test);
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
