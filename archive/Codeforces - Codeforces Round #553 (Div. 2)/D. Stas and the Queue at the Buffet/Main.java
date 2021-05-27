import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Comparator;
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
        DStasAndTheQueueAtTheBuffet solver = new DStasAndTheQueueAtTheBuffet();
        solver.solve(1, in, out);
        out.close();
    }

    static class DStasAndTheQueueAtTheBuffet {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            PairII[] a = new PairII[n + 1];
            PairII[] b = new PairII[n + 1];
            boolean[] used = new boolean[n + 1];
            long ans = 0;
            for (int i = 1; i <= n; i++) {
                a[i] = new PairII(in.nextInt(), in.nextInt());
            }
            Arrays.sort(a, 1, n + 1, Comparator.comparingInt(o -> Math.abs(o.first - o.second)));

            int posL = 1;
            int posR = n;
            int cnt = 0;
            long res = 0;
            for (int i = n; i >= 1; i--) {
                long tmp1 = (long) (posL - 1) * a[i].first + (long) (n - posL) * a[i].second;
                long tmp2 = (long) (posR - 1) * a[i].first + (long) (n - posR) * a[i].second;
                if (a[i].first > a[i].second) {
                    ans += tmp1;
                    posL++;
                } else {
                    ans += tmp2;
                    posR--;
                }
            }
            out.println(ans + res);
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
}