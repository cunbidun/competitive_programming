package Code;

import Lib.Algorithm.Math.Op;
import Lib.Algorithm.Math.PrimeNumberAlgorithm;
import org.omg.CORBA.INTERNAL;

import javax.naming.PartialResultException;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;

@SuppressWarnings("unused")
public class MegaFactorialDiv2 {
    public int countDivisors(int N, int K) {
        int MOD = (int) 1e9 + 9;
        PrimeNumberAlgorithm gen = new PrimeNumberAlgorithm(1000);
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 1; i <= N; i++) if (gen.isPrime(i)) list.add(i);
        int[][] fac = new int[N + 1][list.size() + 1];
        for (int i = 2; i <= N; i++) {
            for (int j = 0; j < list.size(); j++) fac[i][j + 1] = fac[i - 1][j + 1];
            for (int j = 0; j < list.size(); j++) {
                int tmp = list.get(j);
                int num = i;
                while (num % tmp == 0) {
                    fac[i][j + 1]++;
                    num /= tmp;
                }
            }
        }
        if (K == 1) {
            int ans = 1;
            for (int i = 0; i < list.size(); i++) ans = Op.mulMod(ans, (fac[N][i + 1] + 1), MOD);
            return ans;
        }

        int[][] f = new int[N + 1][K + 1];
        for (int i = 1; i <= N; i++) f[i][1] = 1;
        for (int i = 1; i <= K; i++) f[1][i] = 1;

        for (int i = 2; i <= N; i++)
            for (int j = 2; j <= K; j++)
                f[i][j] = Op.addMod(f[i - 1][j], f[i][j - 1], MOD);


        for (int i = 2; i <= N; i++)
            for (int j = 1; j <= list.size(); j++)
                fac[i][j] = Op.mulMod(fac[i][j], f[N - i + 1][K - 1], MOD);

        int[] pow = new int[list.size() + 1];
        Arrays.fill(pow, 1);

        for (int i = 2; i <= N; i++)
            for (int j = 1; j <= list.size(); j++)
                pow[j] = (pow[j] + fac[i][j]) % MOD;

        int ans = 1;
        for (int i = 0; i < list.size(); i++)
            ans = Op.mulMod(ans, pow[i + 1], MOD);
        return ans;
    }
}
