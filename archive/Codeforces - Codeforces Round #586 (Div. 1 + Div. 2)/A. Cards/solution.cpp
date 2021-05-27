#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt1 = 0;
    int cnt0 = 0;
    for (int i = 1; i <= n; i++) {
        char tmp;
        cin >> tmp;
        if (tmp == 'z')
            cnt0++;
        if (tmp == 'n')
            cnt1++;
    }
    while (cnt1--)
        cout << 1 << " ";
    while (cnt0--)
        cout << 0 << " ";
}