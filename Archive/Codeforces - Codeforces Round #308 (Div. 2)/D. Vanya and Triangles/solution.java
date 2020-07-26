import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.TreeSet;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        OutputWriter out = new OutputWriter(outputStream);
        Task552D solver = new Task552D();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task552D {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int[] x = new int[n + 1];
            int[] y = new int[n + 1];
            int[] h = new int[201];
            int[] v = new int[201];
            boolean[][] mark = new boolean[301][301];
            for (int i = 1; i <= n; i++) {
                x[i] = in.nextInt();
                y[i] = in.nextInt();
                v[x[i] + 100]++;
                h[y[i] + 100]++;
                mark[x[i] + 150][y[i] + 150] = true;
            }
            TreeSet<QuarIIII> check = new TreeSet<>();
            int[][] gcd = new int[201][201];
            for (int i = 0; i <= 200; i++)
                for (int j = 0; j <= 200; j++) gcd[i][j] = MathAlgorithm.gcd(i, j);

            long ans = cal(n);
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    int disX = Math.abs(x[i] - x[j]);
                    int disY = Math.abs(y[i] - y[j]);
                    if (disX == 0 || disY == 0) continue;
                    disY /= gcd[Math.abs(x[i] - x[j])][Math.abs(y[i] - y[j])];
                    disX /= gcd[Math.abs(x[i] - x[j])][Math.abs(y[i] - y[j])];


                    int curX = x[i];
                    int curY = y[i];
                    int cnt = 1;


                    QuarIIII ch = new QuarIIII(0, 0, 0, 0);

                    if ((y[i] - y[j]) * (x[i] - x[j]) > 0) {
                        int step = MaxMin.Min((100 - x[i]) / disX + 1, (100 - y[i]) / disY + 1);
                        ch.first = curX + step * disX;
                        ch.second = curY + step * disY;

                        step = MaxMin.Min((100 + x[i]) / disX + 1, (100 + y[i]) / disY + 1);
                        ch.third = curX - step * disX;
                        ch.fourth = curY - step * disY;

                        if (check.contains(ch)) continue;
                        while (true) {
                            curX += disX;
                            curY += disY;
                            if (!(in(curX) && in(curY))) break;
                            if (mark[curX + 150][curY + 150]) cnt++;
                        }

                        curX = x[i];
                        curY = y[i];
                        while (true) {
                            curX -= disX;
                            curY -= disY;
                            if (!(in(curX) && in(curY))) break;
                            if (mark[curX + 150][curY + 150]) cnt++;
                        }
                        check.add(ch);

                    } else {
                        int step = MaxMin.Min((100 - x[i]) / disX + 1, (100 + y[i]) / disY + 1);
                        ch.first = curX + step * disX;
                        ch.second = curY - step * disY;

                        step = MaxMin.Min((100 + x[i]) / disX + 1, (100 - y[i]) / disY + 1);
                        ch.third = curX - step * disX;
                        ch.fourth = curY + step * disY;

                        if (check.contains(ch)) continue;
                        while (true) {
                            curX += disX;
                            curY -= disY;
                            if (!(in(curX) && in(curY))) break;
                            if (mark[curX + 150][curY + 150]) cnt++;
                        }
                        curX = x[i];
                        curY = y[i];
                        while (true) {
                            curX -= disX;
                            curY += disY;
                            if (!(in(curX) && in(curY))) break;
                            if (mark[curX + 150][curY + 150]) cnt++;
                        }
                        check.add(ch);
                    }
                    if (cnt > 2)
                        ans -= cal(cnt);
                }

            }
            for (int i = 0; i <= 200; i++) ans -= (cal(h[i]) + cal(v[i]));
            out.println(ans);
        }

        private boolean in(int i) {
            return -100 <= i && i <= 100;
        }

        private long cal(int i) {
            long tmp = (long) i * (i - 1) * (i - 2);
            return tmp / 6;
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
        }

    }

    static class InputReader extends InputStream {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
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

    static class QuarIIII implements Comparable<QuarIIII> {
        public int first;
        public int second;
        public int third;
        public int fourth;

        public QuarIIII(int first, int second, int third, int fourth) {
            this.first = first;
            this.second = second;
            this.third = third;
            this.fourth = fourth;
        }

        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            QuarIIII quar = (QuarIIII) o;

            return first == quar.first && second == quar.second && third == quar.third && fourth == quar.fourth;
        }

        public String toString() {
            return "(" + first + "," + second + "," + third + "," + fourth + ")";
        }

        public int compareTo(QuarIIII o) {
            int value = Integer.compare(first, o.first);
            if (value != 0) {
                return value;
            }
            value = Integer.compare(second, o.second);
            if (value != 0) {
                return value;
            }
            value = Integer.compare(third, o.third);
            if (value != 0) {
                return value;
            }
            return Integer.compare(fourth, o.fourth);
        }

    }

    static class OutputWriter {
        private final PrintWriter out;

        public OutputWriter(OutputStream outputStream) {
            out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.out = new PrintWriter(writer);
        }

        public void close() {
            out.close();
        }

        public void println(long i) {
            out.println(i);
        }

    }

    static class MathAlgorithm {
        public static int gcd(int a, int b) {
            if (b == 0)
                return a;
            return gcd(b, a % b);
        }

    }
}