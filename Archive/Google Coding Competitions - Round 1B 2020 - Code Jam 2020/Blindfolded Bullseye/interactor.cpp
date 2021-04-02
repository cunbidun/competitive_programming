#include <bits/stdc++.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;

ofstream screen, res;
ifstream in;

void WA(int num = 1) {
  res << "wrong answer\n";
  if (num == 1) {
    res << "too many questions" << endl;
  } else if (num == 2) {
    res << "incorrect format" << endl;
  } else {
    res << "extra tokens" << endl;
  }
}

void OK() {
  res << "accepted" << endl;
}

void interactor() {
  int t, A, B;
  in >> t >> A >> B;
  cout << t << ' ' << A << ' ' << B << endl;
  screen << "G" << t << ' ' << A << ' ' << B << endl;
  int ok = 1;
  while (t--) {
    int R, X, Y;
    in >> R >> X >> Y;
    int limit = 300;
    while (limit--) {
      int x, y;
      cin >> x >> y;
      if (abs(x) > 1e9 || abs(y) > 1e9) {
        WA(2);
      }
      screen << x << ' ' << y << endl;
      if (x == X && y == Y) {
        cout << "CENTER" << endl;
        screen << "GCENTER" << endl;
        break;
      }
      if (1LL * (x - X) * (x - X) + 1LL * (y - Y) * (y - Y) <= 1LL * R * R) {
        cout << "HIT" << endl;
        screen << "GHIT" << endl;
      } else {
        cout << "MISS" << endl;
        screen << "GMISS" << endl;
      }
    }
  }
  if (!ok) {
    WA(1);
  } else {
    OK();
  }
}

int main(int argc, char *argv[]) {
  char *que = "/tmp/que";
  char *ans = "/tmp/ans";
  mkfifo(que, 0777);
  mkfifo(ans, 0777);

  pid_t pid = fork();
  if (pid < 0) {
    return 1;
  }
  if (pid == 0) {
    int fd_read = open(ans, O_RDONLY);
    int fd_write = open(que, O_WRONLY);
    dup2(fd_read, 0);
    dup2(fd_write, 1);
    execl("solution", "solution", NULL);
  } else {
    int fd_write = open(ans, O_WRONLY);
    int fd_read = open(que, O_RDONLY);
    dup2(fd_read, 0);
    dup2(fd_write, 1);

    in.open(argv[1]);
    screen.open(argv[2]);
    res.open(argv[3]);

    interactor();

    in.close();
    screen.close();
    res.close();
  }
  unlink(que);
  unlink(ans);
  return 0;
}
