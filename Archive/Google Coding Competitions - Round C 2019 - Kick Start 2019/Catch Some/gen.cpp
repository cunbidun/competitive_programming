#include "../../Script/genlib.h"
#include "../../Script/testlib.h"
#include <vector>

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);
  cout << 1 << "\n";
  int n = rnd.next(1, 7);
  int k = rnd.next(1, n);
  cout << n << ' ' << k << '\n';
  gen_array(n, (int)1, (int)10);
  cout << "\n";
  gen_array(n, (int)900, (int)1000);
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
