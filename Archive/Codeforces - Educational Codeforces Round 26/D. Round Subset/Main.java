import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DRoundSubset solver = new DRoundSubset();
        solver.solve(1, in, out);
        out.close();
    }

    static class DRoundSubset {
        static final int MAXA = (int) 2e2 + 10;
        int[] d2 = new int[MAXA];
        int[] d5 = new int[MAXA];

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            long[] a = new long[MAXA];

            for (int i = 1; i <= n; i++) {
                a[i] = in.nextLong();
                process(a[i], i);
            }
            int[][] f = new int[MAXA][26 * MAXA];
            for (int[] x : f) {
                Arrays.fill(x, -1);
            }
            f[0][0] = 0;
            for (int i = 1; i <= n; i++) {
                //for (int j = min(i, k); j >= 0; j--)
                for (int j = Math.min(i, k); j >= 0; j--)
                    for (int l = 0; l <= 26 * n; l++)
                        if (f[j][l] != -1) {
                            if (f[j + 1][l + d5[i]] < f[j][l] + d2[i]) {
                                f[j + 1][l + d5[i]] = f[j][l] + d2[i];
                                // out.println(i + " " + j  + " " + l + " -> " + (j + 1) + " " + (l + d5[i]));
                            }
                        }
            }
            int ans = 0;
            for (int i = 0; i <= 26 * n; i++) {
                ans = Math.max(ans, Math.min(f[k][i], i));
            }
            out.println(ans);
        }

        private void process(long l, int i) {
            while (l % 2 == 0) {
                l /= 2;
                d2[i]++;
            }
            while (l % 5 == 0) {
                l /= 5;
                d5[i]++;
            }
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}