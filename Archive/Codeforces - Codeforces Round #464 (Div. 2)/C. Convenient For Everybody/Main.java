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
        CConvenientForEverybody solver = new CConvenientForEverybody();
        solver.solve(1, in, out);
        out.close();
    }

    static class CConvenientForEverybody {
        static final int MAXA = (int) 1e5 + 10;
        static final int INF = (int) 2e9 + 7;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[MAXA];
            int[] s = new int[MAXA];
            for (int i = 1; i <= n; i++) {
                a[i] = in.nextInt();
                s[i] = s[i - 1] + a[i];
            }
            int ss = in.nextInt();
            int ff = in.nextInt();
            int dis = ff - ss;
            int ans = 0;
            int t = 0;
            for (int i = 1; i <= n - dis + 1; i++) {
                int tmp = s[i + dis - 1] - s[i - 1];
                if (ans < tmp) {
                    ans = tmp;
                    t = i;
                }
            }
            for (int i = n - dis + 2; i <= n; i++) {
                int tmp = s[n] - s[i - 1] + s[dis - (n - i + 1)];
                if (ans < tmp) {
                    ans = tmp;
                    t = i;
                }
            }
            boolean ch[] = new boolean[MAXA];
            for (int i = 1; i <= n - dis + 1; i++) {
                int tmp = s[i + dis - 1] - s[i - 1];
                if (ans == tmp) {
                    ch[i] = true;
                }
            }
            for (int i = n - dis + 2; i <= n; i++) {
                int tmp = s[n] - s[i - 1] + s[dis - (n - i + 1)];
                if (ans == tmp) {
                    ch[i] = true;
                }
            }
            //out.println(ans);
            int res = INF;
            for (int i = 1; i <= n; i++) {
                if (ch[i]) {
                    int temp = ss - i + 1;
                    if (temp <= 0) temp += n;
                    res = Math.min(res, temp);
                }
            }
            out.println(res);
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