#include <vector>

#include "../../Script/genlib.h"
#include "../../Script/testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);
  int n = rnd.next(3, 100);
  cout << n << '\n';
  gen_array(n, 1, (int)1e9);
  cout << '\n';
  gen_weighted_tree(n, 1, (int)1e9);
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
