import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.TreeSet;
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
        DTrickyFunction solver = new DTrickyFunction();
        solver.solve(1, in, out);
        out.close();
    }

    static class DTrickyFunction {
        private InputReader in;
        private PrintWriter out;
        private PrinterUtils printer;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            this.printer = new PrinterUtils(out);
            int n = in.nextInt();
            int[] a = in.nextIntArray(n, 1);
            int[] sum = new int[n + 1];
            Point[] p = new Point[n];
            for (int i = 1; i <= n; i++) {
                sum[i] = sum[i - 1] + a[i];
                p[i - 1] = new Point(i, sum[i], i);
            }
            WrapperTriple<Integer, Integer, Double> ans = GeometryUtils.closestPair(p);
            int p1 = ans.first;
            int p2 = ans.second;
            if (p1 > p2) {
                int tmp = p1;
                p1 = p2;
                p2 = tmp;
            }
            out.println((long) (p1 - p2) * (p1 - p2) + (long) (sum[p1] - sum[p2]) * (sum[p1] - sum[p2]));
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

        public int[] nextIntArray(int length, int stIndex) {
            int[] arr = new int[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextInt();
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class Point implements Comparable<Point> {
        public double x;
        public double y;
        public int idx;

        public Point(double x, double y) {
            this.x = x;
            this.y = y;
        }

        public Point(double x, double y, int idx) {
            this.x = x;
            this.y = y;
            this.idx = idx;
        }

        public int compareTo(Point other) {
            return Double.compare(x, other.x) == 0 ? (int) Math.signum(y - other.y) : (int) Math.signum(x - other.x);
        }

        public String toString() {
            return "(" + x + "," + y + ")";
        }

    }

    static class PrinterUtils {
        private PrintWriter out;

        public PrinterUtils(PrintWriter out) {
            this.out = out;
        }

    }

    static class GeometryUtils {
        public static double distance(Point a, Point b) {
            return Math.hypot(a.x - b.x, a.y - b.y);
        }

        public static WrapperTriple<Integer, Integer, Double> closestPair(Point[] points) {
            Arrays.sort(points);
            double min = 1e9;
            int p1 = -1, p2 = -1;
            int left = 0;

            TreeSet<Point> set = new TreeSet<>((a, b) -> (int) (Math.signum(Double.compare(a.y, b.y) == 0 ? a.x - b.x : a.y - b.y)));

            for (Point p : points) {
                while (Double.compare(p.x - points[left].x, min) > 0)
                    set.remove(points[left++]);
                for (Point next : set.subSet(new Point(p.x, (int) (p.y - min), 0), new Point(p.x, (int) (p.y + min), 0))) {
                    double temp = distance(p, next);
                    if (Double.compare(temp, min) < 0) {
                        min = temp;
                        p1 = p.idx;
                        p2 = next.idx;
                    }
                }
                set.add(p);
            }
            return new WrapperTriple<>(p1, p2, min);
        }

    }

    static class WrapperTriple<U, V, W> {
        public U first;
        public V second;
        public W third;

        public WrapperTriple(U first, V second, W third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }

        public String toString() {
            return "(" + first + "," + second + "," + third + ")";
        }

    }
}