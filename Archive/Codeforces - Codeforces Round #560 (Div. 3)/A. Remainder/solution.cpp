#include <bits/stdc++.h>
using namespace std;

// 💖 Hi, thanks for using ICIE! 💖
// 🔧 To use a custom code template, set it in Settings(Ctrl+,) in "Icie Template List" entry 🔧
// 📝 If you spot any bugs or miss any features, create an issue at https://github.com/pustaczek/icie 📝
char a[200010];
int n,x,y;

int main() {
    cin >> n;
    cin >> x;
    cin >> y;

    int ans = 0;
    for(int i =1; i <= n;i++) cin >> a[i];
    for (int i = n; i >= n - x + 1; i--) {
        if (i != n - y) {
            if (a[i] != '0') ans++;
        } else if (a[i] != '1') ans++;
    }
    cout << ans ;
}