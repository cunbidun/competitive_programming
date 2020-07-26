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
        CVasyaAndArray solver = new CVasyaAndArray();
        solver.solve(1, in, out);
        out.close();
    }

    static class CVasyaAndArray {
        private InputReader in;
        private PrintWriter out;
        private PrinterUtil printer;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            this.printer = new PrinterUtil(out);
            int n = in.nextInt();
            int m = in.nextInt();
            int[] a = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                a[i] = n - i + 1;
            }
            TripIII[] q = new TripIII[m + 1];
            for (int i = 1; i <= m; i++) {
                int t = in.nextInt();
                int l = in.nextInt();
                int r = in.nextInt();
                q[i] = new TripIII(l, r, t);
            }
            Arrays.sort(q, 1, m + 1);
//        printer.println(a, 1, n);

            for (int i = 1; i <= m; i++) {
                if (q[i].third == 1) {
                    int l = q[i].first;
                    int r = q[i].second;
                    for (int j = l + 1; j <= r; j++) {
                        a[j] = a[j - 1] + 1;
                    }
                }
            }
//        printer.println(a, 1, n);

            for (int i = 1; i <= m; i++) {
                int l = q[i].first;
                int r = q[i].second;
                if (q[i].third == 1) {
                    for (int j = l + 1; j <= r; j++) {
                        if (a[j] < a[j - 1]) {
                            out.println("NO");
                            return;
                        }
                    }
                } else {
                    boolean d = false;
                    for (int j = l + 1; j <= r; j++) {
                        if (a[j] < a[j - 1]) {
                            d = true;
                            break;
                        }
                    }
                    if (!d) {
                        out.println("NO");
                        return;
                    }
                }
            }
            out.println("YES");
            printer.println(a, 1, n);
        }

    }

    static class TripIII implements Comparable<TripIII> {
        public int first;
        public int second;
        public int third;

        public TripIII(int first, int second, int third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }

        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            TripIII trip = (TripIII) o;

            return first == trip.first && second == trip.second && third == trip.third;
        }

        public String toString() {
            return "(" + first + "," + second + "," + third + ")";
        }

        public int compareTo(TripIII o) {
            int value = Integer.compare(first, o.first);
            if (value != 0) {
                return value;
            }
            value = Integer.compare(second, o.second);
            if (value != 0) {
                return value;
            }
            return Integer.compare(third, o.third);
        }

    }

    static class PrinterUtil {
        private PrintWriter out;

        public PrinterUtil(PrintWriter out) {
            this.out = out;
        }

        public void print(int[] a, int start, int end) {
            for (int i = start; i <= end; i++) {
                out.print(a[i] + " ");
            }
        }

        public void println(int[] a, int start, int end) {
            print(a, start, end);
            out.println();
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