import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;

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
        ETheFairNutAndRectangles solver = new ETheFairNutAndRectangles();
        solver.solve(1, in, out);
        out.close();
    }

    static class ETheFairNutAndRectangles {
        private InputReader in;
        private PrintWriter out;
        private PrinterUtils printer;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            this.printer = new PrinterUtils(out);
            int n = in.nextInt();
            Triple<Integer, Integer, Long>[] a = new Triple[n + 1];
            for (int i = 1; i <= n; i++) {
                a[i] = new Triple<>(in.nextInt(), in.nextInt(), in.nextLong());
            }
            Arrays.sort(a, 1, n + 1);
            ConvexHullOptimization ch = new ConvexHullOptimization(false, false);
            ch.add(0, 0);
            long ans = 0;

            for (int i = 1; i <= n; i++) {
                long f = (long) a[i].first * (long) a[i].second - a[i].third + ch.get(a[i].second);
                ch.add(-a[i].first, f);
                ans = MaxMin.Max(f, ans);
            }
            out.println(ans);
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
        public static <T extends Comparable<T>> T Max(T x, T y) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            return max;
        }

    }

    static class PrinterUtils {
        private PrintWriter out;

        public PrinterUtils(PrintWriter out) {
            this.out = out;
        }

    }

    static class ConvexHullOptimization {
        private ArrayList<Long> A;
        private ArrayList<Long> B;
        private boolean increasingSlope;
        private boolean needTenary;
        private int curIt;

        private boolean bad(int l1, int l2, int l3) {
            if (increasingSlope)
                return (B.get(l3) - B.get(l1)) * (A.get(l1) - A.get(l2)) < (A.get(l1) - A.get(l3)) * (B.get(l2) - B.get(l1));
            return Double.compare((double) (B.get(l3) - B.get(l1)) * (A.get(l1) - A.get(l2)),
                    (double) (A.get(l1) - A.get(l3)) * (B.get(l2) - B.get(l1))) >= 0;
        }

        public ConvexHullOptimization(boolean increasingSlope, boolean needTenary) {
            this.increasingSlope = increasingSlope;
            this.needTenary = needTenary;
            A = new ArrayList<>();
            B = new ArrayList<>();
            curIt = 0;
        }

        public void add(long x, long y) {
            if (!A.isEmpty()) {
                if (A.get(A.size() - 1) == x && B.get(B.size() - 1) <= y) {// change to ">=" if you want to find min
                    A.remove(A.size() - 1);
                    B.remove(B.size() - 1);
                    curIt--;
                }
            }
            A.add(x);
            B.add(y);
            while (A.size() > 2 && bad(A.size() - 3, A.size() - 2, A.size() - 1)) {
                A.remove(A.size() - 2);
                B.remove(B.size() - 2);
                curIt--;
            }
        }

        public long get(long x) {
            if (!needTenary) {
                if (curIt < 0) curIt = 0;
                while (curIt < A.size() - 1 && A.get(curIt) * x + B.get(curIt) <= A.get(curIt + 1) * x + B.get(curIt + 1))
                    curIt++;
                // change to ">=" if you want to find min
                return A.get(curIt) * x + B.get(curIt);
            }
            int l = 0, r = A.size() - 1;
            while (r - l > 2) {
                int mid1 = (l * 2 + r) / 3;
                int mid2 = (l + 2 * r) / 3;
                long val1 = A.get(mid1) * x + B.get(mid1);
                long val2 = A.get(mid2) * x + B.get(mid2);
                if (val1 == val2) {
                    l = mid1;
                    r = mid2;
                } else if (val1 < val2) l = mid1; // change to ">" if you want to find min
                else r = mid2;
            }
            long ret = (long) -1e18; // change to "1e18" if you want to find min
            for (int i = l; i <= r; i++)
                ret = MaxMin.Max(ret, A.get(i) * x + B.get(i)); // change to "min" if you want to find min
            return ret;
        }

    }

    static class Triple<U extends Comparable<U>, V extends Comparable<V>, W extends Comparable<W>> implements Comparable<Triple<U, V, W>> {
        public U first;
        public V second;
        public W third;

        public Triple(U first, V second, W third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }

        public String toString() {
            return "(" + first + "," + second + "," + third + ")";
        }

        public int compareTo(Triple<U, V, W> o) {
            if (first.compareTo(o.first) != 0) return first.compareTo(o.first);
            if (second.compareTo(o.second) != 0) return second.compareTo(o.second);
            else return third.compareTo(o.third);
        }

    }
}