#include "../../Script/genlib.h"
#include "../../Script/testlib.h"
#include <vector>

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  char number_str[10];
  int N = rnd.next(1, 100);
  int A = rnd.next(1, 100);
  int R = rnd.next(1, 100);
  int M = rnd.next(1, 100);
  cout << N << ' ' << A << ' ' << R << ' ' << M << '\n';
  gen_array(N, 1, 100);
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
