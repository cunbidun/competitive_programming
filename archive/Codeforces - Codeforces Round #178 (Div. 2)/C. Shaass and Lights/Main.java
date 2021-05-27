import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.concurrent.ThreadLocalRandom;
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
        Task294C solver = new Task294C();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task294C {
        private static final int MOD = (int) 1e9 + 7;
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int m = in.nextInt();
            if (n == m) {
                out.println(1);
                return;
            }
            int[] a = in.nextIntArray(m, 1);
            QuickSort.sort(a, 1, m);
            int[] f = new int[1010];
            f[0] = 1;
            int pow = 0;
            for (int i = 1; i <= 1000; i++) f[i] = Op.mulMod(f[i - 1], i, MOD);
            int ans = f[n - m];
            if (a[1] != 1)
                ans = Op.mulMod(ans, Op.inv(f[a[1] - 1], MOD), MOD);

            for (int i = 2; i <= m; i++) {
                if (a[i] - a[i - 1] - 1 != 0) {
                    ans = Op.mulMod(ans, Op.inv(f[a[i] - a[i - 1] - 1], MOD), MOD);
                    pow += a[i] - a[i - 1] - 1 - 1;
                }
            }
            if (n != a[m])
                ans = Op.mulMod(ans, Op.inv(f[n - a[m]], MOD), MOD);
            out.println(Op.mulMod(ans, Op.powMod(2, pow, MOD), MOD));

        }

    }

    static class ArrayUtils {
        public static void shuffleArray(int[] array, int stIndex, int enIndex) {
            for (int i = enIndex; i > stIndex; i--) {
                int index = (int) OneNumberGen.genInt(stIndex, i - 1);
                if (index != i) {
                    array[index] ^= array[i];
                    array[i] ^= array[index];
                    array[index] ^= array[i];
                }
            }
        }

    }

    static class Op {
        public static int mulMod(int x, int y, int MOD) {
            return (int) (((long) x * y) % MOD);
        }

        public static int powMod(int x, long p, int MOD) {
            if (p == 0) return 1;
            int t = powMod(x, p / 2, MOD);
            if ((p & 1) == 1)
                return mulMod(mulMod(t, t, MOD), x, MOD);
            return mulMod(t, t, MOD);
        }

        public static int inv(int x, int MOD) {
            return powMod(x, MOD - 2, MOD);
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

    static class OneNumberGen {
        private static long genI(long min, long max) {
            return ThreadLocalRandom.current().nextLong(min, max + 1);
        }

        public static long genInt(long min, long max) {
            if (min >= 0)
                return (genI(min, max));
            else if (max >= 0) {
                double ratio = (double) Math.abs(min) / (Math.abs(min) + max);
                ratio *= 1000000000000000000D;
                double prob = (double) (OneNumberGen.genInt(1, 1000000000000000000L));
                if (Double.compare(ratio, prob) > 0) {
                    return -(genI(0, -min));
                } else {
                    return (genI(0, max));
                }
            } else
                return -(OneNumberGen.genI(-min, -max));
        }

    }

    static class QuickSort {
        public static void sort(int[] list, int lowIndex, int highIndex) {
            ArrayUtils.shuffleArray(list, lowIndex, highIndex);
            Arrays.sort(list, lowIndex, highIndex + 1);
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
}