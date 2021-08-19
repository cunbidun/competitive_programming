#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct node {
  int value;
  int x;
  int y;
};
char m[586][586];
int f[586][586];
int movex[8] = {0, -2, -1, 0, 1, 2};
int movey[8] = {0, -2, -1, 0, 1, 2};
bool operator<(const node &a, const node &b) {
  return a.value > b.value;
}
int h, w;
priority_queue<node> que;
void bfs() {
  node e;
  e.x = 1;
  e.y = 1;
  e.value = 0;
  que.push(e);
  while (!que.empty()) {
    node now = que.top();
    que.pop();
    int nowx = now.x;
    int nowy = now.y;
    int nowv = now.value;
    if (nowv > f[nowx][nowy])
      continue;
    for (int i = 1; i <= 5; i++) {
      for (int j = 1; j <= 5; j++) {
        if ((i == 1 && j == 1) || (i == 1 && j == 5) || (i == 5 && j == 1) || (i == 5 && j == 5))
          continue;
        int newx = nowx + movex[i];
        int newy = nowy + movey[j];
        if (newx <= 0 || newy <= 0 || newx > h || newy > w)
          continue;
        if (((i % 2 == 0 && j == 3) || (j % 2 == 0) && i == 3) && m[newx][newy] == '.' && f[newx][newy] > f[nowx][nowy]) {
          node e = {nowv, newx, newy};
          que.push(e);
          f[newx][newy] = nowv;
        }
        if (f[newx][newy] > nowv + 1) {
          node e = {nowv + 1, newx, newy};
          que.push(e);
          f[newx][newy] = nowv + 1;
        }
      }
    }
  }
  return;
}
int main() {

  cin >> h >> w;
  string s;
  for (int i = 1; i <= h; i++) {
    cin >> s;
    for (int j = 1; j <= w; j++) {
      m[i][j] = s[j - 1];
    }
  }

  memset(f, 0x3f, sizeof(f));
  f[1][1] = 0;
  bfs();
  cout << f[h][w] << endl;
  // for (int i = 1; i <= h; i++) {
  //   for (int j = 1; j <= w; j++) {
  //     cout << f[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  return 0;
}
