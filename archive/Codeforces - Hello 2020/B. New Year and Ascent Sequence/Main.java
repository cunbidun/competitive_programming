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
        Task1284B solver = new Task1284B();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1284B {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            FTSum bit = new FTSum(1000005);
            int[] a = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                int k = in.nextInt();
                boolean d = false;
                int[] tmp = in.nextIntArray(k, 1);
                for (int j = 1; j <= k; j++) {
                    tmp[j] += 2;
                    if (j > 1 && tmp[j] > tmp[j - 1]) {
                        d = true;
                        break;
                    }
                }
                if (d) continue;
                bit.update(tmp[1], 1);
                a[i] = tmp[k];
            }
            long res = 0;
            for (int i = 1; i <= n; i++)
                if (a[i] != 0) {
                    res += bit.getSum(a[i]);
                }
            out.println((long) n * n - res);
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

    static class FTSum {
        private int n;
        private int[] sum;

        public FTSum(int n) {
            sum = new int[n + 1];
            this.n = n;
        }

        public void update(int pos, int val) {
            while (pos <= n) {
                sum[pos] += val;
                pos += pos & -pos;
            }
        }

        public int getSum(int pos) {
            int ans = 0;
            while (pos != 0) {
                ans += sum[pos];
                pos -= pos & -pos;
            }
            return ans;
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

        public void println(long i) {
            out.println(i);
        }

    }
}