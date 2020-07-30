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
        CTreeDiameter solver = new CTreeDiameter();
        solver.solve(1, in, out);
        out.close();
    }

    static class CTreeDiameter {
        private InputReader in;
        private PrintWriter out;
        int n;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int t = in.nextInt();
            while (t-- > 0) {
                n = in.nextInt();
                int l = 2, r = n;
                boolean d = false;
                int Max = ask(2, n);
                while (l != r) {
                    if (l == r - 1) {
                        out.print(1 + " " + (n - 1) + " " + l + " ");
                        for (int i = 1; i <= n; i++)
                            if (i != l) {
                                out.print(i + " ");
                            }
                        out.println();
                        out.flush();
                        int ans1 = in.nextInt();
                        if (ans1 == -1) return;

                        out.print(1 + " " + (n - 1) + " " + r + " ");
                        for (int i = 1; i <= n; i++)
                            if (i != r) {
                                out.print(i + " ");
                            }
                        out.println();
                        out.flush();
                        int ans2 = in.nextInt();
                        if (ans2 == -1) return;

                        out.println("-1 " + MaxMin.Max(Max, ans1, ans2));
                        out.flush();
                        d = true;
                        break;
                    }
                    int m = (l + r) >> 1;
                    int ans = ask(l, m);
                    if (ans == -1)
                        return;
                    if (ans == Max) {
                        r = m;
                    } else {
                        l = m + 1;
                    }
                }
                if (d) continue;

                out.print(1 + " " + (n - 1) + " " + l + " ");
                for (int i = 1; i <= n; i++)
                    if (i != l) {
                        out.print(i + " ");
                    }
                out.println();
                out.flush();
                int ans = in.nextInt();
                if (ans == -1) return;
                out.println("-1" + " " + MaxMin.Max(ans, Max));
                out.flush();
            }
        }

        private int ask(int l, int r) {
            out.print(1 + " " + (r - l + 1) + " " + 1 + " ");
            for (int i = l; i <= r; i++) {
                out.print(i + " ");
            }
            out.println();
            out.flush();
            return in.nextInt();
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

    static class MaxMin {
        public static <T extends Comparable<T>> T Max(T x, T y) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            return max;
        }

        public static <T extends Comparable<T>> T Max(T x, T y, T z) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            if (z.compareTo(max) > 0) max = z;
            return max;
        }

    }
}