#include "../libs/genlib.h"
#include "../libs/testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int N = rnd.next(2, 10);

  int M = N - 1;
  int P = 0;
  cout << N << ' ' << M << ' ' << P << '\n';
  gen_tree(N, 0, 1);
  cout << '\n';
  int Q = 10;
  cout << Q << '\n';
  gen_array(Q, 1, 100);
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
