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

void OK() { res << "accepted" << endl; }

void interactor() {
  int n;
  in >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    in >> a[i];
  }
  cout << n << endl;
  screen << "G" << n << endl;
  int limit = n + 1;
  while (limit--) {
    string type;
    cin >> type;
    screen << type << " ";
    vector<int> b(n + 1);
    if (type == "!") {
      for (int i = 1; i <= n; i++) {
        cin >> b[i];
        screen << b[i] << " ";
      }
      screen << endl;
      for (int i = 1; i <= n; i++) {
        if (b[i] != a[i]) {
          WA(0);
        }
      }
      OK();
      return;
    } else {
      int i, j;
      cin >> i >> j;
      screen << i << " " << j << endl;
      if (i < 1 || j < 1 || n < i || n < j) {
        WA(2);
        return;
      }
      if (type == "AND") {
        cout << (a[i] & a[j]) << endl;
        screen << "G" << (a[i] & a[j]) << endl;
      } else if (type == "OR") {
        cout << (a[i] | a[j]) << endl;
        screen << "G" << (a[i] | a[j]) << endl;
      } else if (type == "XOR") {
        cout << (a[i] ^ a[j]) << endl;
        screen << "G" << (a[i] ^ a[j]) << endl;
      } else {
        WA(2);
        return;
      }
    }
  }
  WA(1);
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