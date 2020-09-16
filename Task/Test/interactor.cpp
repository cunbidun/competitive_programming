#include <bits/stdc++.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;

void print(string s) {
  cout << s << endl;
  cerr << "\033[1;32m" << s << "\033[0m" << endl;
}
void interactor() {
  srand(time(NULL));

  int bound = (1 << 3);
  int a = rand() % bound;
  print(to_string(bound));
  while (1) {
    int num;
    cin >> num;
    cerr << num << endl;

    if (num == bound + 1) {
      print("Incorrect!");
      break;
    } else if (num == a) {
      print("1");
      break;
    } else {
      print("0");
    }
  }
}

int main() {
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

    interactor();
  }
  unlink(que);
  unlink(ans);
  return 0;
}
