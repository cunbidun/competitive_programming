package Code;

import java.util.Arrays;

@SuppressWarnings("unused")
public class DiceGames {
    public long countFormations(int[] sides) {
        int n = sides.length;
        Arrays.sort(sides, 0, n);
        long[][] f = new long[33][33];
        for (int i = 1; i <= sides[n - 1]; i++) f[n - 1][i] = 1;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 1; j <= sides[i]; j++) {
                for (int k = j; k <= sides[i + 1]; k++) f[i][j] += f[i + 1][k];
            }
        }
        long ans = 0;
        for (int i = 1; i <= sides[0]; i++) ans += f[0][i];
        return ans;
    }
}
