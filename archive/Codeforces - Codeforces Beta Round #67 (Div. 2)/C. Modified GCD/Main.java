import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Collections;
import java.util.ArrayList;
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
        CModifiedGCD solver = new CModifiedGCD();
        solver.solve(1, in, out);
        out.close();
    }

    static class CModifiedGCD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();
            int d = MathAlgorithm.gcd(a, b);
            ArrayList<Integer> list = new ArrayList<>();
            list.add(1);
            list.add(d);
            for (int i = 2; i <= Math.sqrt(d); i++) {
                if (d % i == 0) {
                    list.add(i);
                    if (i != d / i) list.add(d / i);
                }
            }
            Collections.sort(list);
            while (n-- > 0) {
                int l = in.nextInt();
                int r = in.nextInt();
                int posR = BinarySearch.upperBound(list, 0, list.size() - 1, r);
                int posL = BinarySearch.lowerBound(list, 0, list.size() - 1, l);
                if (posR == 0 || posL == list.size()) {
                    out.println(-1);
                    continue;
                }
                posR--;
                if (list.get(posR) < l) {
                    out.println(-1);
                    continue;
                }
                out.println(list.get(posR));
            }
        }

    }

    static class MathAlgorithm {
        public static int gcd(int a, int b) {
            if (b == 0)
                return a;
            return gcd(b, a % b);
        }

    }

    static class BinarySearch {
        public static int lowerBound(ArrayList<Integer> array, int indexSt, int indexEn, long value) {
            if (value > array.get(indexEn)) return indexEn + 1;
            int low = indexSt;
            int high = indexEn;
            while (low < high) {
                final int mid = (low + high) / 2;
                if (value <= array.get(mid)) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            return low;
        }

        public static int upperBound(ArrayList<Integer> array, int indexSt, int indexEn, long value) {
            if (value >= array.get(indexEn)) return indexEn + 1;
            int low = indexSt;
            int high = indexEn;
            while (low < high) {
                final int mid = (low + high) / 2;
                if (value >= array.get(mid)) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            return low;
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