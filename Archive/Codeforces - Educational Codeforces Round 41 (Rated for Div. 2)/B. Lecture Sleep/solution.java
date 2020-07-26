import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        BLectureSleep solver = new BLectureSleep();
        solver.solve(1, in, out);
        out.close();
    }

    static class BLectureSleep {
        static final int MAXA = (int) 1e5 + 10;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            int[] a = new int[MAXA];
            int[] st = new int[MAXA];
            int[] sum = new int[MAXA];
            int[] tot = new int[MAXA];
            for (int i = 1; i <= n; i++) {
                a[i] = in.nextInt();
            }

            for (int i = 1; i <= n; i++) {
                st[i] = in.nextInt();
                sum[i] = sum[i - 1];
                tot[i] = tot[i - 1] + a[i];
                if (st[i] == 1) {
                    sum[i] += a[i];
                }
            }

            int ans = 0;
            for (int i = 1; i <= n - k + 1; i++) {
                ans = Math.max(ans, sum[i - 1] + tot[i + k - 1] - tot[i - 1] + sum[n] - sum[i + k - 1]);
            }
            out.println(ans);
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

    }
}