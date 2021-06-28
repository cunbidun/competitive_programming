#include "../libs/genlib.h"
#include "../libs/testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int N = rnd.next(1, 10);
  int K = rnd.next(1, 3);
  cout << N << ' ' << K << '\n';
  vector<int> a;
  for (int i = 1; i <= N; i++) {
    a.push_back(i);
  }
  shuffle(a.begin(), a.end());

  for(int i : a) {
    cout << i << ' ';
  }
  cout << '\n';

  shuffle(a.begin(), a.end());
  for(int i : a) {
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
