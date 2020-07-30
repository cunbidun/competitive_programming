import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Collections;
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
        Task1287C solver = new Task1287C();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1287C {
        private InputReader in;
        private OutputWriter out;
        int n;
        private int odd;
        private int even;
        int[] a;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            n = in.nextInt();
            a = new int[n + 2];
            for (int i = 1; i <= n; i++) a[i] = in.nextInt();
            odd = (n + 1) / 2;
            even = n - odd;
            for (int i = 1; i <= n; i++) {
                if (a[i] != 0) {
                    if (a[i] % 2 == 1) odd--;
                    else even--;
                }
            }
            int ans = 1000;
            a[0] = 1;
            a[n + 1] = 1;
            ans = MaxMin.Min(ans, sol());

            a[0] = 2;
            a[n + 1] = 1;
            ans = MaxMin.Min(ans, sol());

            a[0] = 1;
            a[n + 1] = 2;
            ans = MaxMin.Min(ans, sol());

            a[0] = 2;
            a[n + 1] = 2;
            ans = MaxMin.Min(ans, sol());

            out.println(ans);
        }

        int sol() {
            int res = 0;
            int curO = odd;
            int curE = even;
            ArrayList<PairII> l2 = new ArrayList<>();
            int l1 = 0;

            int i = 0;
            for (int j = 1; j <= n + 1; j++) {
                while (j <= n + 1) {
                    if (a[j] != 0) break;
                    j++;
                }
                if ((a[i] + a[j]) % 2 != 0) {
                    l1++;
                } else {
                    l2.add(new PairII(j - i - 1, a[i] % 2));
                }
                i = j;
            }

            Collections.sort(l2);
//        out.println(l2);
//        out.println(l1);

            for (PairII p : l2) {
                if (p.second % 2 == 1) {
                    if (p.first <= curO) {
                        curO -= p.first;
                    } else res += 2;
                } else {
                    if (p.first <= curE) {
                        curE -= p.first;
                    } else res += 2;
                }
            }
//        out.println(a[0] + " " + a[n + 1] + " " + (res + l1));

//        out.println(l1);
//        out.println(l2);
            return res + l1;
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

        public void println(int i) {
            out.println(i);
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

    static class PairII implements Comparable<PairII> {
        public int first;
        public int second;

        public PairII(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            PairII pair = (PairII) o;

            return first == pair.first && second == pair.second;
        }

        public String toString() {
            return "(" + first + "," + second + ")";
        }

        public int compareTo(PairII o) {
            int value = Integer.compare(first, o.first);
            if (value != 0) {
                return value;
            }
            return Integer.compare(second, o.second);
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
        }

    }
}