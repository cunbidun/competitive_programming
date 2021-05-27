package Code;

import Lib.Algorithm.MaxMin;

@SuppressWarnings("unused")
public class TheDictionary {

    public String find(int n, int m, int k) {
        int[][] f = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) f[i][0] = 1;
        for (int i = 1; i <= m; i++) f[0][i] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                f[i][j] = MaxMin.Min((int) 1e9 + 1, f[i - 1][j] + f[i][j - 1]);
            }
        if (f[n][m] < k)
            return "";
        StringBuilder ans = new StringBuilder();
        int cur = 0 ;
        int pickedA = 0;
        int pickedZ = 0;
        while (pickedA != n || pickedZ != m) {
            if (pickedA == n) {
                ans.append('z');
                pickedZ++;
                continue;
            }
            if (pickedZ == m) {
                ans.append('a');
                pickedA++;
                continue;
            }
            if (cur + f[n - pickedA - 1][m - pickedZ] >= k) {
                ans.append('a');
                pickedA++;
            } else {
                ans.append('z');
                cur += f[n - pickedA - 1][m - pickedZ];
                pickedZ++;
            }

        }
        return ans.toString();
    }
}
