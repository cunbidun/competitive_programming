#include "../../Script/genlib.h"
#include "../../Script/testlib.h"
#include <vector>

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int n = rnd.next(0, 5);
  int m = rnd.next(0, 5);
  int k = 1000;
  cout << n << " " << m << " " << k << "\n";
  for (int i = 1; i <= n; i++) {
    cout << "\"" << gen_string(10, 1, 1, 1, "", 1) << "\" " << rnd.next(1, 1000) << "\n";
  }
  for (int i = 1; i <= m; i++) {
    cout << rnd.next(1, 1000) << " \"" << gen_string(10, 1, 1, 1, "", ' ') << "\" " << rnd.next(1, 1000) << "\n";
  }

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
