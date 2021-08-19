#include "../libs/genlib.h"
#include "../libs/testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int n = rnd.next(1, 5);
  int k = rnd.next(n, 7);
  int s = rnd.next(k, 50);
  cout << n << ' ' << k << '\n';
  vector<int> a = gen_array(n, 1, 10, 0);
  for (int i : a) {
    s -= i;
  }
  if (s > 0) {
    a[0] += s;
  }
  for (int i : a) {
    cout << i << ' ';
  }
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
