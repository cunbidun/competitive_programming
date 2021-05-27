import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        DExtraElement solver = new DExtraElement();
        solver.solve(1, in, out);
        out.close();
    }

    static class DExtraElement {
        private InputReader in;
        private PrintWriter out;
        private PrinterUtil printer;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            this.printer = new PrinterUtil(out);

            int n = in.nextInt();
            if (n <= 3) {
                out.println(1);
                return;
            }
            PairII[] a = new PairII[n + 1];
            for (int i = 1; i <= n; i++) {
                a[i] = new PairII(in.nextInt(), i);
            }
            Arrays.sort(a, 1, n + 1);
            int tmp = a[3].first - a[2].first;
            boolean f = false;
            for (int i = 3; i < n; i++) {
                if (a[i + 1].first != a[i].first + tmp) {
                    f = true;
                    break;
                }
            }
            if (!f) {
                out.println(a[1].second);
                return;
            }

            tmp = a[2].first - a[1].first;
            f = false;
            for (int i = 1; i < n - 1; i++) {
                if (a[i + 1].first != a[i].first + tmp) {
                    f = true;
                    break;
                }
            }
            if (!f) {
                out.println(a[n].second);
                return;
            }
            tmp = (a[n].first - a[1].first) / (n - 2);
            f = false;
            int pos = -1;
            for (int i = 1; i < n; i++) {
                if (a[i + 1].first != a[i].first + tmp) {
                    if (pos == -1 && a[i].first + tmp == a[i + 2].first) {
                        pos = i + 1;
                    } else {
                        f = true;
                        break;
                    }
                    i++;
                }
            }
            if (!f) {
                out.println(a[pos].second);
                return;
            }

            out.println(-1);

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

    static class PrinterUtil {
        private PrintWriter out;

        public PrinterUtil(PrintWriter out) {
            this.out = out;
        }

    }
}