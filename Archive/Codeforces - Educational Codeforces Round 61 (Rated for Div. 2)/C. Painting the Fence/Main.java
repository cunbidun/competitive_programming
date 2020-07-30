import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author cunbidun
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CPaintingTheFence solver = new CPaintingTheFence();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPaintingTheFence {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] cnt1 = new int[n + 1];
            int[] cnt2 = new int[n + 1];
            int[] a = new int[n + 1];
            int m = in.nextInt();
            int[] l = new int[m + 1];
            int[] r = new int[m + 1];

            for (int i = 1; i <= m; i++) {
                l[i] = in.nextInt();
                r[i] = in.nextInt();
                for (int j = l[i]; j <= r[i]; j++) {
                    a[j]++;
                }
            }
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] != 0) ans++;
                cnt1[i] = cnt1[i - 1];
                cnt2[i] = cnt2[i - 1];
                if (a[i] == 1) cnt1[i]++;
                if (a[i] == 2) cnt2[i]++;
            }
            int res = 0;
            for (int i = 1; i < m; i++) {
                for (int j = i + 1; j <= m; j++) {
                    if (i != j) {
                        if (l[j] > r[i] || l[i] > r[j]) {
                            int cnt = cnt1[r[i]] - cnt1[l[i] - 1] + cnt1[r[j]] - cnt1[l[j] - 1];
                            res = MaxMin.Max(res, ans - cnt);
                            continue;
                        }
                        if (r[j] >= r[i] && l[i] >= l[j]) {
                            int cnt = cnt1[r[j]] - cnt1[r[i]];
                            cnt += cnt1[l[i] - 1] - cnt1[l[j] - 1];
                            cnt += cnt2[r[i]] - cnt2[l[i] - 1];
                            res = MaxMin.Max(res, ans - cnt);

                            continue;
                        }
                        if (r[j] <= r[i] && l[i] <= l[j]) {
                            int cnt = cnt1[r[i]] - cnt1[r[j]];
                            cnt += cnt1[l[j] - 1] - cnt1[l[i] - 1];
                            cnt += cnt2[r[j]] - cnt2[l[j] - 1];
                            res = MaxMin.Max(res, ans - cnt);
                            continue;
                        }
                        if (r[j] >= r[i]) {
                            int cnt = cnt1[r[j]] - cnt1[r[i]];
                            cnt += cnt1[l[j] - 1] - cnt1[l[i] - 1];
                            cnt += cnt2[r[i]] - cnt2[l[j] - 1];
                            res = MaxMin.Max(res, ans - cnt);
                            continue;
                        }
                        if (r[j] <= r[i]) {
                            int cnt = cnt1[r[i]] - cnt1[r[j]];
                            cnt += cnt1[l[i] - 1] - cnt1[l[j] - 1];
                            cnt += cnt2[r[j]] - cnt2[l[i] - 1];
                            res = MaxMin.Max(res, ans - cnt);
                        }
                    }
                }
            }
            out.println(res);
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Max(T x, T y) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            return max;
        }

    }

    static class InputReader extends InputStream {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}