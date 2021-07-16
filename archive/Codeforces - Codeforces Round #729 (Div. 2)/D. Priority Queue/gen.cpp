#include "../libs/genlib.h"
#include "../libs/testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int N = rnd.next(1, 10);
  cout << N << '\n';
  vector<int> a = gen_array(N, -1, 10, false);
  for (int i : a) {
    if (i == -1) {
      cout << "-\n";
    } else {
      cout << "+ " << i + 1 << '\n';
    }
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
