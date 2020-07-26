import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.TreeMap;
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
        DZeroQuantityMaximization solver = new DZeroQuantityMaximization();
        solver.solve(1, in, out);
        out.close();
    }

    static class DZeroQuantityMaximization {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.nextIntArray(n, 1);
            int[] b = in.nextIntArray(n, 1);
            TreeMap<PairII, Integer> cnt = new TreeMap<>();
            int ans = 0;
            int free = 0;
            int cnt0 = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] == 0 && b[i] != 0) continue;
                if (a[i] == 0 && b[i] == 0) {
                    free++;
                    continue;
                }
                if (a[i] != 0 && b[i] == 0) {
                    cnt0++;
                    continue;
                }
                int tmp = (MathAlgorithm.gcd(Math.abs(a[i]), Math.abs(b[i])));
                int tmpA = a[i] / tmp;
                int tmpB = -b[i] / tmp;
                if (tmpA < 0) {
                    tmpA = -tmpA;
                    tmpB = -tmpB;
                }
                Integer temp = cnt.get(new PairII(tmpA, tmpB));
                if (temp == null) {
                    cnt.put(new PairII(tmpA, tmpB), 1);
                    temp = 1;
                } else {
                    temp++;
                    cnt.put(new PairII(tmpA, tmpB), cnt.get(new PairII(tmpA, tmpB)) + 1);
                }
                ans = MaxMin.Max(ans, temp);
            }
            out.println(free + (MaxMin.Max(ans, cnt0)));
        }

    }

    static class MathAlgorithm {
        public static int gcd(int a, int b) {
            if (b == 0)
                return a;
            return gcd(b, a % b);
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

    static class MaxMin {
        public static <T extends Comparable<T>> T Max(T x, T y) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            return max;
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