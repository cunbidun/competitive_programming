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
        Task1293D solver = new Task1293D();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1293D {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            long x0 = in.nextLong();
            long y0 = in.nextLong();
            long ax = in.nextLong();
            long ay = in.nextLong();
            long bx = in.nextLong();
            long by = in.nextLong();
            long xs = in.nextLong();
            long ys = in.nextLong();
            long t = in.nextLong();

            ArrayList<PairLL> l = new ArrayList<>();
            l.add(new PairLL(x0, y0));
            while (ax * x0 + bx <= 3e16 && ay * y0 + by <= 3e16) {
                x0 = ax * x0 + bx;
                y0 = ay * y0 + by;
                l.add(new PairLL(x0, y0));
            }

            long[][] dis = new long[100][100];
            for (int i = 0; i < l.size(); i++) {
                for (int j = 0; j < l.size(); j++) {
                    dis[i][j] = Math.abs(l.get(j).first - l.get(i).first) + Math.abs(l.get(j).second - l.get(i).second);
                }
            }

            int ans = 0;
            for (int i = 0; i < l.size(); i++) {
                int res1 = 0, res2 = 0;
                long cur = Math.abs(xs - l.get(i).first) + Math.abs(ys - l.get(i).second);
                int j = i;
                while (j < l.size() && cur + dis[i][j++] <= t)
                    res1++;

                j = i;
                while (j >= 0 && cur + dis[i][j--] <= t)
                    res2++;

                ans = MaxMin.Max(ans, res1, res2);
            }

            out.println(ans);
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

        public long nextLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
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
        public static <T extends Comparable<T>> T Max(T x, T y, T z) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            if (z.compareTo(max) > 0) max = z;
            return max;
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

    static class PairLL implements Comparable<PairLL> {
        public long first;
        public long second;

        public PairLL(long first, long second) {
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

            PairLL pair = (PairLL) o;

            return first == pair.first && second == pair.second;
        }

        public String toString() {
            return "(" + first + "," + second + ")";
        }

        public int compareTo(PairLL o) {
            int value = Long.compare(first, o.first);
            if (value != 0) {
                return value;
            }
            return Long.compare(second, o.second);
        }

    }
}