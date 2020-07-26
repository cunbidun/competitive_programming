package Code;

@SuppressWarnings("unused")
public class TestBettingStrategy {

    public double winProbability(int initSum, int goalSum, int rounds, int prob) {
        double[][][] f = new double[2][1001][12];
        double p = prob / 100.0;
        double ans = 0.0;
        f[0][initSum][0] = 1.0;
        for (int i = 1; i <= rounds; i++) {
            for (int j = 1; j <= goalSum; j++) {

                for (int k = 0; 2 * (1 << k) <= j; k++)
                    f[1][j][0] += f[0][j - (1 << k)][k] * p;

                for (int k = 10; k >= 0; k--)
                    if (j + (1 << k) <= goalSum)
                        f[1][j][k + 1] += f[0][j + (1 << k)][k] * (1 - p);
            }

            for (int k = 0; k <= 11; k++)
                ans += f[1][goalSum][k];

            for (int j = 0; j <= goalSum; j++)
                for (int k = 0; k <= 11; k++) {
                    f[0][j][k] = f[1][j][k];
                    f[1][j][k] = 0.0;
                }

        }

        return ans;
    }
}
