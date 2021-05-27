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
        DRandomTask solver = new DRandomTask();
        solver.solve(1, in, out);
        out.close();
    }

    static class DRandomTask {
        long[][] C = new long[70][70];
        long n;
        int k;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextLong();
            k = in.nextInt();
            calC();
            long l = 1, r = (long) 1e18;
            while (l != r) {
                if (l == r - 1) {
                    if (ch(l)) r = l;
                    else l = r;
                }
                long m = (l + r) >> 1;
                if (ch(m)) r = m;
                else l = m;
            }
            out.println(l);
        }

        private void calC() {
            C[0][0] = 1;
            for (int i = 1; i <= 60; i++) {
                for (int j = 0; j <= i; j++) {
                    if (j > 0) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
                    else C[i][j] = C[i - 1][j];
                }
            }
        }

        private boolean ch(long m) {
            return (cal(m * 2) - cal(m)) >= n;
        }

        private long cal(long x) {
            long res = 0;
            int cnt = 0;
            for (int i = 60; i >= 0; i--) {
                if (((x >> i) & 1) == 1) {
                    if (k >= cnt) {
                        res += C[i][k - cnt];
                        cnt++;
                    } else
                        break;
                }
            }
            return res;
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
