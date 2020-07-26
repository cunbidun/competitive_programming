import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        OutputWriter out = new OutputWriter(outputStream);
        Task676C solver = new Task676C();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task676C {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int k = in.nextInt();
            char[] s = StringUtils.toCharArray(in.nextString(), 1);
            int ans = 0;

            int[] cnt = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                cnt[i] = cnt[i - 1];
                if (s[i] == 'b') cnt[i]++;
            }
            for (int i = 1; i <= n; i++) {
                int dis = BinarySearch.upperBound(cnt, 1, n, cnt[i - 1] + k) - 1 - i + 1;
//            out.println(i + " " + dis);
                ans = MaxMin.Max(ans, dis);
            }
            cnt = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                cnt[i] = cnt[i - 1];
                if (s[i] == 'a') cnt[i]++;
            }
            for (int i = 1; i <= n; i++) {
                int dis = BinarySearch.upperBound(cnt, 1, n, cnt[i - 1] + k) - 1 - i + 1;
//            out.println(i + " " + dis);
                ans = MaxMin.Max(ans, dis);
            }

            out.print(ans);
        }

    }

    static class BinarySearch {
        public static int upperBound(int[] array, int indexSt, int indexEn, int value) {
            if (value >= array[indexEn]) return indexEn + 1;
            int low = indexSt;
            int high = indexEn;
            while (low < high) {
                final int mid = (low + high) / 2;
                if (value >= array[mid]) {
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

        public String nextString() {
            int c;
            while (isSpaceChar(c = read())) ;
            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);
            while (!isSpaceChar(c = read()))
                result.appendCodePoint(c);
            return result.toString();
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class StringUtils {
        public static char[] toCharArray(String s, int stIndex) {
            char[] result = new char[s.length() + stIndex];
            for (int i = 0; i < s.length(); i++) {
                result[i + stIndex] = s.charAt(i);
            }
            return result;
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Max(T x, T y) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
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

        public void print(int i) {
            out.print(i);
        }

    }
}