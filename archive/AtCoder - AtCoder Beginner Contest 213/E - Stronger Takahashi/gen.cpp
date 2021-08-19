#include "../libs/genlib.h"
#include "../libs/testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int H = rnd.next(2, 10);
  int W = rnd.next(2, 10);
  cout << H << ' ' << W << '\n';
  for (int i = 0; i < H; i++) {
    string a = gen_string(W, 0, 0, 0, ".##", 0);
    if (i == 0) {
      a[0] = '.';
    }
    if (i == H - 1) {
      a[a.size() - 1] = '.';
    }
    for (char c : a) {
      cout << c;
    }
    cout << '\n';
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
