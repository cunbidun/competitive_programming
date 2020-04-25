#include <bits/stdc++.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;

int sgn(int a) { return (a > 0) - (0 > a); }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
void interactor() {
    cerr << n << endl;
    int asked_questions = 0;
    char type;
    int m;
    while (1) {
        cin >> type >> m;
        cerr << type << " " << m << endl;

        asked_questions++;
        if ((type != '?' && type != '!')) {
            cerr << "Incorrect question." << endl;
            break;
        }

        if (type == '?') {
            if (asked_questions == 35) {
                cerr << "To many questions." << endl;
                break;
            }
            if (n == m) {
                cout << 0 << endl;
                cerr << 0 << endl;
            }
            if (n > m) {
                cout << 1 << endl;
                cerr << 1 << endl;
            }
            if (n < m) {
                cout << -1 << endl;
                cerr << -1 << endl;
            }
        } else {
            if (m == n)
                cerr << "Correct solution." << endl;
            else
                cerr << "Incorrect solution." << endl;
            break;
        }
    }
}

int main() {
    char *que = "/tmp/que";
    char *ans = "/tmp/ans";
    mkfifo(que, 0777);
    mkfifo(ans, 0777);

    pid_t pid = fork();
    if (pid < 0)
        return 1;
    if (pid == 0) {
        int fd_read = open(ans, O_RDONLY);
        int fd_write = open(que, O_WRONLY);
        dup2(fd_read, 0);
        dup2(fd_write, 1);
        execl("solution", "solution", NULL);
    } else {
        cin  >> n;
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